/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ����Ϸ���ƻ��������
��ע��
************************************************/
#pragma once
#include "Object.h"
#include "RectangleModule.h"

class Mediator;
class GamingScene;
class Controll:public Object
{
public:
	Controll(GamingScene *gscene1,Mediator *mediator1);
	virtual ~Controll();
	virtual void Update();
protected:
	Mediator *mediator;
	GamingScene *gscene;
};
