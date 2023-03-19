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


node* turn_1(node* head)//非递归反转(头插法)
{
	printf("链表反转:\n");
	node* p_tem1 = head->next,*p_tem2=NULL;
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

node* turn_2(node* p)//递归反转orz
{
	
	if (p->next == NULL)//正常需要考虑0个节点情况（即加上head==NULL的判断条件），但在链表创建时已经考虑该情况故这里不再判断
	{
		printf("链表反转:\n");
		return p;
	}
	node* p_new = turn_2(p->next);//找到尾节点则出递归
	p->next->next = p;
	p->next = NULL;

	return p_new;
}


void traverse(node* head)//遍历链表
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

void traverse2(node* p)//遍历链表(递归专属)，因为经过递归反转，头指针发生了变化
{
	printf("遍历列表：");
	while (p->next != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


int main()
{
	node* head = creat_list();
	traverse(head);

	node* head1 = turn_1(head);
	traverse(head1);

	node* head2 = turn_2(head);
	traverse2(head2);

	system("pause");
	return 0;
}