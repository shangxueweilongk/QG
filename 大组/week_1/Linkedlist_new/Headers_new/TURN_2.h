#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Struct_data.h"


node1* turn_new_1(node1* p)//������ݹ鷴ת%%%orz
{
	if (p->next == NULL)//������Ҫ����0���ڵ������������head==NULL���ж�������������������ʱ�Ѿ����Ǹ���������ﲻ���ж�
	{
		printf("������ת���\n");
		return p;
	}
	node1* p_new = turn_new_1(p->next);//�ҵ�β�ڵ�����ݹ�
	p->next->next = p;
	p->next = NULL;
	return p_new;
}

node2* turn_new_2_test(node2* p)//˫������ݹ鷴ת
{
	node2* box = NULL;
	if (p->next == NULL)//������Ҫ����0���ڵ������������head==NULL���ж�������������������ʱ�Ѿ����Ǹ���������ﲻ���ж�
	{
		printf("˫������ת���\n");
		return p;
	}
	node2* p_new = turn_new_2_test(p->next);//�ҵ�β�ڵ�����ݹ�
	box = p->next;
	p->next = p->back;
	p->back = box;
	return p_new;
}
node2* turn_new_2(node2* p)//˫������ݹ鷴ת
{
	node2* p_new = turn_new_2_test(p);
	node2* box = NULL;
	box = p_new->next;
	p_new->next = p_new->back;
	p_new->back = box;
	return p_new;
}


node1* turn_new_circle(node1* p)//˫������ݹ鷴ת
{
	if (j==len)//������Ҫ����0���ڵ������������head==NULL���ж�������������������ʱ�Ѿ����Ǹ���������ﲻ���ж�
	{
		j = 1;//����
		printf("ѭ������ת���\n");
		return p;
	}
	j++;
	node1* p_new = turn_new_circle(p->next);//�ҵ�β�ڵ�����ݹ�
	p->next->next = p;
	p->next = p_new;
	return p_new;
}
