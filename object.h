#pragma once
#include "gameNode.h"

enum ALLOBJECTS
{
	//�⺻�ڿ�
	WOOD,
	STONE,

	//���� TOOLS
	AXE,			//����
	PICKAXE,		//���
	HOE,			//ȣ��
	SICKLE,			//��
	CAN,			//��������	
	ROD,			//���ô�

	//���� WEAPON

	SWORD,			//��
	SLINGSHOT,		//����

	//������ FISH

	PUFFERFISH,		//Ȳ�ݖþ�
	TUNA,			//����
	HALIBUT,		//�ξ�

	//���� SEED

	CAULIFLOWERSEED,
	PARSNIPSEED,
	POTATOSEED,
	KALESEED,

	//�۹� CROPS

	CAULIFLOWER,	//�ݸ��ö��	350G	195Hp	87Sp	
	PARSNIP,		//�Ľ���		220G	65Hp	29Sp
	POTATO,			//����		150G	65Hp	29Sp
	KALE,			//����		220G	130Hp	58Sp

	//���� ORE
	COPPER,			//����		 5G
	IRON,			//ö			10G
	GOLD,			//���		25G

	//����
	BOX,
	FURNACE,
	SCARECROW1,
	SCARECROW2,
};

class object : public gameNode
{
protected:
	ALLOBJECTS	_obj;
	RECT		_objectRc;
	image*		_objectImg;
	int			_frameX, _frameY;
	float		_posX, _posY;
	float		_speed;
	
	bool		_isdelete;




public:
	object();
	~object();

	virtual HRESULT init(ALLOBJECTS obj, const char* imageName, int framex, int framey, POINT pos);
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void itemSetup();

	void Draw();



	//======================= ������ & ������ ======================= //
	RECT GetObjectRect() { return _objectRc; }
	void SetObjectRect(RECT rc) { _objectRc = rc; }

	float GetObjectPosX() { return _posX; }
	void SetObjectPosX(float posx) { _posX = posx; }

	float GetObjectPosY() { return _posY; }
	void SetObjectPosY(float posy) { _posY = posy; }

	float GetObjectSpeed() { return _speed; }
	void SetObjectSpeed(float spd) { _speed = spd; }

	bool GetObjectDelete() { return _isdelete; }
	void SetObjectDelete(bool del) { _isdelete = del; }
	//======================= ============== ======================= //
	
	//=======================   �޸� ��ũ   ======================= //
	// 
	//======================= ============== ======================= //
};

