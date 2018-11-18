/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ�����������������
��ע��
************************************************/
#pragma once
#include <graphics.h>
#include "Object.h"
#include "PlayersData.h"

class Mediator;
class GamingData:public Object
{
public:
	GamingData(Mediator *mediator1);
	~GamingData();
	bool RsPlayerReady(int n);
	bool RsPlayerOnline(int n);
	bool RsShowPlayer41(int n, int &x, int &y);

	void Update();
	bool RsActing();
	void ShowPlayerData();
	void ShowTime();
private:
	Mediator *mediator;
	bool acting;					//�Ƿ������Լ��
	int skiptimes;					//��������
	int leftime;					//ʣ��ʱ��
	PlayersData playersdata[4];		//�������
};
