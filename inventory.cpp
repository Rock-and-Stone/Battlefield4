#include "pch.h"
#include "inventory.h"
#include "button.h"

HRESULT inventory::init()
{
    //������ �ڽĵ� 
    _axe = new itemAxe;
    _pickAxe = new itemPickAxe;
    _null = new itemNull;

    _axe->init();
    _pickAxe->init();
    _null->init();


    //��ư���̹���
    IMAGEMANAGER->addFrameImage("ExitButton", "source/Images/inventory/ExitButton.bmp", 185, 292, 1, 2, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("MenuButton", "source/Images/inventory/MenuButton.bmp", 185, 292, 1, 2, true, MAGENTA);
   
    _quickSlotMin = 0;
    _quickSlotMax = 12;

    _buttonExit = new button;
    _buttonToMenu = new button;


    //����������â �̹���
    _itemInfoImg = IMAGEMANAGER->findImage("itemInfo");
     
    //������ �̹���
    _quickSlot = IMAGEMANAGER->findImage("quickSlot");
    
    //�޴��� �̹��� �ʱ�ȭ
    _invenImg = IMAGEMANAGER->findImage("itemInventory");
    _statImg = IMAGEMANAGER->findImage("statMenu");
    _craftImg = IMAGEMANAGER->findImage("craftMenu");
    _settingImg = IMAGEMANAGER->findImage("settingMenu");
    _exitImg = IMAGEMANAGER->findImage("exitMenu");

    //���� �޴� �̹����� = �κ��̹����� �ʱ�ȭ
    _currentMenuImg = _invenImg;
    
    //�޴��� ������ Rc ��ġ �ʱ�ȭ
    _quickSlotRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY - _quickSlot->getHeight() / 2, _quickSlot->getWidth(), _quickSlot->getHeight());
    _menuRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _currentMenuImg->getWidth(), _currentMenuImg->getHeight());

    //��ư�� RC �ʱ�ȭ
    _storageRc = RectMake(_menuRc.left + 46, _menuRc.top, 53, 60);
    _statRc = RectMake(_storageRc.right + 5, _storageRc.top, 53, 60);
    _craftRc = RectMake(_statRc.right + 5, _statRc.top, 53, 60);
    _settingRc = RectMake(_craftRc.right + 5, _craftRc.top, 53, 60);
    _exitRc = RectMake(_settingRc.right + 5, _settingRc.top, 53, 60);
    
    _isMenuOpen = false;

    //��ư�޴�
    _buttonToMenu->init("MenuButton", WINSIZEX / 2, WINSIZEY / 2 - 100, PointMake(0, 1), PointMake(0, 0), Button, this);
    _buttonExit->init("ExitButton", WINSIZEX / 2, WINSIZEY / 2 + 100, PointMake(0, 1), PointMake(0, 0), Button, this);

    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        _vInven.push_back(_null);
    }

    AddItem(0, _axe);
    AddItem(0, _axe);
    AddItem(3, _axe);
 
    
    AddItem(1, _pickAxe);
    AddItem(30, _pickAxe); 
    
    //�׽�Ʈ ������ ����ֱ�
    QuickSlot();
    
    _downPtItem = NULL;
    _upPtItem = NULL;
    return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{


    //�޴��� Ű�� ���� �Լ�
    MenuOpen();

    //�޴�â�� ��������
    if (_isMenuOpen)
    {
        //â���� ��ư��

        SelectMenu();

        //�޴�â���� ����� �Լ�
        switch (_menuPage)
        {
        case InvenPage:
            MenuInvetoryOpen();
          
            break;
        case StatPage:
            break;
        case CraftPage:
          
            break;
        case SettingPage:
            break;
        case ExitPage:
            _buttonExit->update();
            _buttonToMenu->update();
            break;

        default:
            break;
        }
    }

    else if (!_isMenuOpen)
    {
       //QuickSlot();


    }
   
}

