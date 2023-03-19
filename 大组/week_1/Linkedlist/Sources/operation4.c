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


node* turn_1(node* head)//�ǵݹ鷴ת(ͷ�巨)
{
	printf("����ת:\n");
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

node* turn_2(node* p)//�ݹ鷴תorz
{
	
	if (p->next == NULL)//������Ҫ����0���ڵ������������head==NULL���ж�������������������ʱ�Ѿ����Ǹ���������ﲻ���ж�
	{
		printf("����ת:\n");
		return p;
	}
	node* p_new = turn_2(p->next);//�ҵ�β�ڵ�����ݹ�
	p->next->next = p;
	p->next = NULL;

	return p_new;
}


void traverse(node* head)//��������
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

void traverse2(node* p)//��������(�ݹ�ר��)����Ϊ�����ݹ鷴ת��ͷָ�뷢���˱仯
{
	printf("�����б�");
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