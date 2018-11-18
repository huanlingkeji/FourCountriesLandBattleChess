/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��18��14:29:26
�汾��V0.1
��Ҫ��ѯ������������
��ע��������Ͷ��ѯ�ʡ�����ѯ��
************************************************/
#pragma once
#include "GameModule.h"
#include "RectangleModule.h"

class InquiryModule:public GameModule
{
public:
	InquiryModule(const TCHAR *str1, function<void(void)> yes,function<void(void)>no);
	~InquiryModule();
	void Update();
	void Draw();
	void ReStart();
private:
	const TCHAR *str;
	int keeptime;
	int lasttime;
	RectangleModule *yesmodule;
	RectangleModule *nomodule;
};
