#pragma once
#include "gameNode.h"
#include "itemAxe.h"

class itemManager : public gameNode
{
private:
public:
	itemManager();
	~itemManager();


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();




	//======================= ������ & ������ ======================= //
	//
	//======================= ============== ======================= //

	//=======================   �޸� ��ũ   ======================= //
	// 
	//======================= ============== ======================= //
};

