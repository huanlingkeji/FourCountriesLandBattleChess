/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��16��20:29:18
�汾��V0.1
��Ҫ����ʾ�������
��ע��
************************************************/
#pragma once
#include <graphics.h>

class TipsManager;
class Tip
{
public:
	Tip(const TCHAR *str1,TipsManager *tipmanager1);
	~Tip();
	void Update(int x1,int y1);
	void Draw(int x1,int y1);

	int keeptime;
private:
	TipsManager *tipsmanager;
	const TCHAR *str;
};
