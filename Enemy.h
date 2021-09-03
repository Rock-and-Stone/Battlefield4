#pragma once
#include "entity.h"
#include "CameraManager.h"
#include "tileNode.h"

enum ENEMYDIRECTION
{
	DOWN, RIGHT, UP, LEFT
};

enum ENEMYSTATEMENT
{
	IDLE, CHASE, ATTACK, DEAD
};

enum NODESTATE
{
	NODE_START,
	NODE_END,
	NODE_WALL,
	NODE_EMPTY
};

class node
{
public:
	RECT rc;
	int idX, idY;
	int F, G, H;
	node* parentNode;
	NODESTATE nodeState;

	node(){}
	node(int idx, int idy)
	{
		idX = idx;
		idY = idy;
		F = G = H = 0;
		nodeState = NODE_EMPTY;
		parentNode = NULL;
	}
};
class Enemy : public entity
{
protected:
	//aStar!!
	node* _totalNode[TILEX][TILEY];		//��ü��� 25��(������ ����)
	node* _startNode;					//���۳��
	node* _endNode;						//������
	node* _curNode;						//������

	vector<node*> _openList;			//���¸���Ʈ (ž���� ������ ��Ƶ� ����)
	vector<node*> _closeList;			//���� ã�� ������ ��Ƶ� ����
	vector<node*> _finalList;			//Ŭ�����Ʈ�� ����ִ� ������ ���������Ѽ� ��Ƶ� ����

	int _count;							//���۳��, �����带 �ѹ����� �����ϱ� ���� ����
	bool _isFind;						//�� ã�ҳ�?
	bool _isMove;						//�����̳�?

	ENEMYSTATEMENT _enemyStatement;
	ENEMYDIRECTION _enemyDirection;
	CameraManager* _cm;	
	image* _image;		
	RECT _rc;			
	POINT _pos;			//������ǥ
	POINT _rend;		//������ǥ
	int _posX, _posY;	//������ǥ
	int _idX, _idY;		//���ʹ� �ε��� ��ǥ

	int _fullHP;		//��üü��
	int _currentHP;		//����ü��

	int _frameCount = 0;	//���ʹ� �̹��� ������ī��Ʈ
	int _frameX = 0;		//���ʹ� �̹��� ������X
	int _frameY = 0;		//���ʹ� �̹��� ������Y



public:
	Enemy();
	~Enemy();

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void SwitchImage() = 0;

	void AstarInit();
	void StartSearchPlayer(int playerIdX, int playIdY);
	void SearchPlayer(int playerIdX, int playerIdY);
	//��ã�� �Լ�
	void pathFinding();
	//���¸���Ʈ �߰�
	void addOpenList(int idx, int idy);
	//���¸���Ʈ ����
	void delOpenList(int index);
	//���Ǹ� ���� �Լ�
	void setNodeColor(node* node, COLORREF color);

	void Move();
	void Draw();
	void Collision();

public:
	//frame �� ����,������
	int GetEnemyFrameX() { return _frameX; }
	void SetEnemyFrameX(int frameX) { _frameX = frameX; }
	int GetEnemyFrameY() { return _frameY; }
	void SetEnemyFrameY(int frameY) { _frameY = frameY; }

	//pos �� ����,������
	int GetEnemyPosX() { return _posX; }
	void SetEnemyPosX(int posX) { _posX = posX; }
	int GetEnemyPosY() { return _posY; }
	void SetEnemyPosY(int posY) { _posY = posY; }

	//index �� ����,������
	int GetEnemyIdX() { return _idX; }
	void SetEnemyIdX(int idX) { _idX = idX; }
	int GetEnemyIdY() { return _idY; }
	void SetEnemyIdY(int idY) { _idY = idY; }
};
