/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��10��20:57:47
�汾��V0.1
��Ҫ����������������
��ע��
************************************************/
#pragma once
#include "Module.h"

class RectangleModule :public Module
{
public:
	RectangleModule(int x1, int y1, int width1, int height1, const TCHAR *str1, function< void(void)> cbfunc1);
	~RectangleModule();
	void Update();
	void Draw();
	void SetStr(TCHAR *str1);
private:
	int width;											//������
	int height;											//����߶�
};

