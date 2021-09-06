#pragma once
#include "gameNode.h"
#include <vector>
//�̰� ���� ��ũ��Ÿ�� ����
#pragma region items

#include "itemStone.h"
#include "itemWood.h"
#include "itemBox.h"
#include "itemFurNance.h"
#include "itemScareCrow1.h"
#include "itemScareCrow2.h"

#include "itemCauliFlower.h"
#include "itemKale.h"
#include "itemParsnip.h"
#include "itemPotato.h"

#include "itemHaliBut.h"
#include "itemPufferFish.h"
#include "itemTuna.h"

#include "itemCopper.h"
#include "itemGold.h"
#include "itemIron.h"

#include "itemCauliSeed.h"
#include "itemKaleSeed.h"
#include "itemPotatoSeed.h"
#include "itemParsnipSeed.h"

#include "itemSlingShot.h"
#include "itemSword.h"

#include "itemAxe.h"
#include "itemPickAxe.h"
#include "itemCan.h"
#include "itemRod.h"
#include "itemHoe.h"
#include "itemSickle.h"

#pragma endregion

#include "itemNull.h"




#define INVENTORYSIZE 36
#define QUICKSLOTSIZE 36

class button;

enum MenuPage
{
	InvenPage,
	StatPage,
	CraftPage,
	SettingPage,
	ExitPage,
};

struct tagInventory
{
	int		amount;
	bool	itemExist;
	RECT	rc;				//�޴� ĭ���� ���� ĭ��	
};

class inventory : public gameNode
{
private:
	vector<item*>				_vInven;
	vector<item*>::iterator		_viInven;

	vector<item*>				_vItemInfo;
	vector<item*>::iterator		_viItemInfo;


	//������ ������
#pragma region itemnew

	itemStone* _stone;
	itemWood* _wood;

	itemBox* _box;
	itemFurNance* _furnance;
	itemScareCrow1* _scareCrow1;
	itemScareCrow2* _scareCrow2;

	itemCauliFlower* _cauliFlower;
	itemKale* _kale;
	itemParsnip* _parsnip;
	itemPotato* _potato;

	itemHaliBut* _halibut;
	itemPufferFish* _pufferFish;
	itemTuna* _tuna;

	itemCopper* _copper;
	itemGold* _gold;
	itemIron* _iron;

	itemCauliSeed* _cauliSeed;
	itemKaleSeed* _kaleSeed;
	itemParsnipSeed* _parsnipSeed;
	itemPotatoSeed* _potatoSeed;

	itemAxe* _axe;
	itemPickAxe* _pickAxe;
	itemCan* _can;
	itemHoe* _hoe;
	itemRod* _rod;
	itemSickle* _sickle;

	itemSlingShot* _slingShot;
	itemSword* _sword;

	itemNull* _null;
#pragma endregion




	//itemManager* _itemManager;

	MenuPage _menuPage;

	tagInventory _inven[INVENTORYSIZE];
	tagInventory _quick[QUICKSLOTSIZE];

	//���� �����ִ� �޴� �̹���
	image* _currentMenuImg;

	//������
	image* _quickSlot;

	//������â
	RECT	_quickSlotRc;

	//���� �޴�â
	RECT	_menuRc;

	//�޴� �̹�����
	image* _invenImg;
	image* _statImg;
	image* _craftImg;
	image* _settingImg;
	image* _exitImg;
	image* _itemInfoImg;

	//�޴��ٲٴ� ��ư��?
	RECT	_storageRc;
	RECT	_statRc;
	RECT	_craftRc;
	RECT	_settingRc;
	RECT	_exitRc;

	//�޴��� ���Ǵ���
	BOOL _isMenuOpen;

	//�巡�� ������
	BOOL _dragActivate;

	//�������� �ε���
	int _downPtItem;
	//�������� �ε���
	int _upPtItem;

	int _quickSlotMin;
	int _quickSlotMax;

	BOOL	_invenIsFull;

	//��ư��
	button* _buttonToMenu;
	button* _buttonExit;
	




public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void MenuOpen();
	void SelectMenu();

	void QuickSlot();
	void MenuInvetoryOpen();
	void MenuStatOpen();
	void MenuCraftOpen();
	void MenuSettingOpen();
	void MenuExitOpen();

	//NULL�� �ִ� ���ʹ� ����� ���ִ� 
	void AddItem(item* item);
	

	static void Button(void* obj);

	//======================= ������ & ������ ======================= //
	//		
	//======================= ============== ======================= //

	//=======================   �޸� ��ũ   ======================= //
	// 
	//======================= ============== ======================= //
};







