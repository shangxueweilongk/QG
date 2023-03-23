#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Struct_data.h"

node1* turn_1(node1* head)//单链表非递归反转(头插法)
{
	printf("单链表反转完成\n");
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

node1* turn_2(node2* head)//双链表非递归反转(头插法)
{
	printf("双向链表反转完成\n");
	node2* p = head->next, * box = NULL;//box中间变量存储指针
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

node1* turn_circle(node1* head, int len)//循环链表非递归反转(头插法)
{
	printf("循环链表反转完成\n");
	if (len == 2)//只有两个就改变头结点位置
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
