#pragma once
#include<stdio.h>
#include"Struct_data.h"

void traverse_1(node1* head)//������������
{
	printf("�������б�\n");
	node1* p = head->next;
	while (p != NULL)
	{
		printf("%s ", p->data);
		p = p->next;
	}
	printf("\n");
}

void traverse_2(node2* head)//����˫������
{
	printf("�������˫���б�\n");
	node2* p = head->next;
	node2* p_tail = NULL;
	while (p != NULL)
	{
		printf("%s ", p->data);
		if (p->next == NULL)//�ҵ�β�ڵ�
			p_tail = p;
		p = p->next;
	}
	printf("\n");
	printf("�������˫���б�\n");
	while (p_tail != NULL)
	{
		printf("%s ", p_tail->data);
		p_tail = p_tail->back;
	}
	printf("\n");
}

void traverse_3(node1* head)//����ѭ������
{
	printf("����ѭ���б��30���ڵ㣺\n");
	node1* p = head->next;
	for (int i = 1; i <= 30; i++)
	{
		printf("%s ", p->data);
		p = p->next;
	}
	printf("\n");
}
