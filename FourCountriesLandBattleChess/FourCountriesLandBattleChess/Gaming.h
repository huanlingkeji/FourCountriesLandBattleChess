/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ����Ϸ����ʱ�����������
��ע��
************************************************/
#pragma once
#include "Controll.h"
#include "GameEnd.h"
#include "GRecord.h"
#include "GameModuleManager.h"
#include "TabModule.h"

class GameManager;
class Gaming:public Controll
{
public:
	Gaming(GamingScene *gscene1, Mediator *mediator1);
	~Gaming();
	void Update();
private:
	list<Object*> objects;
	TabModule *tabmodule;
};
