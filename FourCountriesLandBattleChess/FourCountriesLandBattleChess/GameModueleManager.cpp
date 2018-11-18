#include "GameModuleManager.h"
#include "Mediator.h"

GameModuleManager::GameModuleManager(Mediator * mediator1)
{
	mediator = mediator1;
	mediator->SetGMManager(this);
	gmodules[SURRENDER] = new InquiryModule(_T("ȷ��ҪͶ����"), 
		[&]()->void {	}, 
		[&]()->void {TurnOffModule(SURRENDER);	}
	);
	gmodules[DRAW] = new InquiryModule(_T("ȷ��Ҫ���壿"),
		[&]()->void {},
		[&]()->void {TurnOffModule(DRAW); }
	);
}

GameModuleManager::~GameModuleManager()
{
	for (int i = 0; i < MAX_MODULE_NUM; i++)
	{
		delete(gmodules[i]);
	}
}

void GameModuleManager::TurnOnModule(int monum)
{
	gmodules[monum]->ReStart();
}

void GameModuleManager::TurnOffModule(int monum)
{
	gmodules[monum]->ison = false;
}

void GameModuleManager::Update()
{
	for (int i = 0; i < MAX_MODULE_NUM; i++)
	{
		gmodules[i]->Update();
	}
}
