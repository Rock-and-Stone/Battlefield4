#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

HRESULT Enemy::init()
{
	AstarInit();
	return S_OK;
}

HRESULT Enemy::init(const char* imageName, POINT position)
{
	_image = IMAGEMANAGER->findImage(imageName);

	_posX = position.x;
	_posY = position.y;
	_idX = _posX / TILEWIDTH;
	_idY = _posY / TILEHEIGHT;
	_enemyDirection = DOWN;

	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{
	_idX = _posX / TILEWIDTH;
	_idY = _posY / TILEHEIGHT;
}

void Enemy::render()
{
	Draw();
}

void Enemy::AstarInit()
{
	//��� �ʱ�ȭ
	_startNode = NULL;
	_endNode = NULL;
	_curNode = NULL;

	//��ü��� �ʱ�ȭ
	for (int y = 0; y < TILEY; y++)
	{
		for (int x = 0; x < TILEX; x++)
		{
			//���ο� ���� ��Ʈ��ġ ����
			_totalNode[x][y] = new node(x, y);
			_totalNode[x][y]->rc = RectMake(x * 32, y * 32, 32, 32);
		}
	}

	//ùŬ���� ¦���� �ǰ� �ϱ� ���ؼ� -1�� �ʱ�ȭ
	_count = -1;
	//�� ã�ҳ�?
	_isFind = false;

	//����ŸƮ��
	_openList.clear();
	_closeList.clear();
	_finalList.clear();
}

void Enemy::StartSearchPlayer(int playerIdX, int playerIdY)
{
	if (_startNode && _endNode) return;

	_totalNode[_idY][_idX]->nodeState = NODE_START;
	_startNode = _totalNode[_idY][_idX];
	cout << "setStartNode" << endl;

	_totalNode[playerIdY][playerIdX]->nodeState = NODE_END;
	_endNode = _totalNode[playerIdY][playerIdX];
	cout << "setEndNode" << endl;
}

void Enemy::SearchPlayer(int playerIdX, int playerIdY)
{
	_openList.clear();
	_closeList.clear();
	_finalList.clear();

	_totalNode[_idY][_idX]->nodeState = NODE_START;
	_startNode = _totalNode[_idY][_idX];

	_totalNode[playerIdY][playerIdX]->nodeState = NODE_END;
	_endNode = _totalNode[playerIdY][playerIdX];
}

void Enemy::pathFinding()
{
	_openList.clear();
	_closeList.clear();
	_finalList.clear();

	//�����尡 ���� ��� ��ã�� ����
	if (!_endNode) return;
	cout << "startFind" << endl;

	_openList.push_back(_startNode);

	while (_openList.size() > 0)
	{
		_curNode = _openList[0];

		for (int i = 1; i < _openList.size(); i++)
		{
			if (_openList[i]->F <= _curNode->F && _openList[i]->H < _curNode->H)
			{
				_curNode = _openList[i];
			}
		}

		//Ŭ���� ����Ʈ�� �־�д�
		for (int i = 0; i < _openList.size(); i++)
		{
			if (_curNode == _openList[i])
			{
				this->delOpenList(i);
				_closeList.push_back(_curNode);
			}
		}

		//�����尡 ������ ���� ����? (��ã�Ҵ�)
		if (_curNode == _endNode)
		{
			node* endNode = _endNode;
			vector<node*> tempNode;
			//������ ���κ��� ���۳����� �θ��带 ���Ϳ� ��´�
			while (endNode != _startNode)
			{
				tempNode.push_back(endNode);
				endNode = endNode->parentNode;
			}

			for (int i = tempNode.size() - 1; i > 0; i--)
			{
				_finalList.push_back(tempNode[i]);
			}

			_isFind = true;
			_isMove = true;
			//�����ϰ� ���� ���´�
			return;
		}

		//�����¿� (������ ������� - ��¥�� �ֺ� 4���� ��带 ��� ���¸���Ʈ�� ��Ƽ� �˻��� ������)
		addOpenList(_curNode->idX, _curNode->idY - 1);	//��
		addOpenList(_curNode->idX, _curNode->idY + 1);	//��
		addOpenList(_curNode->idX - 1, _curNode->idY);	//��
		addOpenList(_curNode->idX + 1, _curNode->idY);	//��

		//���Ŀ� �밢 4���⵵ �߰��ϸ� �밢�� �̵� ó���� ������
		//���, �»�, ����, ����
		//����ó���� �����ָ� �ȴ�
		//�����̷� ���� �ȵǵ��� ó���Ѵ�
	}
}

void Enemy::addOpenList(int idx, int idy)
{
	//����ó�� �ε��� �����ȿ��� �߰��� �� �־�� �Ѵ�
	if (idx < 0 || idx >= TILEX || idy < 0 || idy >= TILEX) return;

	//���� ���¸���Ʈ�� ���� �� ����
	if (_totalNode[idx][idy]->nodeState == NODE_WALL) return;

	//Ŭ�����Ʈ(�����±�)�� �ִٸ� ���¸���Ʈ�� ������ �ȵȴ�
	for (int i = 0; i < _closeList.size(); i++)
	{
		if (_totalNode[idx][idy] == _closeList[i]) return;
	}

	//������� ������ ������ ������ ���� ���¸���Ʈ�� �߰��� ����
	//�������� 4���� ��带 �̿������ �ϰ� ����10, �밢�� 14����� �߰��Ѵ�
	node* neighborNode = _totalNode[idx][idy];
	int moveCost = _curNode->G + ((_curNode->idX - idx == 0 || _curNode->idY - idy == 0) ? 10 : 14);

	//���¸���Ʈ�ȿ� �̿���尡 ������ �ȵȴ�
	for (int i = 0; i < _openList.size(); i++)
	{
		if (_openList[i] == neighborNode) return;
	}

	//���������� ���¸���Ʈ���� ���°��
	//G, H, ParentNode ������ ���¸���Ʈ�� �߰�
	//F = G + H
	//G = ���ۿ��� ����
	//H = ���翡�� ����
	neighborNode->G = moveCost;
	neighborNode->H = (abs(neighborNode->idX - _endNode->idX) + abs(neighborNode->idY - _endNode->idY)) * 10;
	neighborNode->F = neighborNode->G + neighborNode->H;
	neighborNode->parentNode = _curNode;
	_openList.push_back(neighborNode);
}

void Enemy::delOpenList(int index)
{
	_openList.erase(_openList.begin() + index);
}

void Enemy::setNodeColor(node* node, COLORREF color)
{
	/*HBRUSH brush = CreateSolidBrush(color);
	FillRect(getMemDC(), &node->rc, brush);
	DeleteObject(brush);
	FrameRect(getMemDC(), node->rc, RGB(0, 0, 0));*/
}

void Enemy::Move()
{
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_enemyDirection = DOWN;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_enemyDirection = RIGHT;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_enemyDirection = UP;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_enemyDirection = LEFT;
	}
}

void Enemy::Draw()
{
	if (_isFind)
	{
		for (int i = 0; i < _finalList.size(); i++)
		{
			setNodeColor(_finalList[i], RGB(255, 255, 0));
		}
	}

#pragma region Frame
	_frameCount++;
	_image->setFrameX(_frameX);
	_image->setFrameY(_frameY);

	switch (_enemyDirection)
	{
	case DOWN:
		_frameY = 0;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case RIGHT:
		_frameY = 1;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case UP:
		_frameY = 2;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case LEFT:
		_frameY = 3;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	}
#pragma endregion

	_image->frameRender(getMemDC(), _posX, _posY, _frameX, _frameY);
}

void Enemy::Collision()
{
}
