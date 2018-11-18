/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��18��14:27:09
�汾��V0.1
��Ҫ����ǩ����������
��ע����������ӱ�ǩ
************************************************/
#pragma once
#include <graphics.h>
#include "MouseInput.h"
#include "ChessPieces.h"

class Mediator;
class TabModule
{
public:
	TabModule(Mediator *mediator1);
	~TabModule();
	bool Update();
	void SetXy(int x1, int y1);
	void Draw();
	int RsPoint(int x1, int y1);
	void ReStart();
private:
	Mediator *mediator;
	ChessPieces *cps;
	int x;
	int y;
	bool ison;
	int height;
	int width;
};