#include "ClientManager.h"
#include "GameManager.h"
#include "Mediator.h"
#include "FirstInterface.h"

//�������⣺ָ��this�޷����ݸ��׽��� 2018��11��11��10:03:24
//������⣺��ʵ���д��ݸ�������û��ʹ�ó�Ա����������������lambda����ʹ��ʱ����

//�������⣺2018��11��11��15:40:44 delete����Ԫ���ٸ�ֵ �ٴα�������ʱΪ��
//�����������ʱ����������ڲ��ṹ�����ü򵥳�Ա
GameManager::GameManager()
{
	InitBackGround initbkg;
	mediator = new Mediator(this);
	glbdata = new GlobalData(mediator);
	mouseinput = new MouseInput();
	scene = new FirstInterface(this);
	client = new ClientManager(mediator);
}
 
GameManager::~GameManager()
{
	delete(mediator);
	delete(glbdata);
	delete(mouseinput);
	delete(scene);
	delete(client);
}

void GameManager::Run()
{
	while (true)
	{
		mouseinput->Update();
		scene->Update();
		client->Update();
		mouseinput->ClearInput();
		Sleep(20);
		FlushBatchDraw();
		cleardevice();
	}
}

Mediator * GameManager::GetMediator()
{
	return mediator;
}

void GameManager::ChangeScene(Scene * scene1)
{
	delete(scene);
	scene = scene1;
	Run();
}
