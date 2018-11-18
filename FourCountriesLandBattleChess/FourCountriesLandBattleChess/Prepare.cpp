#include "Prepare.h"
#include "GameManager.h"
#include "Mediator.h"
#include "GamingScene.h"
//�����й����н������ɾ���ˣ���������ʣ��һ�����߼�û���������
Prepare::Prepare(GamingScene *gscene1, Mediator *mediator1):Controll(gscene1,mediator1)
{
	objects.push_back(new RectangleModule(550, 500, 100, 50, _T("��ɲ���"), [&]()->void {
		gscene->ChangeControll(new Gaming(gscene ,mediator));
	}));
	objects.push_back(new RectangleModule(550, 570, 100, 50, _T("��������"), [&]()->void {
		mediator->SaveChessPosition();
	}));
	objects.push_back(new RectangleModule(550, 640, 100, 50, _T("��������"), [&]()->void {
		mediator->ReSetSquare();
	}));
	objects.push_back(new RectangleModule(550, 710, 100, 50, _T("���ٻ���"), [&]()->void {

	}));

	objects.push_back(new RectangleModule(670, 50, 100, 50, _T("���ش���"), [&]()->void {
		mediator->ReturnLobby();
	}));

	objects.push_back(new PRecord(mediator));
}

Prepare::~Prepare()
{
	for (auto o = objects.begin(); o != objects.end(); ++o)
	{
		delete(*o);
	}
}

void Prepare::Update()
{
	for (auto o = objects.begin(); o != objects.end(); ++o)
	{
		(*o)->Update();
	}
}
