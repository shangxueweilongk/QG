#pragma once
#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

//����������
typedef struct BTNode
{
	int data;
	struct BTNode* pLchid;
	struct BTNode* pRchid;
}bst;
///////////////////////////////////////////
//ջ
typedef  struct Stack_Node
{
	bst* p;
	struct Stack_Node* next;
}StackNode, * LinkStackPtr;

typedef  struct  Link_Stack
{
	LinkStackPtr top;//ջ��
	int	count;//�ڵ���
}LinkStack;
//////////////////////////////////////////
//����
typedef struct node
{
	bst* p1;                   //������ָ��
	struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
	Node* front;                   //��ͷ
	Node* rear;                    //��β
	int length;            //���г���
} LQueue;

/////////////////////////////////////////////////

//ջ�ĳ�ʼ��
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
bst* getTopLStack(LinkStack* s)
{
	if (isEmptyLStack(s))//Ϊ��
		return NULL;
	return s->top->p;
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

//ѹջ
bool pushLStack(LinkStack* s, bst* t)
{
	LinkStackPtr p_new = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p_new == NULL)
	{
		printf("�ڴ����ʧ�ܣ����˳�����\n");
		exit(0);
	}
	p_new->p = t;
	p_new->next = s->top;//������һ��ջ
	s->top = p_new;//�ƶ�topָ��
	(s->count)++;//���ȼ�1
	return true;
}

//��ջ
bst* popLStack(LinkStack* s)
{
	bst* c;
	if (isEmptyLStack(s))
		return 0;
	LinkStackPtr p = s->top;
	c = s->top->p;
	s->top = s->top->next;
	free(p);
	s->count--;
	return c;
}

///////////////////////////////////////////////

//���г�ʼ��
void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));//����ͷ���
	if (Q->front == NULL)
	{
		printf("��̬�ռ䴴��ʧ�ܣ������˳�\n");
		exit(0);
	}
	Q->rear->next = NULL;
	Q->length = 0;
}

//�ж϶����Ƿ�Ϊ��
bool IsEmptyLQueue(const LQueue* Q)
{
	if (Q->length > 0)
		return false;
	return true;
}

//���ض����׽ڵ��ַ
bst* GetHeadLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return NULL;
	return Q->front->next->p1;
}

//���
void EnLQueue(LQueue* Q, bst* data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("��̬�ڴ����ʧ�ܣ����˳�����\n");
		exit(0);
	}
	p->p1 = data;//�洢����ָ��
	Q->rear->next = p;
	Q->rear = p;
	p->next = NULL;
	Q->length++;
}

//����
void DeLQueue(LQueue* Q)
{
	Node* p = Q->front->next;//�洢���ӽڵ�ĵ�ַ
	Q->front->next = p->next;//ָ���½ڵ�
	if (Q->front->next == NULL)//���Ӻ�ͷ���ָ��NULL�Ļ���front��rear�غ�
		Q->rear = Q->front;
	free(p);//�ͷſռ�
	Q->length--;
}

//���ٶ���
void DestoryLQueue(LQueue* Q)
{
	Node* p = Q->front;
	Node* q = NULL;
	while (p == NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	Q->length = 0;
}