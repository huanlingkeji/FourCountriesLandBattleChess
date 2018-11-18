#include "GRecord.h"

GRecord::GRecord(Mediator * mediator1)
{
	mediator = mediator1;
	ordernum = mediator->GetOrdernum();
	chesspieces = NULL;
}

GRecord::~GRecord()
{

}

bool GRecord::ChoospChess()
{
	//�����û��ѡ�� ���ҵ�������Լ�������ѡ��ɹ�
	if (chesspieces)
	{
		return false;
	}
	if (MouseInput::RsLButtonDown())
	{
		int x, y;
		MouseInput::GetMxy(x, y);
		ChessPieces *cps = mediator->GetChess(x, y);
		if (cps && cps->camp == ordernum && cps->ismove)
		{
			chesspieces = cps;
			mediator->AddTip(_T("ѡȡ����"));
			return true;
		}
	}
	return false;
}

void GRecord::MoveChess()
{
	if (!chesspieces)
	{
		return;
	}
	if (MouseInput::RsLButtonDown())
	{
		//��ȡ������ж��Ƿ�����ƶ���Ŀ���
		int x, y;
		MouseInput::GetMxy(x, y);
		Square *square = mediator->GetSquare(x, y);
		if (!square)
		{
			return;
		}
		if (mediator->CanMoveChess(chesspieces, square))
		{
			mediator->AddTip(_T("���ӿ����ƶ���Ŀ���"));
			chesspieces = NULL;
		}
	}
}

void GRecord::Update()
{
	if (!ChoospChess())
	{
		MoveChess();
	}
	CancleChoose();
	Draw();
}

void GRecord::CancleChoose()
{
	if (MouseInput::RsRButtonDown())
	{
		mediator->AddTip(_T("ȡ��ѡ����"));
		chesspieces = NULL;
	}
}

void GRecord::Draw()
{
	if (!chesspieces)
	{
		return;
	}
	if (timeGetTime() % 1000 < 550)
	{
		return;
	}
	int hang, lie;
	PpToLp(ordernum, chesspieces->cx, chesspieces->cy, hang, lie);

	setfillcolor(BLACK);
	if (lie < 7 || lie>11)
	{
		fillrectangle(20 + lie * 40, 15 + hang * 40, 40 + lie * 40, 45 + hang * 40);//����ľ���
		rectangle(18 + lie * 40, 13 + hang * 40, 38 + lie * 40, 43 + hang * 40);
	}
	else
	{
		fillrectangle(15 + lie * 40, 20 + hang * 40, 45 + lie * 40, 40 + hang * 40);//����ľ���
		rectangle(13 + lie * 40, 18 + hang * 40, 43 + lie * 40, 38 + hang * 40);
	}
}
