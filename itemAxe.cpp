#include "pch.h"
#include "itemAxe.h"

itemAxe::itemAxe()
{
}

itemAxe::~itemAxe()
{
}

HRESULT itemAxe::init()
{
	_item.items = AXE;
	_item.itemImg = IMAGEMANAGER->findImage("playerTool");
	_item.frameX = 3;
	_item.frameY = 0;
	_item.itemName = "����";
	_item.itemInfo = "������ �ڸ��� ����";

	return S_OK;
}

void itemAxe::release()
{
}

void itemAxe::update()
{
}

void itemAxe::render()
{
}
