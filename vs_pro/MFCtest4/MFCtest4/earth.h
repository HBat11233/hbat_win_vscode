#pragma once

#include "CFace.h"

class earth
{
public:
	//���ȵȷ�n��
	int n;
	//ά�ȵȷ�m��
	//ʵ�ʷ�Ϊ2*m��
	int m;
	//��ĸ���
	int len;
	//��뾶
	int R;
	CFace* que;
public:
	earth();
	~earth();
	bool init(int n, int m, int R);
private:
	//�������ϱ��������ά����
	CP3** CreateCP3();
	//ɾ����ά����
	bool DeleteCP3(CP3** cp3);
	bool CreateCFace(CP3** cp3);
public:
	bool clear();
};

