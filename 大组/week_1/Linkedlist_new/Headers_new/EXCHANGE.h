#pragma once
#include<stdio.h>
#include"Struct_data.h"

void exchange(node1* head)//���б���ż�������ڵ�1,2�������ڵ�3,4����...��ֻʣ���ڵ��򲻽������磺(in)1->2->3->4->5,(out)2->1->4->3->5��
{
	printf("��ż�������\n");
	int len_1 = 0, i = 1;//��ڵ�������ж�Ҫ��������
	node1* p1 = head->next;
	while (p1 != NULL)
	{
		len_1++;
		p1 = p1->next;
	}

	for (node1* p = head; i <= len_1 / 2; p = p->next, i++)
	{
		node1* p_tem1 = p->next, * p_tem2 = p_tem1->next;

		p->next = p_tem2;
		p_tem1->next = p_tem2->next;
		p_tem2->next = p_tem1;
		p = p->next;//r��p����ǰһ��
		if (p == NULL)
			return;
	}
}
