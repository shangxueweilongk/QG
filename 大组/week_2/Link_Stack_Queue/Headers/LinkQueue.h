#pragma once
#include "data_queue.h" 

//��ʼ��
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
	printf("���ٶ������\n");
}

//�ж϶����Ƿ�Ϊ��
bool IsEmptyLQueue(const LQueue* Q)
{
	if (Q->length > 0)
		return false;
	return true;
}

//�����׽ڵ��ַ
void* GetHeadLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return NULL;
	return Q->front->next->data;
}

//���ض��г���
int LengthLQueue(LQueue* Q)
{
	return Q->length;
}

//���
void EnLQueue(LQueue* Q, void* data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("��̬�ڴ����ʧ�ܣ����˳�����\n");
		exit(0);
	}
	p->data = data;//�洢����ָ��
	Q->rear->next = p;
	Q->rear = p;
	p->next = NULL;
	Q->length++;
}

//����
bool DeLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return false;
	Node* p = Q->front->next;//�洢���ӽڵ�ĵ�ַ
	Q->front->next = p->next;//ָ���½ڵ�
	if (Q->front == NULL)//���Ӻ�ͷ���ָ��NULL�Ļ���front��rear�غ�
		Q->rear = Q->front;
	free(p);//�ͷſռ�
	Q->length--;
	return true;
}

//��ն���
void ClearLQueue(LQueue* Q)
{
	Node* p = Q->front->next;//����ͷ���
	Node* q = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	Q->front->next = NULL;
	Q->rear = Q->front;
	Q->length = 0;
	printf("��ն������\n");
}

//��ӡ
void LPrint(void* q, char c)
{
	if (c == 'i')
		printf("%d ", *(int*)q);
	if (c == 'f')
		printf("%f ", *(float*)q);
	if (c == 'c')
		printf("%c ", *(char*)q);

}


//����(��ͷ��β)
bool TraverseLQueue(const LQueue* Q, char c)
{
	if (IsEmptyLQueue(Q))
		return false;
	Node* p = Q->front->next;
	while (p != NULL)
	{
		LPrint(p->data, c);
		p = p->next;
	}
	return true;
}



