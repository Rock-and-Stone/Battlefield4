#pragma once
#include "entity.h"
#include "CameraManager.h"

enum ENEMYDIRECTION
{
	DOWN, RIGHT, UP, LEFT
};

enum ENEMYSTATEMENT
{
	IDLE, CHASE, ATTACK, DEAD
};

class Enemy : public entity
{
protected:
	ENEMYSTATEMENT _enemyStatement;
	ENEMYDIRECTION _enemyDirection;
	CameraManager* _cm;	
	image* _image;		
	RECT _rc;			
	POINT _pos;			//������ǥ
	POINT _rend;		//������ǥ

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
	int GetEnemyPosX() { return _pos.x; }
	void SetEnemyPosX(int posX) { _pos.x = posX; }
	int GetEnemyPosY() { return _pos.y; }
	void SetEnemyPosY(int posY) { _pos.y = posY; }

};
