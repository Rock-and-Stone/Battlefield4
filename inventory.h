#pragma once
#include "gameNode.h"
#include <vector>
#include "object.h"

#define INVENTORYSIZE 36
#define QUICKSLOTSIZE 12


enum MenuPage
{
	InvenPage,
	StatPage,
	CraftPage,
	SettingPage,
	ExitPage,
};


struct tagItemInfo
{
	image* itemImg;
	string itemName;
	int	   count;			 //����ü�� ����
	int    currentFrameX;
	int	   currentFrameY;
};
struct tagInventory
{
	tagItemInfo itemInfo;
	RECT	rc;				//�޴� ĭ���� ���� ĭ��	
};

class inventory : public gameNode
{
private:

	MenuPage _menuPage;

	tagInventory _inven[INVENTORYSIZE];

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




public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void MenuOpen();
	void SelectMenu();

	void MenuInvetoryOpen();
	void MenuStatOpen();
	void MenuCraftOpen();
	void MenuSettingOpen();
	void MenuExitOpen();


	void ClickObject();
	void DragObject();
	void DragObjectToSwap();
};

