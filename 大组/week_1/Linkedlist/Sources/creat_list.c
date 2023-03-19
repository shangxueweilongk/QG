#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct NODE1//������
{
	int data;//������
	struct NODE1 * next;//ָ����
}node1;

typedef struct NODE2//˫������
{
	int data;//������
	struct NODE2* next;//ǰָ��
	struct NODE2* back;//��ָ��
}node2;


node1 * creat_list1()//��������
{
	int num;//�ڵ����
	node1 * head = (node1*)malloc(sizeof(node1));//����ͷ���
	if (head == NULL)
	{
		printf("��̬�ڴ����ʧ��,�������");
		exit(0);
	}

	node1 * p_tail = head;//β�ڵ�

	printf("���뵥����ڵ������\n");
	scanf("%d", &num);

	if (num < 1)
	{
		printf("������ڵ�������󣬳������\n");
		exit(0);
	}

	for (int i = 1; i <= num; i++)
	{
		node1 * p_new= (node1*)malloc(sizeof(node1));
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


node2* creat_list2()//˫������
{
	int num;//�ڵ����
	node2* head = (node2*)malloc(sizeof(node2));//����ͷ���
	if (head == NULL)
	{
		printf("��̬�ڴ����ʧ��,�������");
		exit(0);
	}
	head->back = NULL;
	node2* p_tail = head;//β�ڵ�

	printf("����˫������ڵ������\n");
	scanf("%d", &num);

	if (num < 1)
	{
		printf("˫������ڵ�������󣬳������\n");
		exit(0);
	}

	for (int i = 1; i <= num; i++)
	{
		node2* p_new = (node2*)malloc(sizeof(node2));
		if (p_new == NULL)
		{
			printf("��̬�ڴ����ʧ��,�������");
			exit(0);
		}
		node2* p_tem = p_tail;//�м���������ϸ��ڵ�λ��
		printf("�����%d���ڵ����ֵ��\n", i);
		scanf("%d", &p_new->data);
		p_tail->next = p_new;
		p_tail = p_new;
		p_tail->back = p_tem;
		p_new->next = NULL;//�棡����
	}
	return head;
}

void traverse_1(node1* head)//������������
{
	printf("�����б�\n");
	node1* p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void traverse_2(node2* head)//����˫������
{
	printf("�����б�\n");
	node2* p = head->next;
	node2* p_tail = NULL;
	while (p != NULL)
	{
		printf("%d ", p->data);
		if (p->next == NULL)//�ҵ�β�ڵ�
			p_tail = p;
		p = p->next;
	}
	printf("\n");
	printf("��������б�\n");
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