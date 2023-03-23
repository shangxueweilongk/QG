#pragma once
#include<stdio.h>
#include"Struct_data.h"


node1* mid_search(node1* head)//找到单链表中点（遍历两次）
{
	node1* p1 = head->next, * p2 = head->next;
	int len = 0;
	while (p1 != NULL)//遍历第一次确定长度
	{
		len++;
		p1 = p1->next;
	}
	for (int i = 1; i <= len / 2 + 1; i++)//若len为偶数则取靠后那个中点
	{
		if (i == len / 2 + 1)
			return p2;
		else
			p2 = p2->next;
	}
}