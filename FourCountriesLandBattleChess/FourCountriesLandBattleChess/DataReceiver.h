/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ�����ݽ������������
��ע��
************************************************/
#pragma once
#include <winsock2.h>
#include <thread>
#pragma comment (lib, "ws2_32")

class Mediator;
class DataReceiver
{
public:
	DataReceiver(Mediator * mediator1,SOCKET clientsocket);
	~DataReceiver();
private:
	std::thread *thread;
	Mediator *mediator;
};
