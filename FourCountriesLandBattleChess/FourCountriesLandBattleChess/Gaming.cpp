
#include "Gaming.h"
#include "GameManager.h"
#include "Mediator.h"
#include "GamingScene.h"

Gaming::Gaming(GamingScene * gscene1, Mediator * mediator1) :Controll(gscene1, mediator1)
{
	objects.push_back(new RectangleModule(550, 530, 100, 50, _T("��������"), [&]()->void {

	}));
	objects.push_back(new RectangleModule(550, 600, 100, 50, _T("����Ͷ��"), [&]()->void {
	//	gscene->ChangeControll(new GameEnd(gscene, mediator));
		mediator->TurnOnModule(SURRENDER);
	}));
	objects.push_back(new RectangleModule(550, 670, 100, 50, _T("�������"), [&]()->void {
		mediator->TurnOnModule(DRAW);
	}));

	objects.push_back(new RectangleModule(670, 50, 100, 50, _T("���ش���"), [&]()->void {
		mediator->ReturnLobby();
	}));

	objects.push_back(new GRecord(mediator));
	objects.push_back(new GameModuleManager(mediator));
	
	tabmodule = new TabModule(mediator);
}

Gaming::~Gaming()
{
	for (auto o = objects.begin(); o != objects.end(); ++o)
	{
		delete(*o);
	}
	delete(tabmodule);
}

void Gaming::Update()
{
	if (!tabmodule->Update())
	{
		if (!mediator->RsActing())
		{
			return;
		}
		for (auto o = objects.begin(); o != objects.end(); ++o)
		{
			(*o)->Update();
		}
	}
}
