#include "pch.h"
#include "hoe.h"

HRESULT hoe::init()
{
    _item.items = HOE;
    _item.itemImg = IMAGEMANAGER->findImage("playerTool");
    _item.frameX = 1;
    _item.frameY = 0;
    _item.itemName = "ȣ��";
    _item.itemInfo = "���� ������ �����ϱ����� ����";
    _item.damage = 0;
    _item.hP = 0;
    _item.sP = 0;
    _item.price = 10;

    _item.isburiedAble = true;
    return S_OK;
}

void hoe::release()
{
}

void hoe::update()
{
}

void hoe::render()
{
}

void hoe::Draw()
{
}
