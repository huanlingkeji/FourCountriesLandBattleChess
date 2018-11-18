/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ��׼��ʱ��Ϣ��¼�������
��ע��
************************************************/
#pragma once
#include "Mediator.h"
#include "ChessPieces.h"
#include "Object.h"
#include "Arithmetic.h"

class PRecord:public Object
{
public:
	PRecord(Mediator *mediator1);
	~PRecord();
	bool ChoospChess();					//ѡ��
	void ChangeChess();					//����
	void Update();
	void CancleChoose();
	void Draw();
private:
	Mediator *mediator;
	ChessPieces *chesspieces;
	int ordernum;
};
