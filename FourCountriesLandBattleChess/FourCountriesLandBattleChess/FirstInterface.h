/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ����Ϸ�׽����������
��ע��
************************************************/
#pragma once
#include "Scene.h"
#include "GamingScene.h"

class GameManager;
class FirstInterface:public Scene
{
public:
	FirstInterface(GameManager *gmanager1);
	~FirstInterface();
	void Update();
private:
	list<Object*> objects;
	GameManager *gmanager;
};

