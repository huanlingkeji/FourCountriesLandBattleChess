/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ����Ϸ����������
��ע��
************************************************/
#pragma once
#include <functional>
#include <string>
using namespace std;

class GameModule
{
public:
	GameModule(int x1 = 0,int y1=0);
	virtual ~GameModule();
	virtual void Update();
	virtual void ReStart();
	bool ison;
protected:
	int x;
	int y;
};
