#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include <vector>

#define TILEHEIGHT 32
#define TILEWIDTH 32

class CameraManager;

class homeMap : public  gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];		//Ÿ��
	DWORD _attribute[TILEX * TILEY];	//Ÿ�ϼӼ�

	CameraManager* _cameraManager;

	int _pos[2];

	typedef vector<tagTile>			  _vTile;
	typedef vector<tagTile>::iterator _viTile;

public:
	homeMap();
	~homeMap();

	HRESULT init();
	void release();
	void update();
	void render();
	
	
	void load();


	tagTile* getTile() { return _tiles; }

	//STEP2
	//Ÿ�ϼӼ��� ���� �����ڵ� ������־�� �Ҳ��ϴ�
	DWORD* getAttribute() { return _attribute; }

	//�츰 ����ϰ� ���� �ʽ��ϴ�
	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }

	void setCameraLink(CameraManager* cm) { _cameraManager = cm; }
};

