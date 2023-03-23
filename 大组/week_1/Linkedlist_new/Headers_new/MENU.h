#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Struct_data.h"
#include"CREAT.h"
#include"EXCHANGE.h"
#include"SEARCH.h"
#include"JUDGE.h"
#include"TURN_1.h"
#include"TURN_2.h"
#include"TRAVERSE.h"

node1* head1 = NULL;
node2* head2 = NULL;

int flag = 0;//flag=0没创造链表，flag=1单向，flag=2双向，flag=3循环


void menu()
{
	printf("A.创建单链表\n");
	printf("B.创建双向链表\n");
	printf("C.创建循环链表\n");
	printf("D.单链表奇偶调换\n");
	printf("E.寻找单链表中点\n");
	printf("F.判断列表是否成环\n");
	printf("G.反转列表(非递归)\n");
	printf("H.反转列表(递归)\n");
	printf("I.遍历链表\n");
	printf("J.结束程序\n");
}

void menucontrol()
{
	char a[200]={0};
	while (1)
	{
		system("cls");//清屏
		menu();
		printf("输入大(小)写字母进入相应功能\n");
		scanf("%s", a);
		if(strlen(a)>1)
		{
			system("cls");
			printf("输入按键有误，请重新输入\n");
			system("pause");
			getchar();
			continue;
		}

		else if (a[0] == 65 || a[0] == 97)//A.创建单链表
		{
			system("cls");
			head1=creat_list1();
			if (head1 != NULL)//不返回空指针则让flag=1(即标记创造了一个单链表)
				flag = 1;
			else
				flag = 0;
			system("pause");
			continue;
		}

		else if (a[0] == 66 || a[0] == 98)//B.创建双向链表
		{
			system("cls");
			head2=creat_list2();
			if (head2 != NULL)//不返回空指针则让flag=2(即标记创造了一个双向链表)
				flag = 2;
			else
				flag = 0;
			system("pause");
			continue;
		}

		else if (a[0] == 67 || a[0] == 99)//C.创建循环链表
		{
			system("cls");
			head1=creat_list3();
			if (head1 != NULL)//不返回空指针则让flag=3(即标记创造了一个循环链表)
				flag = 3;
			else
				flag = 0;
			system("pause");
			continue;
		}

		else if (a[0] == 68 || a[0] == 100)//D.单链表奇偶调换
		{
			system("cls");

			if (flag == 1)
				exchange(head1);
			else if(flag==0)
				printf("链表创建失败无法进行操作，将退出\n");
			else
				printf("不支持该类型链表进行操作，将退出\n");
			system("pause");
			continue;
		}

		else if (a[0] == 69 || a[0] == 101)//E.寻找单链表中点
		{
			system("cls");

			if (flag == 1)
				printf("中点数据为：%s ", mid_search(head1)->data);

			else if (flag == 0)
				printf("链表创建失败无法进行操作，将退出\n");
			else
				printf("不支持该类型链表进行操作，将退出\n");
			system("pause");
			continue;
		}

		else if (a[0] == 70 || a[0] == 102)//F.判断列表是否成环
		{

			system("cls");
			if (flag == 1)
				circle_judge1(head1);
			else if (flag == 2)
				circle_judge2(head2);
			else if (flag == 3)
				circle_judge1(head1);
			else
				printf("链表创建失败无法进行操作，将退出\n");
			system("pause");
			continue;
		}

		else if (a[0] == 71 || a[0] == 103)//G.反转列表(非递归)
		{
			system("cls");
			if (flag == 1)
				turn_1(head1);
			else if (flag == 2)
				turn_2(head2);
			else if (flag == 3)
				turn_circle(head1,len);
			else
				printf("链表创建失败无法进行操作，将退出\n");
			system("pause");
			continue;
		}

		else if (a[0] == 72 || a[0] == 104)//H.反转列表(递归)
		{
			system("cls");
			node1* head = (node1*)malloc(sizeof(node1));//创建接收首节点的地址(递归)
			if (flag == 1)
			{
				head->next = turn_new_1(head1->next);
				head1 = head;
			}
			else if (flag == 2)
			{
				head->next = turn_new_2(head2->next);
				head2 = head;
			}
			else if (flag == 3)
			{
				head->next = turn_new_circle(head1->next);
				head1 = head;
			}
			else
				printf("链表创建失败无法进行操作，将退出\n");
			system("pause");
			continue;
		}

		else if (a[0] == 73 || a[0] == 105)//I.遍历列表
		{
		    system("cls");
			if (flag == 1)
				traverse_1(head1);
			else if (flag == 2)
				traverse_2(head2);
			else if (flag == 3)
				traverse_3(head1);
			else
				printf("链表创建失败无法进行操作，将退出\n");
			system("pause");
			continue;
		}

		else if (a[0] == 74 || a[0] == 106)//J.结束程序
		{
			system("cls");
			exit(0);
		}

		else
		{
			system("cls");
			printf("输入按键有误，请重新输入\n");
			system("pause");
			continue;
		}
	}
}
