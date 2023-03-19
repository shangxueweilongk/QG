#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct NODE1//单链表
{
	int data;//数据域
	struct NODE1 * next;//指针域
}node1;

typedef struct NODE2//双向链表
{
	int data;//数据域
	struct NODE2* next;//前指针
	struct NODE2* back;//后指针
}node2;


node1 * creat_list1()//单向链表
{
	int num;//节点个数
	node1 * head = (node1*)malloc(sizeof(node1));//创建头结点
	if (head == NULL)
	{
		printf("动态内存分配失败,程序结束");
		exit(0);
	}

	node1 * p_tail = head;//尾节点

	printf("输入单链表节点个数：\n");
	scanf("%d", &num);

	if (num < 1)
	{
		printf("单链表节点个数有误，程序结束\n");
		exit(0);
	}

	for (int i = 1; i <= num; i++)
	{
		node1 * p_new= (node1*)malloc(sizeof(node1));
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


node2* creat_list2()//双向链表
{
	int num;//节点个数
	node2* head = (node2*)malloc(sizeof(node2));//创建头结点
	if (head == NULL)
	{
		printf("动态内存分配失败,程序结束");
		exit(0);
	}
	head->back = NULL;
	node2* p_tail = head;//尾节点

	printf("输入双向链表节点个数：\n");
	scanf("%d", &num);

	if (num < 1)
	{
		printf("双向链表节点个数有误，程序结束\n");
		exit(0);
	}

	for (int i = 1; i <= num; i++)
	{
		node2* p_new = (node2*)malloc(sizeof(node2));
		if (p_new == NULL)
		{
			printf("动态内存分配失败,程序结束");
			exit(0);
		}
		node2* p_tem = p_tail;//中间变量储存上个节点位置
		printf("输入第%d个节点的数值：\n", i);
		scanf("%d", &p_new->data);
		p_tail->next = p_new;
		p_tail = p_new;
		p_tail->back = p_tem;
		p_new->next = NULL;//规！范！
	}
	return head;
}

void traverse_1(node1* head)//遍历单向链表
{
	printf("遍历列表：\n");
	node1* p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void traverse_2(node2* head)//遍历双向链表
{
	printf("遍历列表：\n");
	node2* p = head->next;
	node2* p_tail = NULL;
	while (p != NULL)
	{
		printf("%d ", p->data);
		if (p->next == NULL)//找到尾节点
			p_tail = p;
		p = p->next;
	}
	printf("\n");
	printf("反向遍历列表：\n");
	while (p_tail->back != NULL)
	{
		printf("%d ", p_tail->data);
		p_tail = p_tail->back;
	}
}

int main()
{
	node1* head_1 = creat_list1();
	traverse_1(head_1);

	node2* head_2 = creat_list2();
	traverse_2(head_2);
	system("pause");
	return 0;
}