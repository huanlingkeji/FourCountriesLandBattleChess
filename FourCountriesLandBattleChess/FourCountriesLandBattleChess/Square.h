/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ������������
��ע��
************************************************/
#pragma once
#include "ChessPieces.h"

class Square
{
public:
	Square();
	~Square();

	int sx;
	int sy;
	int type;
	int direction;
	ChessPieces *chesspieces;
};

