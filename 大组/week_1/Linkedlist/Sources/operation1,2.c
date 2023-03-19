#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct NODE//������
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


void traverse(node* head)//����������
{
	node* p = head->next;
	printf("�����б�");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void exchange(node* head)//��ż�������ڵ�1,2�������ڵ�3,4����...��ֻʣ���ڵ��򲻽������磺(in)1->2->3->4->5,(out)2->1->4->3->5��
{
	printf("������ż����:\n");
	int len = 0, i = 1;//��ڵ�������ж�Ҫ��������
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
		p = p->next;//r��p����ǰһ��
		if (p == NULL)
			return;
	}
}


node* mid_search(node* head)//�ҵ������е㣨�������Σ�
{
	node* p1 = head->next, * p2 = head->next;
	int len = 0;
	while (p1 != NULL)//������һ��ȷ������
	{
		len++;
		p1 = p1->next;
	}
	for (int i = 1; i <= len / 2 + 1; i++)//��lenΪż����ȡ�����Ǹ��е�
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
	printf("����е����ֵ��%d ", mid_search(head)->data);
	system("pause");
	return 0;
}