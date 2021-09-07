#include "pch.h"
#include "marnie.h"
#include "CameraManager.h"

marnie::marnie()
{
}

marnie::~marnie()
{
}

HRESULT marnie::init(int indX, int indY)
{

	_x = indX * TILESIZE + (TILESIZE / 2),
	_y = indY * TILESIZE + (TILESIZE / 2);

	_rc = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);

	_img = IMAGEMANAGER->findImage("marnie");

	return S_OK;
}

void marnie::release()
{
}

void marnie::update()
{
	_rc = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);

	int tileX, tileY;

	RECT rcCollision;
	rcCollision = _rc;

	rcCollision.left += 2;
	rcCollision.top += 2;
	rcCollision.right -= 2;
	rcCollision.bottom -= 2;

	tileX = rcCollision.left / TILEWIDTH;
	tileY = rcCollision.top / TILEHEIGHT;

	_idX = tileX;
	_idY = tileY;
}

void marnie::render()
{
	_img->frameRender(getMemDC(), _x - _cameraManager->getCamX(), _y - _cameraManager->getCamY());
}

//�����ִ� ���� �߰��ϴ� �Լ�
vector<tile*> marnie::addOpenList(tile* currentTile)
{
	int startX = currentTile->getIdX() - 1;
	int startY = currentTile->getIdY() - 1;


	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 0)
			{
				if (j == 0 || j == 2) continue;
			}

			else if (i == 1 && j == 1) continue;

			else if (i == 2)
			{
				if (j == 0 || j == 2)continue;
			}

			tile* node = _vTotalList[(startY * TILEX) + startX + j + (i * TILEY)];

			//����ó��
			if (!node->getIsOpen()) continue;
			if (node->getAttribute() == "start") continue;
			if (node->getAttribute() == "wall") continue;



			//���� Ÿ�� �������ش�
			node->setParentNode(_currentTile);

			bool addObj = true;

			for (int i = 0; i < _vOpenList.size(); i++)
			{
				//�̹� �ִ� �ָ�
				if (_vOpenList[i] == node)
				{
					addObj = false;
					break;
				}
			}


			if (node->getAttribute() != "end") node->setColor(RGB(255, 0, 0));

			//�̹� üũ�� �ָ�
			if (!addObj) continue;

			//�ڷ� �Ѿ�� �ʰ� �ϱ����� ���� ó��
			if (node->getIdX() <= 0) continue;
			if (node->getIdX() >= TILEX) continue;
			if (node->getIdY() <= 0) continue;
			if (node->getIdY() >= TILEY) continue;

			_vOpenList.push_back(node);
		}

	}
	return _vOpenList;
}

void marnie::pathFinder(tile* currentTile)
{
	//���ϱ� ���� ������ ��κ���� �����ؿ�õӽô�
	float tempTotalCost = 5000;
	tile* tempTile = nullptr;

	//���¸���Ʈ ���� �ȿ��� ���� ���� ��θ� �̾Ƴ���
	for (int i = 0; i < addOpenList(currentTile).size(); ++i)
	{
		//H �� ����
		_vOpenList[i]->setCostToGoal(
			(abs(_endTile->getIdX() - _vOpenList[i]->getIdX()) +
				abs(_endTile->getIdY() - _vOpenList[i]->getIdY())) * 10);

		POINT center1 = _vOpenList[i]->getParentNode()->getCenter();
		POINT center2 = _vOpenList[i]->getCenter();

		//G �� ����
		//4 ������ ��� 14�� ���� ������ ��������.
		_vOpenList[i]->setCostFromStart((getDistance(center1.x, center1.y, center2.x, center2.y) > TILEWIDTH) ? 14 : 10);

		//�� ��κ�� ����
		_vOpenList[i]->setTotalCost(_vOpenList[i]->getCostToGoal() +
			_vOpenList[i]->getCostFromStart());

		//�̾Ƴ� �� ��κ�� �߿� ���� ���� ����� �ָ� ã��
		if (tempTotalCost > _vOpenList[i]->getTotalCost())
		{
			tempTotalCost = _vOpenList[i]->getTotalCost();

			tempTile = _vOpenList[i];
		}

		bool addObj = true;

		for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
		{
			if (*_viOpenList == tempTile)
			{
				addObj = false;
				break;
			}
		}

		_vOpenList[i]->setIsOpen(false);

		if (!addObj) continue;

		_vOpenList.push_back(tempTile);
	}

	//�����ߴ�
	if (tempTile->getAttribute() == "end")
	{
		_mitsuketa = true;

		//�ִ� ��δ� ��ĥ�ؿ���ݽô�
		while (_currentTile->getParentNode() != nullptr)
		{
			_currentTile->setColor(RGB(22, 14, 128));
			_vGoList.push_back(_currentTile);
			_currentTile = _currentTile->getParentNode();
		}
		return;

	}


	_vCloseList.push_back(tempTile);

	for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
	{
		if (*_viOpenList == tempTile)
		{
			_viOpenList = _vOpenList.erase(_viOpenList);
			break;
		}
	}

	for (int i = 0; i < _vCloseList.size(); i++)
	{
		_vCloseList[i]->setColor(RGB(255, 0, 255));
	}

	_currentTile = tempTile;

	if (_vOpenList.size() == 0) //�����ִ� ���¸���Ʈ�� ���ٸ� �Լ�����.
	{
		_start = false;
		return;
	}

	//����Լ�
	//����Լ��� ���� �ڵ尡 �ſ� ª������ ���������� ������ ������
	//�ӵ��鿡���� ������
	//�� �� �� ȣ��ɶ����� �ҷ��� �޸𸮰� ���̴µ�
	//�� 1.2�ް� �̻� ���̸� �����µ� �̰� ���ÿ����÷ο��� �Ѵ�.
	//pathFinder(_currentTile);
}