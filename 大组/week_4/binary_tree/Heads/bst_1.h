#pragma once
#include"data.h"

//����(��Ҫ�ı�ָ��ֵ������Ҫ����ָ��)
void bst_insert(bst** t, int num)
{
	if (*t == NULL)
	{
		*t = (bst*)malloc(sizeof(bst));
		(*t)->data = num;
		(*t)->pLchid = NULL;
		(*t)->pRchid = NULL;
		printf("����ɹ�\n");
	}
	else if (num > (*t)->data)//�Ƚڵ�ֵ�����������
		bst_insert(&((*t)->pRchid), num);
	else if (num < (*t)->data)//�Ƚڵ�ֵ�����������
		bst_insert(&((*t)->pLchid), num);
	else
		printf("����ֵ�Ѵ����޷����в���\n");
}

//ɾ��(��Ҫ�ı�ָ��ֵ������Ҫ����ָ��)
void bst_delete(bst** t, int num)
{
	if (*t == NULL)
	{
		printf("�����������ڵ���Ϊ0��δ���ҵ���Ӧ��ֵ���޷�ɾ��\n");
		return;
	}
	else if (num == (*t)->data)//��ڵ�ֵ�����ɾ��
	{
		bst* q, * s;

		if ((*t)->pRchid == NULL)//��������Ϊ�գ��ڵ�ֱ�ӱ�Ϊ������
		{
			q = *t;
			*t = (*t)->pLchid;
			free(q);
		}

		else if ((*t)->pLchid == NULL)//��������Ϊ�գ��ڵ�ֱ�ӱ�Ϊ������
		{
			q = *t;
			*t = (*t)->pRchid;
			free(q);
		}
		else//������������Ϊ��
		{
			q = *t;
			s = (*t)->pLchid;//����������
			while (s->pRchid != NULL)//�ҵ������������ֵ
			{
				q = s;//���ֵ��ǰһ����
				s = s->pRchid;
			}
			(*t)->data = s->data;//��ֵ�ı�

			if (q != *t)
				q->pRchid = s->pLchid;
			else
				q->pLchid = s->pLchid;

			free(s);//жĥɱ¿
		}
		printf("ɾ���ɹ�\n");
		return;
	}

	else if (num > (*t)->data)
		bst_delete(&((*t)->pRchid), num);
	else if (num < (*t)->data)
		bst_delete(&((*t)->pLchid), num);
}

//����
void bst_search(bst* t, int num)
{
	if (t == NULL)
	{
		printf("��ֵ�����ڣ�δ�ܲ��ҵ�\n");
		return;
	}
	else if (num == (t)->data)
	{
		printf("��ֵ���ڣ��Ѿ����ҵ�\n");
		return;
	}
	else if (num > t->data)
		bst_search(t->pRchid, num);
	else if (num < t->data)
		bst_search(t->pLchid, num);
}

//����������ݹ飩
void bst_pretraverse_1(bst* t)
{
	if (t != NULL)
	{
		printf("%d ", t->data);//�ڵ�
		bst_pretraverse_1(t->pLchid);//������
		bst_pretraverse_1(t->pRchid);//������
	}
}

//�������(�ݹ�)
void bst_intraverse_1(bst* t)
{
	if (t != NULL)
	{
		bst_intraverse_1(t->pLchid);//������
		printf("%d ", t->data);//�ڵ�
		bst_intraverse_1(t->pRchid);//������
	}
}

//�������(�ݹ�)
void bst_posttraverse_1(bst* t)
{
	if (t != NULL)
	{
		bst_posttraverse_1(t->pLchid);//������
		bst_posttraverse_1(t->pRchid);//������
		printf("%d ", t->data);//�ڵ�
	}
}

//����������ǵݹ飩
void bst_pretraverse_2(bst* t)
{
	if (t == NULL)
	{
		printf("�����������Ľڵ���Ϊ0���޷����б���\n");
		return;
	}

	LinkStack s;
	initLStack(&s);
	pushLStack(&s, t);//��t��ָ��ĵ�ַѹջ
	while (isEmptyLStack(&s) == false)//ջΪ�������
	{
		t = getTopLStack(&s);//�õ�ջ��Ԫ��
		printf("%d ", popLStack(&s)->data);//��s��ָ��ĵ�ַ��ջ
		if (t->pRchid != NULL)//��Ϊ����ѹջ
			pushLStack(&s, t->pRchid);
		if (t->pLchid != NULL)
			pushLStack(&s, t->pLchid);
	}
	destroyLStack(&s);
}

//�������(�ǵݹ�)
void bst_intraverse_2(bst* t)
{
	if (t == NULL)
	{
		printf("�����������Ľڵ���Ϊ0���޷����б���\n");
		return;
	}
	bst* p = t;
	LinkStack s;
	initLStack(&s);
	pushLStack(&s, t);
	t = t->pLchid;
	while (isEmptyLStack(&s) == false)
	{
		while (t != NULL)//���������ڵ���ջ
		{
			pushLStack(&s, t);
			t = t->pLchid;
		}
		p = popLStack(&s);
		printf("%d ", p->data);
		if (p->pRchid != NULL)
		{
			pushLStack(&s, p->pRchid);
			t = p->pRchid->pLchid;
		}
	}
	destroyLStack(&s);
}

//�������(�ǵݹ�)
void bst_posttraverse_2(bst* t)
{
	if (t == NULL)
	{
		printf("�����������Ľڵ���Ϊ0���޷����б���\n");
		return;
	}
	int arr[2000] = { 0 };
	bst* p;
	LinkStack s;
	initLStack(&s);
	while (t != NULL)//�ֽ����ڵ���������Ľڵ�ѹջ
	{
		pushLStack(&s, t);
		t = t->pLchid;
	}
	while (isEmptyLStack(&s) == false)
	{
		p = getTopLStack(&s);
		arr[p->data]++;//���ʹ�һ�ξ�+1�����ڶ��η���ʱ�Ͳ���Ҫ�ж������������

		if (arr[p->data] == 2)
			printf("%d ", popLStack(&s)->data);
		else if (p->pRchid != NULL)
		{
			p = p->pRchid;
			while (p != NULL)//���������ڵ�ѹջ
			{
				pushLStack(&s, p);
				p = p->pLchid;
			}
		}
		else
			printf("%d ", popLStack(&s)->data);
	}
	destroyLStack(&s);
}

//�������
void bst_leveltraverse(bst* t)
{
	if (t == NULL)
	{
		printf("�����������Ľڵ���Ϊ0���޷����б���\n");
		return;
	}
	LQueue s;
	InitLQueue(&s);
	EnLQueue(&s, t);
	while (IsEmptyLQueue(&s) == false)
	{
		t = GetHeadLQueue(&s);
		printf("%d ", t->data);
		DeLQueue(&s);
		if (t->pLchid != NULL)
			EnLQueue(&s, t->pLchid);
		if (t->pRchid != NULL)
			EnLQueue(&s, t->pRchid);
	}
	DestoryLQueue(&s);
}
