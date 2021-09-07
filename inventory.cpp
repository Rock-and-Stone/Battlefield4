#include "pch.h"
#include "inventory.h"
#include "button.h"

HRESULT inventory::init()
{
    //������ �ڽĵ� //�濰���� ���ٴ� NEW ����....
#pragma region Newitems
    _null           = new itemNull;

    _stone          = new   itemStone;
    _wood           = new   itemWood;

    _box            = new  itemBox;
    _furnance       = new  itemFurNance;
    _scareCrow1     = new  itemScareCrow1;
    _scareCrow2     = new  itemScareCrow2;

    _cauliFlower    = new  itemCauliFlower;
    _kale           = new  itemKale;
    _parsnip        = new  itemParsnip;
    _potato         = new  itemPotato;

    _halibut        = new  itemHaliBut;
    _pufferFish     = new  itemPufferFish;
    _tuna           = new  itemTuna;

    _copper         = new  itemCopper;
    _gold           = new  itemGold;
    _iron           = new  itemIron;

    _cauliSeed      = new  itemCauliSeed;
    _kaleSeed       = new  itemKaleSeed;
    _parsnipSeed    = new  itemParsnipSeed;
    _potatoSeed     = new  itemPotatoSeed;

    _axe            = new  itemAxe;
    _pickAxe        = new  itemPickAxe;
    _can            = new  itemCan;
    _hoe            = new  itemHoe;
    _rod            = new  itemRod;
    _sickle         = new  itemSickle;

    _slingShot      = new  itemSlingShot;
    _sword          = new   itemSword;
   

    //�� ����Ÿ �ϱܾ�Ͷ� ��!
    _null        ->init();
                
    _stone       ->init();
    _wood        ->init();
             
    _box         ->init();
    _furnance    ->init();
    _scareCrow1  ->init();
    _scareCrow2  ->init();
            
    _cauliFlower ->init();
    _kale        ->init();
    _parsnip     ->init();
    _potato      ->init();
               
    _halibut     ->init();
    _pufferFish  ->init();
    _tuna        ->init();
            
    _copper      ->init();
    _gold        ->init();
    _iron        ->init();
           
    _cauliSeed   ->init();
    _kaleSeed    ->init();
    _parsnipSeed ->init();
    _potatoSeed  ->init();
           
    _axe         ->init();
    _pickAxe     ->init();
    _can         ->init();
    _hoe         ->init();
    _rod         ->init();
    _sickle      ->init();
          
    _slingShot   ->init();
    _sword       ->init();
#pragma endregion

    //��ư���̹���
    IMAGEMANAGER->addFrameImage("ExitButton", "source/Images/inventory/ExitButton.bmp", 185, 292, 1, 2, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("MenuButton", "source/Images/inventory/MenuButton.bmp", 185, 292, 1, 2, true, MAGENTA);
    IMAGEMANAGER->addImage("BOX", "source/Images/inventory/box.bmp", 42, 42, true, MAGENTA);
    
    for (int i = 0; i < 4; i++) 
    {
        _craftObjImg[i] = IMAGEMANAGER->findImage("craftObject");
        
    }
  
    _quickSlotMin = 0;
    _quickSlotMax = 12;

    _buttonExit = new button;
    _buttonToMenu = new button;

    _BOXImg = IMAGEMANAGER->findImage("BOX");
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
    _BOXRc = RectMake((_quickSlotRc.left + 15), (_quickSlotRc.top + 13), _BOXImg->getWidth(), _BOXImg->getHeight());

    _isMenuOpen = false;

    //��ư�޴�
    _buttonToMenu->init("MenuButton", WINSIZEX / 2, WINSIZEY / 2 - 100, PointMake(0, 1), PointMake(0, 0), Button, this);
    _buttonExit->init("ExitButton", WINSIZEX / 2, WINSIZEY / 2 + 100, PointMake(0, 1), PointMake(0, 0), Button, this);

  

    //�κ��� �ΰ��̶� �ĳ���
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        _vInven.push_back(_null);
    }
    //�⺻������
    AddItem(_axe);
    AddItem(_pickAxe);
    AddItem(_can);
    AddItem(_hoe);
    AddItem(_rod);
    AddItem(_sickle);
    AddItem(_slingShot);
    AddItem(_sword);

    for (int i = 0; i < 100; i++)
    {
        AddItem(_stone);
        AddItem(_wood);
    }


    //�׽�Ʈ ������ ����ֱ�
        _canBox = false;
        _canFur = false;
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
            MenuCraftOpen();

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
       QuickSlot();


    }
   
}

