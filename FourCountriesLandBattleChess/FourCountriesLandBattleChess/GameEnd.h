/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ����Ϸ�����������
��ע��
************************************************/
#pragma once
#include "Controll.h"

class GameManager;
class GameEnd :public Controll
{
public:
	GameEnd(GamingScene *gscene1, Mediator *mediator1);
	~GameEnd();
	void Update();
private:
	list<Object*> objects;
};
