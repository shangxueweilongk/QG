#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Struct_data.h"


node1* turn_new_1(node1* p)//单链表递归反转%%%orz
{
	if (p->next == NULL)//正常需要考虑0个节点情况（即加上head==NULL的判断条件），但在链表创建时已经考虑该情况故这里不再判断
	{
		printf("单链表反转完成\n");
		return p;
	}
	node1* p_new = turn_new_1(p->next);//找到尾节点则出递归
	p->next->next = p;
	p->next = NULL;
	return p_new;
}

node2* turn_new_2_test(node2* p)//双向链表递归反转
{
	node2* box = NULL;
	if (p->next == NULL)//正常需要考虑0个节点情况（即加上head==NULL的判断条件），但在链表创建时已经考虑该情况故这里不再判断
	{
		printf("双向链表反转完成\n");
		return p;
	}
	node2* p_new = turn_new_2_test(p->next);//找到尾节点则出递归
	box = p->next;
	p->next = p->back;
	p->back = box;
	return p_new;
}
node2* turn_new_2(node2* p)//双向链表递归反转
{
	node2* p_new = turn_new_2_test(p);
	node2* box = NULL;
	box = p_new->next;
	p_new->next = p_new->back;
	p_new->back = box;
	return p_new;
}


node1* turn_new_circle(node1* p)//双向链表递归反转
{
	if (j==len)//正常需要考虑0个节点情况（即加上head==NULL的判断条件），但在链表创建时已经考虑该情况故这里不再判断
	{
		j = 1;//重置
		printf("循环链表反转完成\n");
		return p;
	}
	j++;
	node1* p_new = turn_new_circle(p->next);//找到尾节点则出递归
	p->next->next = p;
	p->next = p_new;
	return p_new;
}
