#pragma once
#include "gameNode.h"
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
protected:

	ITEMS _item;


	

public:
	object();
	~object();

	virtual HRESULT init();
	virtual HRESULT init(ALLITEMS item, const char* imageName, string itemname, string iteminfo, int framex, int framey, int Price, int Damage, int hp, int sp, bool isbarriable);
	virtual void release();
	virtual void update();
	virtual void render();

	void Draw();



	//======================= ������ & ������ ======================= //

	ITEMS GetItemStruct() { return _item; }
	void SetItemStrcut(ITEMS item) { _item = item; }

	
	

	//======================= ============== ======================= //
	
	//=======================   �޸� ��ũ   ======================= //
	// 
	//======================= ============== ======================= //
};

