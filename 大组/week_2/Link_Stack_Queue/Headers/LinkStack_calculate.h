#pragma once

//�Ժ�׺���ʽ��������
#include"LinkStack_turn.h"

int operate(char c, int x, int y)
{
	if (c == '+')
		return(x + y);
	else if (c == '-')
		return(x - y);
	else if (c == '*')
		return(x * y);
	else if (c == '/')
	{
		if (y == 0)//
		{
			printf("����ʽ�з�ĸΪ0�����˳�����\n");
			exit(0);
		}
		return(x / y);
	}

}

void calculate()
{
	char* nums_1 = turn();//����
	if (nums_1 == NULL)
	{
		printf("��׺���ʽ����,����������(��֧�ַǸ�������������Ҳ�����ʹ�ÿո񽫱��ʽ����)\n");
		return ;
	}
	LinkStack p;
	initLStack(&p);
	for (int i = 0; i < strlen(nums_1); i++)//����
	{
		if (isNum(nums_1[i]))
		{
			int sum = 0;
			for (; isNum(nums_1[i]); i++)
				sum = nums_1[i] - 48 + sum * 10;
			pushLStack_1(&p, sum);
		}
		if (judge_operator(nums_1[i]))
		{
			pushLStack_1(&p, operate(nums_1[i], popLStack_1(&p), popLStack_1(&p)));
		}
	}
	if (abs(getTopLStack(&p)->result) > 100000)//���
		printf("���ʽ�������(С)���ܵ���������޷�����\n");
	else
		printf("���Ϊ(����ȡ��)��%d\n", getTopLStack(&p)->result);
}
