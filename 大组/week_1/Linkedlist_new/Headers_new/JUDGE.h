#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Struct_data.h"


void circle_judge1(node1* p)//true�ɻ�(�Ե������ѭ����������ж�)
{
	node1* p_slow = p, * p_fast = p->next;//����ָ��
	while (p_slow != p_fast)
	{
		if (p_slow == NULL || p_fast == NULL)
		{
			printf("�������ɻ�\n");
			return;
		}

		p_slow = p_slow->next;
		p_fast = p_fast->next;
		if (p_fast == NULL)
		{
			printf("�������ɻ�\n");
			return;
		}
		else
			p_fast = p_fast->next;
	}
	printf("������ɻ�\n");
}

void circle_judge2(node2* p)//true�ɻ�(��˫����������ж�)
{
	node2* p_slow = p, * p_fast = p->next;//����ָ��
	while (p_slow != p_fast)
	{
		if (p_slow == NULL || p_fast == NULL)
		{
			printf("�������ɻ�\n");
			return;
		}
		p_slow = p_slow->next;
		p_fast = p_fast->next;
		if (p_fast == NULL)
		{
			printf("�������ɻ�\n");
			return;
		}
		else
			p_fast = p_fast->next;
	}
	printf("������ɻ�\n");
}