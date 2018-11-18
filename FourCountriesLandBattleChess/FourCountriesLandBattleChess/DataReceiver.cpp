
#include "DataReceiver.h"
#include "Mediator.h"

void RevData(SOCKET clientsocket);
void SolveData(char *buffer);

DataReceiver::DataReceiver(Mediator * mediator1, SOCKET clientsocket)
{
	mediator = mediator1;
	thread = new std::thread(RevData, clientsocket);
}

DataReceiver::~DataReceiver()
{

}

void RevData(SOCKET clientsocket)
{
	int flag = 1;
	while (flag)
	{
		char buffer[1000] = { 0 };
		flag = recv(clientsocket, buffer, 1000, NULL);
		if (flag > 0)
		{
			printf("���յ���������Ϣ:%s ����ֵΪ%d\n", buffer, flag);
			SolveData(buffer);
		}
	}
	printf("�ͻ������ӶϿ� �׽��ֱ�ʶΪ%d\n", (int)clientsocket);
	closesocket(clientsocket);
}

void SolveData(char *buffer)
{
	int n = 0;
	char sub[2] = {};
	memcpy(sub, buffer + n, 2);
	n += 2;
	int cnum = 0;
	sscanf_s(sub, "%2d", &cnum);
	printf("������Ϊ:%2d\n", cnum);
	int pnum = 0;
	memcpy(sub, buffer + n, 2);
	n += 2;
	sscanf_s(sub, "%2d", &pnum);
	printf("��Һ�Ϊ:%2d\n", pnum);
	int data[4] = { 0 };
	switch (cnum)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	}
}
