#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Struct_data.h"


void circle_judge1(node1* p)//true成环(对单链表和循环链表进行判断)
{
	node1* p_slow = p, * p_fast = p->next;//慢快指针
	while (p_slow != p_fast)
	{
		if (p_slow == NULL || p_fast == NULL)
		{
			printf("该链表不成环\n");
			return;
		}

		p_slow = p_slow->next;
		p_fast = p_fast->next;
		if (p_fast == NULL)
		{
			printf("该链表不成环\n");
			return;
		}
		else
			p_fast = p_fast->next;
	}
	printf("该链表成环\n");
}

void circle_judge2(node2* p)//true成环(对双向链表进行判断)
{
	node2* p_slow = p, * p_fast = p->next;//慢快指针
	while (p_slow != p_fast)
	{
		if (p_slow == NULL || p_fast == NULL)
		{
			printf("该链表不成环\n");
			return;
		}
		p_slow = p_slow->next;
		p_fast = p_fast->next;
		if (p_fast == NULL)
		{
			printf("该链表不成环\n");
			return;
		}
		else
			p_fast = p_fast->next;
	}
	printf("该链表成环\n");
}