#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct NODE
{
	int data;//������
	struct NODE* next;//ָ����
}node;

node* creat_list()//��������
{
	int num;//�ڵ����
	node* head = (node*)malloc(sizeof(node));//����ͷ���
	if (head == NULL)
	{
		printf("��̬�ڴ����ʧ��,�������");
		exit(0);
	}

	node* p_tail = head;//β�ڵ�

	printf("���뵥����ڵ������\n");
	scanf("%d", &num);

	if (num < 1)
	{
		printf("������ڵ�������󣬳������\n");
		exit(0);
	}

	for (int i = 1; i <= num; i++)
	{
		node* p_new = (node*)malloc(sizeof(node));
		if (p_new == NULL)
		{
			printf("��̬�ڴ����ʧ��,�������");
			exit(0);
		}
		printf("�����%d���ڵ����ֵ��\n", i);
		scanf("%d", &p_new->data);
		p_tail->next = p_new;
		p_tail = p_new;
		p_new->next = NULL;//�棡����
	}
	return head;
}


node* creat_list1()//ѭ������
{
	int num;//�ڵ����
	node* head = (node*)malloc(sizeof(node));//����ͷ���
	if (head == NULL)
	{
		printf("��̬�ڴ����ʧ��,�������");
		exit(0);
	}

	node* p_tail = head;//β�ڵ�

	printf("����ѭ������ڵ������\n");
	scanf("%d", &num);

	if (num < 1)
	{
		printf("ѭ������ڵ�������󣬳������\n");
		exit(0);
	}

	for (int i = 1; i <= num; i++)
	{
		node* p_new = (node*)malloc(sizeof(node));
		if (p_new == NULL)
		{
			printf("��̬�ڴ����ʧ��,�������");
			exit(0);
		}
		printf("�����%d���ڵ����ֵ��\n", i);
		scanf("%d", &p_new->data);
		p_tail->next = p_new;
		p_tail = p_new;
		p_new->next = head;
	}
	return head;
}


bool circle_judge(node* p)//true�ɻ�
{
	node* p_slow = p, * p_fast = p->next;//����ָ��
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
		printf("������ɻ�\n");
	else
		printf("�������ɻ�\n");


	node* head1 = creat_list1();
	if (circle_judge(head1))
		printf("������ɻ�\n");
	else
		printf("�������ɻ�\n");
	system("pause");
	return 0;
}