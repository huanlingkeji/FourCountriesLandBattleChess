
#include "GamingData.h"
#include "Mediator.h"
GamingData::GamingData(Mediator *mediator1)
{
	mediator = mediator1;
	mediator->SetGamingData(this);
	acting = false;					//�Ƿ������Լ��
	skiptimes = 5;					//��������
	leftime = 30000;				//ʣ��ʱ��
}

GamingData::~GamingData()
{

}

bool GamingData::RsPlayerReady(int n)
{
	return playersdata[n].ready;
}

bool GamingData::RsPlayerOnline(int n)
{
	return playersdata[n].online;
}

bool GamingData::RsShowPlayer41(int n, int & x, int & y)
{
	x = playersdata[n].chessx41;
	y = playersdata[n].chessy41;
	return !playersdata[n].survival40;
}

void GamingData::Update()
{
	ShowPlayerData();
	ShowTime();
}

bool GamingData::RsActing()
{
	return acting;
}

void GamingData::ShowPlayerData()
{
	int position[2][4] = { {350,700,350, 50} ,
						   {750,500, 20,500} };
	for (int i = 0; i < 4; i++)
	{
		int pn = (i+ mediator->GetOrdernum())%4;
		if (!playersdata[i].online)
		{
			continue;
		}
		if (playersdata[i].ready)
		{
			TCHAR ch[20];
			_stprintf_s(ch, _T("���%d ׼��"), i);
			setcolor(WHITE);
			outtextxy(position[0][pn], position[1][pn],ch);
		}
		else
		{
			TCHAR ch[20];
			_stprintf_s(ch, _T("���%d ����"), i);
			setcolor(WHITE);
			outtextxy(position[0][pn], position[1][pn],ch);
		}
	}
}

void GamingData::ShowTime()
{
	if (acting)
	{
		TCHAR ch[20];
		_stprintf_s(ch, _T("ʣ��ʱ��%d s"), leftime/1000);
		setcolor(WHITE);
		outtextxy(660,580, ch);

		_stprintf_s(ch, _T("ʣ����������:%d"), skiptimes);
		outtextxy(660,650, ch);
	}
}

