/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��10��20:57:47
�汾��V0.1
��Ҫ��������������
��ע��
************************************************/
#pragma once
#include "Object.h"
#include "MouseInput.h"

class Module :public Object
{
public:
	Module(int x1, int y1, const TCHAR *str1, function< void(void)> cbfunc1);
	virtual ~Module();
	virtual void Update();
protected:
	int x;												//����x
	int y;												//����x
	const TCHAR *str;									//��ʾ���ַ���
	bool ismouseon;										//�Ƿ񱻴���
	function< void(void)> cbfunc;						//�ص�����
};