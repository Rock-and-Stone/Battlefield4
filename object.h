#pragma once
#include "gameNode.h"
#include <vector>

class object : public gameNode
{
protected:



public:
	object();
	~object();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void itemSetup();

	void Draw();



	//======================= ������ & ������ ======================= //
	//
	//======================= ============== ======================= //
	
	//=======================   �޸� ��ũ   ======================= //
	// 
	//======================= ============== ======================= //
};