void inventory::render()
{
    //����� �׽�Ʈ
    char str[128];
 
    sprintf_s(str, "vec : %d", _vInven.size());
    TextOut(getMemDC(), 10, 60, str, strlen(str));
    sprintf_s(str, "ptdonw : %d", _downPtItem);
    TextOut(getMemDC(), 10, 80, str, strlen(str));
    sprintf_s(str, "ptup : %d", _upPtItem);
    TextOut(getMemDC(), 10, 100, str, strlen(str));
    sprintf_s(str, "_Min : %d", _quickSlotMin);
    TextOut(getMemDC(), 10, 120, str, strlen(str));
    sprintf_s(str, "_Max : %d", _quickSlotMax);
    TextOut(getMemDC(), 10, 140, str, strlen(str));

   //���簢�� ��ġ �׽�Ʈ
 /*   if (KEYMANAGER->isToggleKey(VK_TAB))
    {
        Rectangle(getMemDC(), _quickSlotRc);
        Rectangle(getMemDC(), _menuRc);
        Rectangle(getMemDC(), _storageRc);
        Rectangle(getMemDC(), _statRc);
        Rectangle(getMemDC(), _craftRc);
        Rectangle(getMemDC(), _settingRc);
        Rectangle(getMemDC(), _exitRc);

    }*/



    //�޴�â�� �������� �޴�â �ƴϸ� �����Կ�
    if (_isMenuOpen)
    {
        _currentMenuImg->render(getMemDC(), _menuRc.left, _menuRc.top);

        if (KEYMANAGER->isToggleKey(VK_F1))
        {
            for (int i = 0; i < INVENTORYSIZE; ++i)
            {
                Rectangle(getMemDC(), _inven[i].rc);
                sprintf_s(str, "%d", i);
                TextOut(getMemDC(), _inven[i].rc.left, _inven[i].rc.bottom, str, strlen(str));

           
            
            }
        }
        //�޴�â���� ����� ����
        switch (_menuPage)
        {
        case InvenPage:
            
            for (int i = 0; i < _vInven.size(); i++)
            {
                _vInven[i]->render(_inven[i].rc.left, _inven[i].rc.top);

                if (_vInven[i]->GetItemInfo().amount != 1)
                {
                    sprintf_s(str, "%d", _vInven[i]->GetItemInfo().amount);
                    TextOut(getMemDC(), _inven[i].rc.right, _inven[i].rc.bottom, str, strlen(str));
                }
                if (_dragActivate)
                {
                    _vInven[_downPtItem]->render(_ptMouse.x-20, _ptMouse.y-20);
                    
                }
            
                   
                
             
                
                if (PtInRect(&_inven[i].rc, _ptMouse) && _vInven[i] != _null)
                {
               
                    _itemInfoImg->render(getMemDC(), _ptMouse.x, _ptMouse.y);

            
                  

                    sprintf_s(str, "%s", _vInven[i]->GetItemInfo().itemName.c_str());
                    TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 20, str, strlen(str));
                    sprintf_s(str, "%s", _vInven[i]->GetItemInfo().itemInfo.c_str());
                    TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 70, str, strlen(str));
                  
                    
                }
            }
            break;

        case StatPage:
            break;

        case CraftPage:
            break;

        case SettingPage:
            break;

        case ExitPage:
           _buttonExit->render();
           _buttonToMenu->render();
            break;

        default:
            break;
        }
        

    }
    //�޴�â�� �������� �������� �����Ѵ�
    else if (!_isMenuOpen)
    {
        //�������� �̹����� �����Ѵ�
        _quickSlot->render(getMemDC(), _quickSlotRc.left, _quickSlotRc.top);

        for (int i = _quickSlotMin; i < _quickSlotMax; i++) 
        {
            _vInven[i]->render(_quick[i % 12].rc.left, _quick[i % 12].rc.top);
        }
       
    }
    if (KEYMANAGER->isOnceKeyDown(VK_TAB))
    {
        _quickSlotMin += 12;
        _quickSlotMax += 12;


        if (_quickSlotMax > 36)
        {
            _quickSlotMin = 0;
            _quickSlotMax = 12;

        }
    }
   

}
//�޴�â �����ְ� ���°�
void inventory::MenuOpen()
{
    //�޴� Ű�� ���� ��ư
    if (KEYMANAGER->isOnceKeyDown('E')) 
    { 
        _isMenuOpen = !_isMenuOpen; 
     
     
        if (!_isMenuOpen)
            SOUNDMANAGER->play("menuClose", 0.5f);
        else
            SOUNDMANAGER->play("menuOpen", 0.5f);
    }
}

