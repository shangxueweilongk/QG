#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Struct_data.h"

node1* creat_list1()//��������
{
	char str[100]={0},str_1[100]={0};
	int num = 0;//�ڵ����

	node1* head = (node1*)malloc(sizeof(node1));//����ͷ���
	if (head == NULL)
	{
		printf("��̬�ڴ����ʧ��,�������");
		exit(0);
	}

	node1* p_tail = head;//β�ڵ�

	printf("���뵥����ڵ������\n");
	scanf("%s", &str);
	for (int i = 0,j=0; i < strlen(str); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			str_1[j++] = str[i];
		else
		{
			printf("�ڵ�����������󣬽��˳�\n");
			return NULL;
		}
	}
	for (int i = 0; i < strlen(str_1); i++)
		num = (str[i]-48) + num * 10;

	if (num < 1)
	{
		printf("������ڵ�������󣬽��˳�\n");
		return NULL;
	}
	if (num > 1000)
	{
		printf("�ڵ�̫�࣬��Ȱ�����β�ӣ����˳�\n");
		return NULL;
	}

	for (int i = 1; i <= num; i++)
	{

		node1* p_new = (node1*)malloc(sizeof(node1));
		if (p_new == NULL)
		{
			printf("��̬�ڴ����ʧ��,�������");
			exit(0);
		}
		printf("�����%d���ڵ�����ݣ�\n", i);
		getchar();
		scanf("%s", p_new->data);
		p_new->data[strlen(p_new->data)] = 0;//��ֹ����

		p_tail->next = p_new;
		p_tail = p_new;
		p_new->next = NULL;//�棡����
	}
	return head;
}





node2* creat_list2()//˫������
{
	char str[100] = { 0 }, str_1[100] = { 0 };
	int num = 0;//�ڵ����

	node2* head = (node2*)malloc(sizeof(node2));//����ͷ���
	if (head == NULL)
	{
		printf("��̬�ڴ����ʧ��,�������");
		exit(0);
	}
	head->back = NULL;
	node2* p_tail = head;//β�ڵ�

	printf("����˫������ڵ������\n");
	scanf("%s", &str);
	for (int i = 0, j = 0; i < strlen(str); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			str_1[j++] = str[i];
		else
		{
			printf("˫������ڵ�����������󣬽��˳�\n");
			return NULL;
		}
	}
	for (int i = 0; i < strlen(str_1); i++)
		num = (str[i] - 48) + num * 10;

	if (num < 2)
	{
		printf("˫������ڵ�����������󣬽��˳�\n");
		return NULL;
	}
	if (num > 1000)
	{
		printf("�ڵ�̫�࣬��Ȱ�����β�ӣ����˳�\n");
		return NULL;
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

		printf("�����%d���ڵ�����ݣ�\n", i);
		getchar();
		scanf("%s", p_new->data);
		p_new->data[strlen(p_new->data)] = 0;//��ֹ����

		p_tail->next = p_new;
		p_tail = p_new;
		p_tail->back = p_tem;
		p_new->next = NULL;//�棡����
	}
	head->next->back = NULL;
	return head;
}





node1* creat_list3()//ѭ������
{
	char str[100] = { 0 }, str_1[100] = { 0 };
	int num = 0;//�ڵ����

	node1* head = (node1*)malloc(sizeof(node1));//����ͷ���
	if (head == NULL)
	{
		printf("��̬�ڴ����ʧ��,�������");
		exit(0);
	}

	node1* p_tail = head;//β�ڵ�

	printf("����ѭ������ڵ������\n");
	scanf("%s", &str);
	for (int i = 0, j = 0; i < strlen(str); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			str_1[j++] = str[i];
		else
		{
			printf("ѭ������ڵ�����������󣬽��˳�\n");
			return NULL;
		}
	}
	for (int i = 0; i < strlen(str_1); i++)
		num = (str[i] - 48) + num * 10;

	len = num;//�ڵ���

	if (num < 2)
	{
		printf("ѭ������ڵ�������󣬳������\n");
		exit(0);
	}
	if (num > 1000)
	{
		printf("�ڵ�̫�࣬��Ȱ�����β�ӣ����˳�\n");
		return NULL;
	}

	for (int i = 1; i <= num; i++)
	{
		node1* p_new = (node1*)malloc(sizeof(node1));
		if (p_new == NULL)
		{
			printf("��̬�ڴ����ʧ��,�������");
			exit(0);
		}
		printf("�����%d���ڵ�����ݣ�\n", i);
		getchar();
		scanf("%s", p_new->data);
		p_new->data[strlen(p_new->data)] = 0;//��ֹ����

		p_tail->next = p_new;
		p_tail = p_new;
		p_new->next = head->next;
	}

	return head;
}