/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��10��20:36:32
�汾��V0.1
��Ҫ����Ϸ�������������
��ע��
************************************************/
#pragma once
#include "InitBackGround.h"
#include "Scene.h"
#include "GlobalData.h"

class Mediator;
class ClientManager;
class FirstInterface;
class GameManager
{
public:
	GameManager();
	~GameManager();
	void Run();
	Mediator* GetMediator();
	void ChangeScene(Scene *scene1);
private:
	MouseInput *mouseinput;
	Mediator *mediator;
	Scene *scene;
	GlobalData *glbdata;
	ClientManager *client;
};
