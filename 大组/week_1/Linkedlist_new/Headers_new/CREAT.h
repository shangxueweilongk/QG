#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Struct_data.h"

node1* creat_list1()//单向链表
{
	char str[100]={0},str_1[100]={0};
	int num = 0;//节点个数

	node1* head = (node1*)malloc(sizeof(node1));//创建头结点
	if (head == NULL)
	{
		printf("动态内存分配失败,程序结束");
		exit(0);
	}

	node1* p_tail = head;//尾节点

	printf("输入单链表节点个数：\n");
	scanf("%s", &str);
	for (int i = 0,j=0; i < strlen(str); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			str_1[j++] = str[i];
		else
		{
			printf("节点个数输入有误，将退出\n");
			return NULL;
		}
	}
	for (int i = 0; i < strlen(str_1); i++)
		num = (str[i]-48) + num * 10;

	if (num < 1)
	{
		printf("单链表节点个数有误，将退出\n");
		return NULL;
	}
	if (num > 1000)
	{
		printf("节点太多，我劝你耗子尾子，将退出\n");
		return NULL;
	}

	for (int i = 1; i <= num; i++)
	{

		node1* p_new = (node1*)malloc(sizeof(node1));
		if (p_new == NULL)
		{
			printf("动态内存分配失败,程序结束");
			exit(0);
		}
		printf("输入第%d个节点的数据：\n", i);
		getchar();
		scanf("%s", p_new->data);
		p_new->data[strlen(p_new->data)] = 0;//防止乱码

		p_tail->next = p_new;
		p_tail = p_new;
		p_new->next = NULL;//规！范！
	}
	return head;
}





node2* creat_list2()//双向链表
{
	char str[100] = { 0 }, str_1[100] = { 0 };
	int num = 0;//节点个数

	node2* head = (node2*)malloc(sizeof(node2));//创建头结点
	if (head == NULL)
	{
		printf("动态内存分配失败,程序结束");
		exit(0);
	}
	head->back = NULL;
	node2* p_tail = head;//尾节点

	printf("输入双向链表节点个数：\n");
	scanf("%s", &str);
	for (int i = 0, j = 0; i < strlen(str); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			str_1[j++] = str[i];
		else
		{
			printf("双向链表节点个数输入有误，将退出\n");
			return NULL;
		}
	}
	for (int i = 0; i < strlen(str_1); i++)
		num = (str[i] - 48) + num * 10;

	if (num < 2)
	{
		printf("双向链表节点个数输入有误，将退出\n");
		return NULL;
	}
	if (num > 1000)
	{
		printf("节点太多，我劝你耗子尾子，将退出\n");
		return NULL;
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

		printf("输入第%d个节点的数据：\n", i);
		getchar();
		scanf("%s", p_new->data);
		p_new->data[strlen(p_new->data)] = 0;//防止乱码

		p_tail->next = p_new;
		p_tail = p_new;
		p_tail->back = p_tem;
		p_new->next = NULL;//规！范！
	}
	head->next->back = NULL;
	return head;
}





node1* creat_list3()//循环链表
{
	char str[100] = { 0 }, str_1[100] = { 0 };
	int num = 0;//节点个数

	node1* head = (node1*)malloc(sizeof(node1));//创建头结点
	if (head == NULL)
	{
		printf("动态内存分配失败,程序结束");
		exit(0);
	}

	node1* p_tail = head;//尾节点

	printf("输入循环链表节点个数：\n");
	scanf("%s", &str);
	for (int i = 0, j = 0; i < strlen(str); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			str_1[j++] = str[i];
		else
		{
			printf("循环链表节点个数输入有误，将退出\n");
			return NULL;
		}
	}
	for (int i = 0; i < strlen(str_1); i++)
		num = (str[i] - 48) + num * 10;

	len = num;//节点数

	if (num < 2)
	{
		printf("循环链表节点个数有误，程序结束\n");
		exit(0);
	}
	if (num > 1000)
	{
		printf("节点太多，我劝你耗子尾子，将退出\n");
		return NULL;
	}

	for (int i = 1; i <= num; i++)
	{
		node1* p_new = (node1*)malloc(sizeof(node1));
		if (p_new == NULL)
		{
			printf("动态内存分配失败,程序结束");
			exit(0);
		}
		printf("输入第%d个节点的数据：\n", i);
		getchar();
		scanf("%s", p_new->data);
		p_new->data[strlen(p_new->data)] = 0;//防止乱码

		p_tail->next = p_new;
		p_tail = p_new;
		p_new->next = head->next;
	}

	return head;
}