void inventory::QuickSlot()
{
    if (!_isMenuOpen)
    {
        for (int i = 0; i < 12; i++)
        {
            //12�� ĭ���� �����ϰ�
            _quick[i].rc = RectMake((_quickSlotRc.left + 15) + (i * 44.7), (_quickSlotRc.top + 13), 42, 42); 
        }
    }   
}

//�޴�â���� �κ��丮â
void inventory::MenuInvetoryOpen()
{
   //���� ���簢�� �������ش�

    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 12; ++i)
        {
            //12X3 ���������� rc ����
            _inven[12 * j + i].rc = RectMake(307 + (i * 55.3), 178 + (j * 63), 49, 45);
        }
    }
    
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (PtInRect(&_inven[i].rc, _ptMouse))
        {
            if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) _dragActivate = true;
            else _dragActivate = false;
                
            if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
            {
                
                  _downPtItem = i;   
            }
            if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
            {
                for (int j = 0; j < INVENTORYSIZE; j++)
                {
                    if (PtInRect(&_inven[j].rc, _ptMouse))
                    {
                        _upPtItem = j;
                    }

                }


                swap(_vInven[_downPtItem], _vInven[_upPtItem]);

            }
        }
    }

   
 
    
   


}
//����â
void inventory::MenuStatOpen()
{

}
//����â
void inventory::MenuCraftOpen()
{

}
//����â
void inventory::MenuSettingOpen()
{

}
//������â
void inventory::MenuExitOpen()
{

}
//������ �߰�
void inventory::AddItem(int arrNum, item* item)
{
    bool _isadd  = true;

    for (int i = 0; i < _vInven.size(); i++)
    {
        if (_vInven[i] != item)
        {
 
            _isadd = false;
        }
        if (_vInven[i] == item)
        {
            _isadd = true;
            _vInven[i]->amountAdd();
            break;   
        }
    }
    if (!_isadd)
    {
        _vInven[arrNum] = item;
    }
   



}



//��ư��
void inventory::SelectMenu()
{
    if(PtInRect(&_storageRc,_ptMouse)||PtInRect(&_statRc,_ptMouse)
       || PtInRect(&_craftRc, _ptMouse)|| PtInRect(&_settingRc, _ptMouse)|| PtInRect(&_exitRc,_ptMouse))
    { 
        if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
        {
            if (PtInRect(&_storageRc, _ptMouse) && _menuPage != InvenPage)
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _invenImg;
                _menuPage = InvenPage;
            
            }
            if (PtInRect(&_statRc, _ptMouse) && _menuPage != StatPage)
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _statImg;
                _menuPage = StatPage;
            }
            if (PtInRect(&_craftRc, _ptMouse) && _menuPage != CraftPage)
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _craftImg;
                _menuPage = CraftPage;
            }
            if (PtInRect(&_settingRc, _ptMouse) && _menuPage != SettingPage)
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _settingImg;
                _menuPage = SettingPage;
            }
            if (PtInRect(&_exitRc, _ptMouse))
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _exitImg;            
                _menuPage = ExitPage;
            }
        }
    }
}
void inventory::CheckItems()
{

}
void inventory::Button(void* obj)
{
    inventory* invento = (inventory*)obj;

    if (invento->_buttonExit->getBtnDir() == BUTTONDIRECTION_UP) exit(1);
    if (invento->_buttonToMenu->getBtnDir() == BUTTONDIRECTION_UP) SCENEMANAGER->changeScene("mainMenuScene");
}

