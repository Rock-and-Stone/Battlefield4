#pragma once
#include "gameNode.h"
#include <vector>
//#include "CameraManager.h"

//��ü������ 
enum ALLITEMS 
{
//���� TOOLS
	AXE,			//����
	PICKAXE,		//���
	HOE,			//ȣ��
	SICKLE,			//��
	CAN,			//��������	
	ROD	,			//���ô�

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
	//NONE;
	NONE
};
struct ITEMS
{
	//����ü�� �������
	ALLITEMS    items;						//�������� ����
	image*		itemImg;					//������Ʈ �̹���

	//�κ��丮���� ���ٰ͵�
	string		itemName;					//������ �̸�
	string		itemInfo;					//������ ����

	//�������� ������ ����
	int			frameX, frameY;			    //�������̹��� ��ġ
	int			price;						//������ ����
	int			damage;						//���ݷ�
	int			hP;							//ü���� ä���ش�.
	int			sP;							//���¹̳��� ä���ش�.
	
	BOOL		isburiedAble;				//���� ������ �ִ� �����̴�?

};

class object : public gameNode
{
private:
	vector<ITEMS>				_vItem;
	vector<ITEMS>::iterator		_viItem;


public:
	object();
	~object();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void itemSetup();

	void Draw();



	//======================= ������ & ������ ======================= //
	//
	//======================= ============== ======================= //
	
	//=======================   �޸� ��ũ   ======================= //
	// 
	//======================= ============== ======================= //
};

