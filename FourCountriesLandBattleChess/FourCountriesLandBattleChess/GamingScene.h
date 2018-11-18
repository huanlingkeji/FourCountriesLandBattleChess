/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ����Ϸ����ʱ�����������
��ע��
************************************************/
#pragma once
#include "Scene.h"
#include "GamingData.h"
#include "ChessComposition.h"
#include "Controll.h"
#include "Prepare.h"
#include "TipsManager.h"

class GamingScene :public Scene
{
public:
	GamingScene(GameManager *gmanager1);
	~GamingScene();
	void Update();
	void ChangeControll(Controll *controll1);
private:
	Controll *controll;
	list<Object*> objects;
};

