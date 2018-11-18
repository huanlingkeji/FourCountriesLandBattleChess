/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ������ʱ��¼�������
��ע��
************************************************/
#pragma once
#include "Mediator.h"
#include "ChessPieces.h"
#include "Object.h"
#include "Arithmetic.h"

class GRecord :public Object
{
public:
	GRecord(Mediator *mediator1);
	~GRecord();
	bool ChoospChess();					//ѡ��
	void MoveChess();					//����
	void Update();
	void CancleChoose();
	void Draw();
private:
	Mediator *mediator;
	ChessPieces *chesspieces;
	int ordernum;
};