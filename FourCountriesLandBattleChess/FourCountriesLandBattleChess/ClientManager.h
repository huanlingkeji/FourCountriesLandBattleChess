/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ���ͻ����������
��ע��
************************************************/
#pragma once
#include <winsock2.h>
#pragma comment (lib, "ws2_32")
#pragma warning(disable:4996)
//ע�⣺Ҫ��ϵͳ���ļ������Զ�����ļ�ǰ��
//�������⣺�ļ���������2018��11��11��16:49:08 �Ҳ�����ô�����໥������������
//������⣺2018��11��11��20:57:59 �ķ�ʱ��ܳ� winsock2�ļ���Ҫ�����Զ����ļ���ǰ����� ע�⣡����
//�油������������ͷ�ļ���������һ������

class Mediator;
class ClientManager
{
public:
	ClientManager(Mediator *mediator1);
	~ClientManager();
	void Update();
private:
	Mediator *mediator;
	SOCKET s;
};