void inventory::render()
{
    //����� �׽�Ʈ
    char str[128];
    SetBkMode(getMemDC(), TRANSPARENT);
    HFONT oldFont, font1;
    SetTextColor(getMemDC(), RGB(0, 0, 0));
    HFONT font2 = CreateFont(30, 0, 0, 0, 400, true, false, false,
        DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
        PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("sandoll �̻�"));
    HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), font2);

    sprintf_s(str, "%d", temp);
    TextOut(getMemDC(), 100, 400, str, strlen(str));
    sprintf_s(str, "f%d", _canFur);
    TextOut(getMemDC(), 100, 420, str, strlen(str));

    sprintf_s(str, "%d", _box->GetItemInfo().needAmountToCraft);
    TextOut(getMemDC(), 100, 440, str, strlen(str));

    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (PtInRect(&_inven[i].rc, _ptMouse))
        {
            sprintf_s(str, "%d", _inven[i].itemExist);
            TextOut(getMemDC(), 10, 180, str, strlen(str));

    
            sprintf_s(str, "%s", _vInven[i]->GetItemInfo().itemName.c_str());
            TextOut(getMemDC(), 10, 200, str, strlen(str));
        }
    
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
                sprintf_s(str, "%d", i);
                TextOut(getMemDC(), _inven[i].rc.left, _inven[i].rc.bottom, str, strlen(str));
            }
        }
        //�޴�â���� ����� ����
        switch (_menuPage)
        {
        case InvenPage:
            
            for (int i = 0; i < INVENTORYSIZE; i++)
            {
                _vInven[i]->render(_inven[i].rc.left, _inven[i].rc.top);
                //
                if (_inven[i].amount != 1 && _inven[i].amount != 0 && _inven[i].amount > 1)
                {
                    sprintf_s(str, "%d", _inven[i].amount);
                    TextOut(getMemDC(), _inven[i].rc.right - 25, _inven[i].rc.bottom - 12, str, strlen(str));
                }
                if (_dragActivate)
                {
                    _vInven[_downPtItem]->render(_ptMouse.x - 20, _ptMouse.y - 20);

                    if (_inven[_downPtItem].amount != 1 && _inven[_downPtItem].amount != 0 && _inven[_downPtItem].amount > 1)
                    {
                        sprintf_s(str, "%d", _inven[_downPtItem].amount);
                        TextOut(getMemDC(), _ptMouse.x + 10, _ptMouse.y + 10, str, strlen(str));
                    }
                }
            
            }
            for (int i = 0; i < INVENTORYSIZE; i++)
            {
                if (PtInRect(&_inven[i].rc, _ptMouse) && _vInven[i] != _null)
                {
                    if (!_dragActivate)
                    {
                        _itemInfoImg->render(getMemDC(), _ptMouse.x, _ptMouse.y);


                        sprintf_s(str, "%s", _vInven[i]->GetItemInfo().itemName.c_str());
                        TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 20, str, strlen(str));


                        string  temp = _vInven[i]->GetItemInfo().itemInfo;


                        if (temp.length() > 20)
                        {
                            sprintf_s(str, "%s", temp.substr(0, 20).c_str());
                            TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 70, str, strlen(str));
                            sprintf_s(str, "%s", temp.substr(20, 20).c_str());
                            TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 90, str, strlen(str));
                        }
                        if (temp.length() < 20)
                        {
                            sprintf_s(str, "%s", temp.substr(0, temp.length()).c_str());
                            TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 70, str, strlen(str));
                        }

                    }

                }
            }
            break;

        case StatPage:
            break;

        case CraftPage:
      
          if (_canBox)
          {
              _craftObjImg[0]->frameRender(getMemDC(), _menuRc.left + 40 + (0 * 80), _menuRc.top + 80, 0, 0);
          }
          else
          {
              IMAGEMANAGER->findImage("craftObjectAlpha")->frameRender(getMemDC(), _menuRc.left + 40 + (0 * 80), _menuRc.top + 80, 0, 0);
          }

          if (_canFur)
          {
              _craftObjImg[1]->frameRender(getMemDC(), _menuRc.left + 40 + (1 * 80), _menuRc.top + 80, 1, 0);
          }
          else
          {
              IMAGEMANAGER->findImage("craftObjectAlpha")->frameRender(getMemDC(), _menuRc.left + 40 + (1 * 80), _menuRc.top + 80, 1, 0);
          }
        /*  if (_canBox)
          {
              _craftObjImg[0]->frameRender(getMemDC(), _menuRc.left + 40 + (0 * 80), _menuRc.top + 80, 0, 0);
          }     
          if (_canBox)
          {
              _craftObjImg[0]->frameRender(getMemDC(), _menuRc.left + 40 + (0 * 80), _menuRc.top + 80, 0, 0);
          }*/

             
            

            for (int i = 0; i < INVENTORYSIZE; i++)
            {
       
                if (PtInRect(&_inven[i].rc, _ptMouse) && _vInven[i] != _null)
                {
                    sprintf_s(str, "%d", _inven[i].amount);
                    TextOut(getMemDC(), _ptMouse.x + 30, _ptMouse.y, str, strlen(str));
                }

                _vInven[i]->render(_inven[i].rc.left, _inven[i].rc.top);

                if (_inven[i].amount != 1 && _inven[i].amount != 0 && _inven[i].amount > 1)
                {
                    sprintf_s(str, "%d", _inven[i].amount);
                    TextOut(getMemDC(), _inven[i].rc.right-25, _inven[i].rc.bottom-12, str, strlen(str));
                }
                if (_dragActivate)
                {
                    _vInven[_downPtItem]->render(_ptMouse.x - 20, _ptMouse.y - 20);
                    if (_inven[_downPtItem].amount != 1 && _inven[_downPtItem].amount != 0 && _inven[_downPtItem].amount > 1)
                    {
                        sprintf_s(str, "%d", _inven[_downPtItem].amount);
                        TextOut(getMemDC(), _ptMouse.x + 10, _ptMouse.y + 10, str, strlen(str));
                    }
                }
            }

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
            _BOXImg->render(getMemDC(), _BOXRc.left, _BOXRc.top);

            if (_inven[i].amount != 1 && _inven[i].amount != 0)
            {
                sprintf_s(str, "%d", _inven[i].amount);
                TextOut(getMemDC(), _quick[i].rc.right - 25, _quick[i].rc.bottom - 12, str, strlen(str));
            }

         
        }
        sprintf_s(str, "%s", _vInven[_nowQuickItem]->GetItemInfo().itemName.c_str());
        TextOut(getMemDC(), 200, 200, str, strlen(str));
        
    }
    //������ ���� �Ѱ��ִ� �뵵
    if (KEYMANAGER->isOnceKeyDown(VK_TAB))
    {
        SOUNDMANAGER->play("pickUpItem", 0.1f);
        _quickSlotMin += 12;
        _quickSlotMax += 12;

        _nowQuickItem += 12;

        if (_quickSlotMax > 36)
        {
            _quickSlotMin = 0;
            _quickSlotMax = 12;
            _nowQuickItem -= 36;
        }
    }
   
    SelectObject(getMemDC(), oldFont2);
    DeleteObject(font2);

}
//�޴�â �����ְ� ���°�(��)
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
//������ ĭ����(��)
void inventory::QuickSlot()
{
    if (!_isMenuOpen)
    {
        for (int i = 0; i < 12; i++)
        {
            //12�� ĭ���� �����ϰ�
            _quick[i].rc = RectMake((_quickSlotRc.left + 15) + (i * 44.7), (_quickSlotRc.top + 13), 42, 42); 
      
          
            if (KEYMANAGER->isOnceKeyDown('1'))
            {
                _BOXRc = RectMake(_quick[0].rc.left, _quick[0].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin;
            }
            if (KEYMANAGER->isOnceKeyDown('2'))
            {
                _BOXRc = RectMake(_quick[1].rc.left, _quick[1].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 1;
            }
            if (KEYMANAGER->isOnceKeyDown('3'))
            {
                _BOXRc = RectMake(_quick[2].rc.left, _quick[2].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 2;
            }
            if (KEYMANAGER->isOnceKeyDown('4'))
            {
                _BOXRc = RectMake(_quick[3].rc.left, _quick[3].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 3;
            }
            if (KEYMANAGER->isOnceKeyDown('5'))
            {
                _BOXRc = RectMake(_quick[4].rc.left, _quick[4].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 4;
            }
            if (KEYMANAGER->isOnceKeyDown('6'))
            {
                _BOXRc = RectMake(_quick[5].rc.left, _quick[5].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 5;
            }
            if (KEYMANAGER->isOnceKeyDown('7'))
            {
                _BOXRc = RectMake(_quick[6].rc.left, _quick[6].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 6;
            }
            if (KEYMANAGER->isOnceKeyDown('8'))
            {
                _BOXRc = RectMake(_quick[7].rc.left, _quick[7].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 7;
            }
            if (KEYMANAGER->isOnceKeyDown('9'))
            {
                _BOXRc = RectMake(_quick[8].rc.left, _quick[8].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 8;
            }
            if (KEYMANAGER->isOnceKeyDown('0'))
            {
                _BOXRc = RectMake(_quick[9].rc.left, _quick[9].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 9;
            }
            if (KEYMANAGER->isOnceKeyDown(VK_OEM_MINUS))
            {
                _BOXRc = RectMake(_quick[10].rc.left, _quick[10].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 10;
            }
            if (KEYMANAGER->isOnceKeyDown(VK_OEM_PLUS))
            {
                _BOXRc = RectMake(_quick[11].rc.left, _quick[11].rc.top, _BOXImg->getWidth(), _BOXImg->getHeight());
                _nowQuickItem = _quickSlotMin + 11;
            }
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

        //���� ����
        for (int i = 0; i < INVENTORYSIZE; i++)
        {
            if (PtInRect(&_inven[i].rc, _ptMouse))
            {
                if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) _dragActivate = true;

                if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
                {
                    _downPtItem = i;
                    if (!_inven[i].itemExist) continue;
                    SOUNDMANAGER->play("pickUpItem", 0.1f);
                }

                if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
                {
                    _dragActivate = false;

                    for (int j = 0; j < INVENTORYSIZE; j++)
                    {
                        if (PtInRect(&_inven[j].rc, _ptMouse))
                        {
                            _upPtItem = j;
                            if (!_inven[_downPtItem].itemExist) break;
                            SOUNDMANAGER->play("pickUpItem", 0.1f);
                        }

                    }

                  swap(_vInven[_downPtItem], _vInven[_upPtItem]);
                  swap(_inven[_downPtItem].amount, _inven[_upPtItem].amount);
                  swap(_inven[_downPtItem].itemExist, _inven[_upPtItem].itemExist);
         
                }
            }
        }
        if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
        {
            _dragActivate = false;

            if (PtInRect(&_menuRc, _ptMouse))
            {
                swap(_vInven[_downPtItem], _vInven[_downPtItem]);
            }
        }
}
//����â�ǹ̰� �ֳ� �Ͱ�
void inventory::MenuStatOpen()
{

}
//����â(�̿�)
void inventory::MenuCraftOpen()
{
    //���簢�� ĭ����
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 12; ++i)
        {
            //12X3 ���������� rc ����
            _inven[12 * j + i].rc = RectMake(307 + (i * 55.3), 448 + (j * 55.2), 49, 45);
        }
    }
    //���� ����
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (PtInRect(&_inven[i].rc, _ptMouse))
        {
            if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) _dragActivate = true;

            if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
            {
                _downPtItem = i;
                if (!_inven[i].itemExist) continue;
                SOUNDMANAGER->play("pickUpItem", 0.1f);
            }

            if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
            {
                _dragActivate = false;

                for (int j = 0; j < INVENTORYSIZE; j++)
                {
                    if (PtInRect(&_inven[j].rc, _ptMouse))
                    {
                        _upPtItem = j;
                        if (!_inven[_downPtItem].itemExist) break;
                        SOUNDMANAGER->play("pickUpItem", 0.1f);
                    }



                }
                    //�׳� ��������� ���� �ٸ� �ش�ĭ�� ���� ������
                    swap(_vInven[_downPtItem], _vInven[_upPtItem]);
                    swap(_inven[_downPtItem].amount, _inven[_upPtItem].amount);
                    swap(_inven[_downPtItem].itemExist, _inven[_upPtItem].itemExist);
                
              

            }
        }
    }

    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (_inven[i].amount < 1)
        {
      
        }
    }

    if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
    {
        _dragActivate = false;

        if (PtInRect(&_menuRc, _ptMouse))
        {
            swap(_vInven[_downPtItem], _vInven[_downPtItem]);

        }
    }

    for (int i = 0; i < 4; i++)
    {
        _craftObjRc[i] = RectMake(_menuRc.left + 40 + (i * 80), _menuRc.top + 80, _craftObjImg[i]->getFrameWidth(), _craftObjImg[i]->getFrameHeight());
    }
    //������ �����Ѱ�?Ȯ��
    temp = 0;
    int newtemp = 0;
    bool tempbool = true;
    
    
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
      
            if (_vInven[i] == _wood)
            {
                newtemp = i;
                if ((_inven[i].amount >= _box->GetItemInfo().needAmountToCraft))
                {
                    _canBox = true;
                    if (PtInRect(&_craftObjRc[0], _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
                    {
                        AddItem(_box);
                        _inven[i].amount -= 50;
                    }
                }
                else
                {
                    _canBox = false;
                }
            }
        
  

        //if (_vInven[i]==_stone)
        //{
        //     if ((_inven[i].amount >= _furnance->GetItemInfo().needAmountToCraft))
        //     {
        //         _canFur = true;
        //         if (PtInRect(&_craftObjRc[1], _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
        //         {
        //             AddItem(_furnance);
        //             _inven[i].amount -= 10;
        //         }
        //     }
        //     else
        //     {
        //         _canFur = false;
        //     }
        //}
        //if (_vInven[i] == _copper)
        //{
        //    if ((_inven[i].amount > _furnance->GetItemInfo().needAmountToCraft))
        //    {
        //        _canFur = true;
        //        if (PtInRect(&_craftObjRc[2], _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
        //        {
        //            AddItem(_scareCrow1);
        //            _inven[i].amount -= 5;
        //        }
        //    }
        //    else
        //    {
        //        _canFur = false;
        //    }
        //}
        //if (_vInven[i] == _iron)
        //{
        //    if ((_inven[i].amount > _furnance->GetItemInfo().needAmountToCraft))
        //    {
        //        _canFur = true;
        //        if (PtInRect(&_craftObjRc[3], _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
        //        {
        //            AddItem(_scareCrow2);
        //            _inven[i].amount -= 5;
        //        }
        //    }
        //    else
        //    {
        //        _canFur = false;
        //    }
        //}
    }
     temp += _inven[newtemp].amount;
        


   

}
//����â(�̿�)
void inventory::MenuSettingOpen()
{
}
//������ �߰�(��)
void inventory::AddItem(item* item)
{
    //�ż���
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        //���� ������ �ִ°ų�>>??
        if (_vInven[i] == item)
        {
            //��ǻ� 99��
            if (_inven[i].amount > 998)
            {
                continue;
            }
            else 
            { 
                _inven[i].amount++; 
                _inven[i].itemExist = true;
                break; 
            }
        }
        //������ ����?
        else
        {
            //���ڸ��Դϱ�?
            if (!_inven[i].itemExist)
            {
                _vInven[i] = item;
                _inven[i].amount = 1;
                _inven[i].itemExist = true;
                break;
            }
            //�����ֳ׿�
            else
            {
                continue;
            }
        }
    }
}
//�޴���ư��(��)
void inventory::SelectMenu()
{
    if (PtInRect(&_storageRc, _ptMouse) || PtInRect(&_statRc, _ptMouse)
        || PtInRect(&_craftRc, _ptMouse) || PtInRect(&_settingRc, _ptMouse) || PtInRect(&_exitRc, _ptMouse))
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
//�������ư �ݹ��Լ�
void inventory::Button(void* obj)
{
    inventory* invento = (inventory*)obj;

    if (invento->_buttonExit->getBtnDir() == BUTTONDIRECTION_UP) exit(1);
    if (invento->_buttonToMenu->getBtnDir() == BUTTONDIRECTION_UP) SCENEMANAGER->changeScene("mainMenuScene");
}

