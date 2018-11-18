/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��16��20:28:58
�汾��V0.1
��Ҫ����ʾ�����������
��ע��
************************************************/
#pragma once
#include "Object.h"
#include "Tip.h"

class Mediator;
class TipsManager:public Object
{
public:
	TipsManager(Mediator *mediator1);
	~TipsManager();
	void Update();
	void AddTip(const TCHAR *str1);
	void DeleteTip(Tip *tip1);
private:
	Mediator *mediator;
	list<Tip*> tips;
	list<Tip*>::iterator iterator;
	int lastftime;
};
