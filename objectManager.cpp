#include "pch.h"
#include "objectManager.h"

objectManager::objectManager()
{
}

objectManager::~objectManager()
{
}

HRESULT objectManager::init()
{
    return S_OK;
}

void objectManager::release()
{
}
 
void objectManager::update()
{
    for (_viObject = _vObject.begin(); _viObject != _vObject.end(); _viObject++)
    {
        (*_viObject)->update();
    }
}

void objectManager::render()
{
    for (_viObject = _vObject.begin(); _viObject != _vObject.end(); _viObject++)
    {
        RECT Temp = (*_viObject)->GetObjectRect();
        (*_viObject)->render();
    }
}

void objectManager::SetWood(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
         object* Wood;
         Wood = new wood;
         Wood->init(OBJ_WOOD, "springObjects", 6, 12, PointMake(x,y));
         _vObject.push_back(Wood);
    }
}

void objectManager::SetSword(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetSlingShot(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetPufferFish(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetTuna(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetHaliBut(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetCauliFlowerSeed(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetParsnipSeed(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetPotatoSeed(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetKaleSeed(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetCauliFlower(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetParsnip(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetPotato(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetKale(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetCopper(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetIron(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::SetGold(float x, float y, int amount)
{
    //for (int i = 0; i < amount; i++)
//{
//    object* Axe;
//    Axe = new axe;
//    Axe->init(AXE,"",,,PointMake());
//    _vObject.push_back(Axe);
//}
}
void objectManager::ObjectCollsion()
{
    RECT temp;
    RECT playerRc;
    RECT ObjcetRc;
    for (int i = 0; i < _vObject.size(); i++)
    {

    }
}
// =[ ============================================= �� �� ========================================= ]=
