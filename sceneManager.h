#pragma once
#include "singletonBase.h"
#include <string>
#include <map>

class gameNode;

class sceneManager : public singletonBase<sceneManager>
{
private:
	typedef map<string, gameNode*>				mapSceneList;
	typedef map<string, gameNode*>::iterator	mapSceneIter;

	bool _isVideoPlay;

private:
	static gameNode* _currentScene;

	mapSceneList _mSceneList;


public:
	sceneManager();
	~sceneManager();

	HRESULT init();
	void release();
	void update();
	void render();

	gameNode* addScene(string sceneName, gameNode* scene);

	HRESULT changeScene(string sceneName);

	//������� ����?
	BOOL isCurrentScene(string sceneName);

	bool GetVideoPlay() { return _isVideoPlay; }
	void SetVideoPlay(bool isPlay) { _isVideoPlay = isPlay; }
};

