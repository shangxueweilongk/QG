#pragma once
#include<stdio.h>
#include"Struct_data.h"


node1* mid_search(node1* head)//�ҵ��������е㣨�������Σ�
{
	node1* p1 = head->next, * p2 = head->next;
	int len = 0;
	while (p1 != NULL)//������һ��ȷ������
	{
		len++;
		p1 = p1->next;
	}
	for (int i = 1; i <= len / 2 + 1; i++)//��lenΪż����ȡ�����Ǹ��е�
	{
		if (i == len / 2 + 1)
			return p2;
		else
			p2 = p2->next;
	}
}