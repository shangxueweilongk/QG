#pragma once
#include<stdio.h>
#include"Struct_data.h"

void traverse_1(node1* head)//遍历单向链表
{
	printf("遍历单列表：\n");
	node1* p = head->next;
	while (p != NULL)
	{
		printf("%s ", p->data);
		p = p->next;
	}
	printf("\n");
}

void traverse_2(node2* head)//遍历双向链表
{
	printf("正向遍历双向列表：\n");
	node2* p = head->next;
	node2* p_tail = NULL;
	while (p != NULL)
	{
		printf("%s ", p->data);
		if (p->next == NULL)//找到尾节点
			p_tail = p;
		p = p->next;
	}
	printf("\n");
	printf("反向遍历双向列表：\n");
	while (p_tail != NULL)
	{
		printf("%s ", p_tail->data);
		p_tail = p_tail->back;
	}
	printf("\n");
}

void traverse_3(node1* head)//遍历循环链表
{
	printf("遍历循环列表的30个节点：\n");
	node1* p = head->next;
	for (int i = 1; i <= 30; i++)
	{
		printf("%s ", p->data);
		p = p->next;
	}
	printf("\n");
}
