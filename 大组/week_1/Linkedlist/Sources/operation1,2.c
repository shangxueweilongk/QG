#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct NODE//单链表
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


void traverse(node* head)//遍历单链表
{
	node* p = head->next;
	printf("遍历列表：");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void exchange(node* head)//奇偶调换（节点1,2交换，节点3,4交换...若只剩单节点则不交换，如：(in)1->2->3->4->5,(out)2->1->4->3->5）
{
	printf("进行奇偶调换:\n");
	int len = 0, i = 1;//求节点个数，判断要调换几次
	node* p1 = head->next;
	while (p1 != NULL)
	{
		len++;
		p1 = p1->next;
	}

	for (node* p = head; i <= len / 2; p = p->next, i++)
	{
		node* p_tem1 = p->next, * p_tem2 = p_tem1->next;

		p->next = p_tem2;
		p_tem1->next = p_tem2->next;
		p_tem2->next = p_tem1;
		p = p->next;//r让p再向前一步
		if (p == NULL)
			return;
	}
}


node* mid_search(node* head)//找到链表中点（遍历两次）
{
	node* p1 = head->next, * p2 = head->next;
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

int main()
{
	node* head = creat_list();
	traverse(head);
	exchange(head);
	traverse(head);
	printf("输出中点的数值：%d ", mid_search(head)->data);
	system("pause");
	return 0;
}