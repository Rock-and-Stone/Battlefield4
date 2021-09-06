#pragma once
#include "gameNode.h"
#include <vector>


#include "itemAxe.h"
#include "itemCan.h"
#include "itemHoe.h"
#include "itemRod.h"
#include "itemSickle.h"
#include "itemPickAxe.h"
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
	itemAxe* _axe;
	itemPickAxe* _pickAxe;
	itemCan* _can;
	itemHoe* _hoe;
	itemRod* _rod;
	itemSickle* _sickle;

	itemNull* _null;


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
	
	void AddAmount();

	static void Button(void* obj);

	//======================= ������ & ������ ======================= //
	//		
	//======================= ============== ======================= //

	//=======================   �޸� ��ũ   ======================= //
	// 
	//======================= ============== ======================= //
};







