/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ����������������
��ע��
************************************************/
#pragma once
#include "Object.h"

class MouseInput :public Object
{
public:
	MouseInput();
	~MouseInput();
	void Update();
	static bool RsMosueMove();
	static bool RsLButtonDown();
	static bool RsMButtonDown();
	static bool RsRButtonDown();
	static bool RsOn(int x1, int y1, int width1, int height1);
	static void GetMxy(int &x1, int &y1);
	void ClearInput();
private:
	static MOUSEMSG m;
};
