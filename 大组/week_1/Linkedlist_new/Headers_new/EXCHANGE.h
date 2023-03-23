#pragma once
#include<stdio.h>
#include"Struct_data.h"

void exchange(node1* head)//单列表奇偶调换（节点1,2交换，节点3,4交换...若只剩单节点则不交换，如：(in)1->2->3->4->5,(out)2->1->4->3->5）
{
	printf("奇偶调换完成\n");
	int len_1 = 0, i = 1;//求节点个数，判断要调换几次
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
		p = p->next;//r让p再向前一步
		if (p == NULL)
			return;
	}
}
