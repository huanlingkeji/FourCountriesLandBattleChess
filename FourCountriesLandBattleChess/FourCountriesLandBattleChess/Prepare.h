/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ����Ϸ׼��ʱ�������
��ע��
************************************************/
#pragma once
#include "Controll.h"
#include "Gaming.h"
#include "PRecord.h"

class GameManager;
class Prepare:public Controll
{
public:
	Prepare(GamingScene *gscene1, Mediator *mediator1);
	~Prepare();
	void Update();
private:
	list<Object*> objects;
};
