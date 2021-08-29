#include "pch.h"
#include "inventory.h"

HRESULT inventory::init()
{
    //������ �̹���
    _quickSlot = IMAGEMANAGER->findImage("quickSlot");
    
    //�޴��� �̹��� �ʱ�ȭ
    _invenImg = IMAGEMANAGER->findImage("itemInventory");
    _statImg = IMAGEMANAGER->findImage("statMenu");
    _craftImg = IMAGEMANAGER->findImage("craftMenu");
    _settingImg = IMAGEMANAGER->findImage("settingMenu");
    //_exitImg = IMAGEMANAGER->findImage("e");

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
  
    //�׽�Ʈ ������ ����ֱ�
    _inven[0].itemInfo.itemImg = IMAGEMANAGER->findImage("playerTool");
    _inven[1].itemInfo.itemImg = IMAGEMANAGER->findImage("playerTool");
    _inven[2].itemInfo.itemImg = IMAGEMANAGER->findImage("playerTool");
    _inven[0].itemInfo.currentFrameX = 0;
    _inven[1].itemInfo.currentFrameX = 1;
    _inven[2].itemInfo.currentFrameX = 2;

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
            DragObjectToSwap();
            break;
        case StatPage:
            break;
        case CraftPage:
            DragObject();
            break;
        case SettingPage:
            break;
        case ExitPage:
            break;

        default:
            break;
        }
    }

    else if (!_isMenuOpen)
    {


    }
   
}

void inventory::render()
{
    char str[128];
    sprintf_s(str, "isMenuOP : %d", _isMenuOpen);
    TextOut(getMemDC(), 10, 60, str, strlen(str));
    sprintf_s(str, "MenuPage : %d", _menuPage);
    TextOut(getMemDC(), 10, 80, str, strlen(str));
    sprintf_s(str, "draging : %d", _dragActivate);
    TextOut(getMemDC(), 10, 100, str, strlen(str));
    if (KEYMANAGER->isToggleKey(VK_TAB))
    {
        Rectangle(getMemDC(), _quickSlotRc);
        Rectangle(getMemDC(), _menuRc);
        Rectangle(getMemDC(), _storageRc);
        Rectangle(getMemDC(), _statRc);
        Rectangle(getMemDC(), _craftRc);
        Rectangle(getMemDC(), _settingRc);
        Rectangle(getMemDC(), _exitRc);
    
 
    }



    //�޴�â�� �������� �޴�â �ƴϸ� �����Կ�
    if (_isMenuOpen)
    {
        _currentMenuImg->render(getMemDC(), _menuRc.left, _menuRc.top);

        if (KEYMANAGER->isToggleKey(VK_F1))
        {
            for (int i = 0; i < INVENTORYSIZE; ++i)
            {
                Rectangle(getMemDC(), _inven[i].rc);
            }
        }
        //�޴�â���� ����� �Լ�
        switch (_menuPage)
        {
        case InvenPage:
            for (int i = 0; i < 3; i++)
            {
                _inven[i].itemInfo.itemImg->frameRender(getMemDC(), _inven[i].rc.left, _inven[i].rc.top, _inven[i].itemInfo.currentFrameX, 0);
            }
            break;
        case StatPage:
            break;
        case CraftPage:
            break;
        case SettingPage:
            break;
        case ExitPage:
            break;

        default:
            break;
        }
        

    }
    else if (!_isMenuOpen)
    {
        _quickSlot->render(getMemDC(), _quickSlotRc.left, _quickSlotRc.top);
    }

   

}
//�޴�â �����ִ°�
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
//�޴�â���� �κ��丮â
void inventory::MenuInvetoryOpen()
{
   //���� ���簢�� �������ش�
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 12; ++i)
        {
            //�����
            _inven[12 * j + i].rc = RectMake(307 + (i * 55.3), 178 + (j * 63), 49, 45);
        }
    }

}

void inventory::MenuStatOpen()
{

}

void inventory::MenuCraftOpen()
{

}

void inventory::MenuSettingOpen()
{

}

void inventory::MenuExitOpen()
{

}
//��ư��
void inventory::SelectMenu()
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
        /*if (PtInRect(&_exitRc, _ptMouse))
        {
            SOUNDMANAGER->play("menuSelect", 0.5f);
            _currentMenuImg = _exitImg;            
            _menuPage = ExitPage;
        }*/
    }
}
//      �޴�â���� ��ȣ�ۿ�
void inventory::ClickObject()
{
}

void inventory::DragObject()
{
    if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
    {
        _dragActivate = true;
    }
    else _dragActivate = false;
}

void inventory::DragObjectToSwap()
{
    if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
    {
        _dragActivate = true;
    }
    else _dragActivate = false;

    for (int i = 0; i < INVENTORYSIZE; ++i)
    {
        if (PtInRect(&_inven[i].rc, _ptMouse) && _dragActivate)
        {
            
        }
    }
    
   
 
}
