/***********************************************
���ߣ�����ʤ
ʱ�䣺2018��11��11��17:40:53
�汾��V0.1
��Ҫ����Ϸ�������������
��ע��
************************************************/
#pragma once
#include "Object.h"
#include "RectangleModule.h"

class Mediator;
class Scene:public Object
{
public:
	Scene(Mediator *mediator1);
	virtual ~Scene();
	virtual void Update();
protected:
	Mediator *mediator;
};
