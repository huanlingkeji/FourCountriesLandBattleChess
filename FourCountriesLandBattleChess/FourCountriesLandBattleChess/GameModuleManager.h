/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��18��14:30:58
�汾��V0.1
��Ҫ����Ϸ����������������
��ע��
************************************************/
#pragma once
#include "GameModule.h"
#include "Object.h"
#include "InquiryModule.h"

enum ModuleType{SURRENDER,DRAW,MAX_MODULE_NUM};
class Mediator;
class GameModuleManager :public Object
{
public:
	GameModuleManager(Mediator *mediator1);
	~GameModuleManager();
	void TurnOnModule(int monum);
	void TurnOffModule(int monum);
	void Update();
private:
	Mediator *mediator;
	GameModule *gmodules[MAX_MODULE_NUM];
};
