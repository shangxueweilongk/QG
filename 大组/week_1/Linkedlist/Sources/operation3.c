#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct NODE
{
	int data;//数据域
	struct NODE* next;//指针域
}node;

node* creat_list()//单向链表
{
	int num;//节点个数
	node* head = (node*)malloc(sizeof(node));//创建头结点
	if (head == NULL)
	{
		printf("动态内存分配失败,程序结束");
		exit(0);
	}

	node* p_tail = head;//尾节点

	printf("输入单链表节点个数：\n");
	scanf("%d", &num);

	if (num < 1)
	{
		printf("单链表节点个数有误，程序结束\n");
		exit(0);
	}

	for (int i = 1; i <= num; i++)
	{
		node* p_new = (node*)malloc(sizeof(node));
		if (p_new == NULL)
		{
			printf("动态内存分配失败,程序结束");
			exit(0);
		}
		printf("输入第%d个节点的数值：\n", i);
		scanf("%d", &p_new->data);
		p_tail->next = p_new;
		p_tail = p_new;
		p_new->next = NULL;//规！范！
	}
	return head;
}


node* creat_list1()//循环链表
{
	int num;//节点个数
	node* head = (node*)malloc(sizeof(node));//创建头结点
	if (head == NULL)
	{
		printf("动态内存分配失败,程序结束");
		exit(0);
	}

	node* p_tail = head;//尾节点

	printf("输入循环链表节点个数：\n");
	scanf("%d", &num);

	if (num < 1)
	{
		printf("循环链表节点个数有误，程序结束\n");
		exit(0);
	}

	for (int i = 1; i <= num; i++)
	{
		node* p_new = (node*)malloc(sizeof(node));
		if (p_new == NULL)
		{
			printf("动态内存分配失败,程序结束");
			exit(0);
		}
		printf("输入第%d个节点的数值：\n", i);
		scanf("%d", &p_new->data);
		p_tail->next = p_new;
		p_tail = p_new;
		p_new->next = head;
	}
	return head;
}


bool circle_judge(node* p)//true成环
{
	node* p_slow = p, * p_fast = p->next;//慢快指针
	while (p_slow != p_fast)
	{
		if (p_slow == NULL || p_fast == NULL)
			return false;
		p_slow = p_slow->next;
		p_fast = p_fast->next;
		if (p_fast == NULL)
			return false;
		else
			p_fast = p_fast->next;
	}
	return true;
}



int main()
{
	node* head = creat_list();
	if (circle_judge(head))
		printf("该链表成环\n");
	else
		printf("该链表不成环\n");


	node* head1 = creat_list1();
	if (circle_judge(head1))
		printf("该链表成环\n");
	else
		printf("该链表不成环\n");
	system("pause");
	return 0;
}