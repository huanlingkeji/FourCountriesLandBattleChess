/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ��ȫ�������������
��ע��
************************************************/
#pragma once
class Mediator;

class GlobalData
{
public:
	GlobalData(Mediator *mediator1);
	~GlobalData();
	int GetOrdernum();
	void SetOrdernum(int ordernum1);
private:
	Mediator *mediator;
	int ordernum;
};
