#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Struct_data.h"

node1* turn_1(node1* head)//������ǵݹ鷴ת(ͷ�巨)
{
	printf("������ת���\n");
	node1* p_tem1 = head->next, * p_tem2 = NULL;
	head->next = NULL;
	while (p_tem1 != NULL)
	{
		p_tem2 = p_tem1;
		p_tem1 = p_tem1->next;
		p_tem2->next = head->next;
		head->next = p_tem2;
	}
	return head;
}

node1* turn_2(node2* head)//˫����ǵݹ鷴ת(ͷ�巨)
{
	printf("˫������ת���\n");
	node2* p = head->next, * box = NULL;//box�м�����洢ָ��
	while (p != NULL)
	{
		box = p->next;
		p->next = p->back;
		p->back = box;
		if (p->back == NULL)
			head->next = p;
		p = p->back;

	}
	return head;
}

node1* turn_circle(node1* head, int len)//ѭ������ǵݹ鷴ת(ͷ�巨)
{
	printf("ѭ������ת���\n");
	if (len == 2)//ֻ�������͸ı�ͷ���λ��
	{
		head->next = head->next->next;
		return head;
	}
	node1* p_tem1 = head->next->next, * p_tem2 = NULL, * p_tem = head->next;
	for (int i = 1; i < len; i++)
	{
		p_tem2 = p_tem1;
		p_tem1 = p_tem1->next;
		p_tem2->next = head->next;
		head->next = p_tem2;
	}
	p_tem->next = p_tem2;
	return head;
}
