#pragma once
#include "data_stack.h" 

//��ջ�Ļ�������

//��ʼ��ջ
bool initLStack(LinkStack* s)
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));//����ͷ���
	if (s->top == NULL)
	{
		printf("��̬�ڴ����ʧ�ܣ����˳�����\n");
		exit(0);
	}
	s->count = 0;
	s->top->next = NULL;
	return true;
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmptyLStack(LinkStack* s)
{
	if (s->count <= 0)
		return true;//Ϊ��
	else
		return false;//��Ϊ��
}

//�õ�ջ��Ԫ��
LinkStackPtr getTopLStack(LinkStack* s)
{
	if (isEmptyLStack(s))//Ϊ��
		return NULL;
	return s->top;
}

//���ջ
void clearLStack(LinkStack* s)
{
	if (isEmptyLStack(s))//Ϊ�ռ��Ѿ������
		return ;
	LinkStackPtr p = s->top;
	LinkStackPtr q = NULL;

	while (p->next != NULL)//��ͷ���ֹͣ(����ͷ���)
	{
		q = p;
		p = p->next;
		free(q);
	}

	s->top = p;
	s->count = 0;
}

//����ջ
void destroyLStack(LinkStack* s)
{
	if (isEmptyLStack(s))//Ϊ�ռ��Ѿ�������
		return;
	LinkStackPtr p = s->top;
	LinkStackPtr q = NULL;
	while (p != NULL)//��ͷ���Ҳ����
	{
		q = p;
		p = p->next;
		free(q);
	}
	s->top = NULL;
	s->count = 0;
}

//���ջ����
int LStackLength(LinkStack* s)
{
	return s->count;
}

//��ջ
bool pushLStack(LinkStack* s, char data)
{
	LinkStackPtr p_new = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p_new == NULL)
	{
		printf("�ڴ����ʧ�ܣ����˳�����\n");
		exit(0);
	}
	p_new->data = data;
	p_new->next = s->top;//������һ��ջ
	s->top = p_new;//�ƶ�topָ��
	(s->count)++;//���ȼ�1
	return true;
}

//��ջ
char popLStack(LinkStack* s)
{
	char c;
	if (isEmptyLStack(s))
		return 0;
	LinkStackPtr p = s->top;
	c = s->top->data;
	s->top = s->top->next;
	free(p);
	s->count--;
	return c;
}

//��ջ_1
bool pushLStack_1(LinkStack* s, int n)
{
	LinkStackPtr p_new = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p_new == NULL)
	{
		printf("�ڴ����ʧ�ܣ����˳�����\n");
		exit(0);
	}
	p_new->result = n;
	p_new->next = s->top;//������һ��ջ
	s->top = p_new;//�ƶ�topָ��
	(s->count)++;//���ȼ�1
	return true;
}

//��ջ_1(������������)
int popLStack_1(LinkStack* s)
{
	int n;
	if (isEmptyLStack(s))
		return NULL;
	LinkStackPtr p = s->top;
	n = s->top->result;
	s->top = s->top->next;
	free(p);
	s->count--;
	return n;
}

//����ջ
bool traverseLSueue(LinkStack* s)
{
	LinkStackPtr p = s->top;
	if (isEmptyLStack(s))
		return false;
	while (p->next != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	return true;
}
