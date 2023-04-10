#pragma once
#include"data.h"

//插入(需要改变指针值所以需要二级指针)
void bst_insert(bst** t, int num)
{
	if (*t == NULL)
	{
		*t = (bst*)malloc(sizeof(bst));
		(*t)->data = num;
		(*t)->pLchid = NULL;
		(*t)->pRchid = NULL;
		printf("插入成功\n");
	}
	else if (num > (*t)->data)//比节点值大放在右子树
		bst_insert(&((*t)->pRchid), num);
	else if (num < (*t)->data)//比节点值大放在左子树
		bst_insert(&((*t)->pLchid), num);
	else
		printf("该数值已存在无法进行插入\n");
}

//删除(需要改变指针值所以需要二级指针)
void bst_delete(bst** t, int num)
{
	if (*t == NULL)
	{
		printf("二叉排序树节点数为0或未能找到相应的值，无法删除\n");
		return;
	}
	else if (num == (*t)->data)//与节点值相等则删除
	{
		bst* q, * s;

		if ((*t)->pRchid == NULL)//若右子树为空，节点直接变为左子树
		{
			q = *t;
			*t = (*t)->pLchid;
			free(q);
		}

		else if ((*t)->pLchid == NULL)//若左子树为空，节点直接变为右子树
		{
			q = *t;
			*t = (*t)->pRchid;
			free(q);
		}
		else//左右子树都不为空
		{
			q = *t;
			s = (*t)->pLchid;//遍历左子树
			while (s->pRchid != NULL)//找到左子树的最大值
			{
				q = s;//最大值的前一个点
				s = s->pRchid;
			}
			(*t)->data = s->data;//将值改变

			if (q != *t)
				q->pRchid = s->pLchid;
			else
				q->pLchid = s->pLchid;

			free(s);//卸磨杀驴
		}
		printf("删除成功\n");
		return;
	}

	else if (num > (*t)->data)
		bst_delete(&((*t)->pRchid), num);
	else if (num < (*t)->data)
		bst_delete(&((*t)->pLchid), num);
}

//查找
void bst_search(bst* t, int num)
{
	if (t == NULL)
	{
		printf("该值不存在，未能查找到\n");
		return;
	}
	else if (num == (t)->data)
	{
		printf("该值存在，已经查找到\n");
		return;
	}
	else if (num > t->data)
		bst_search(t->pRchid, num);
	else if (num < t->data)
		bst_search(t->pLchid, num);
}

//先序遍历（递归）
void bst_pretraverse_1(bst* t)
{
	if (t != NULL)
	{
		printf("%d ", t->data);//节点
		bst_pretraverse_1(t->pLchid);//左子树
		bst_pretraverse_1(t->pRchid);//右子树
	}
}

//中序遍历(递归)
void bst_intraverse_1(bst* t)
{
	if (t != NULL)
	{
		bst_intraverse_1(t->pLchid);//左子树
		printf("%d ", t->data);//节点
		bst_intraverse_1(t->pRchid);//右子树
	}
}

//后序遍历(递归)
void bst_posttraverse_1(bst* t)
{
	if (t != NULL)
	{
		bst_posttraverse_1(t->pLchid);//左子树
		bst_posttraverse_1(t->pRchid);//右子树
		printf("%d ", t->data);//节点
	}
}

//先序遍历（非递归）
void bst_pretraverse_2(bst* t)
{
	if (t == NULL)
	{
		printf("二叉排序树的节点数为0，无法进行遍历\n");
		return;
	}

	LinkStack s;
	initLStack(&s);
	pushLStack(&s, t);//将t所指向的地址压栈
	while (isEmptyLStack(&s) == false)//栈为空则结束
	{
		t = getTopLStack(&s);//得到栈顶元素
		printf("%d ", popLStack(&s)->data);//将s所指向的地址出栈
		if (t->pRchid != NULL)//不为空则压栈
			pushLStack(&s, t->pRchid);
		if (t->pLchid != NULL)
			pushLStack(&s, t->pLchid);
	}
	destroyLStack(&s);
}

//中序遍历(非递归)
void bst_intraverse_2(bst* t)
{
	if (t == NULL)
	{
		printf("二叉排序树的节点数为0，无法进行遍历\n");
		return;
	}
	bst* p = t;
	LinkStack s;
	initLStack(&s);
	pushLStack(&s, t);
	t = t->pLchid;
	while (isEmptyLStack(&s) == false)
	{
		while (t != NULL)//将左子树节点入栈
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

//后序遍历(非递归)
void bst_posttraverse_2(bst* t)
{
	if (t == NULL)
	{
		printf("二叉排序树的节点数为0，无法进行遍历\n");
		return;
	}
	int arr[2000] = { 0 };
	bst* p;
	LinkStack s;
	initLStack(&s);
	while (t != NULL)//现将根节点和左子树的节点压栈
	{
		pushLStack(&s, t);
		t = t->pLchid;
	}
	while (isEmptyLStack(&s) == false)
	{
		p = getTopLStack(&s);
		arr[p->data]++;//访问过一次就+1，当第二次访问时就不需要判断右子树的情况

		if (arr[p->data] == 2)
			printf("%d ", popLStack(&s)->data);
		else if (p->pRchid != NULL)
		{
			p = p->pRchid;
			while (p != NULL)//将左子树节点压栈
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

//层序遍历
void bst_leveltraverse(bst* t)
{
	if (t == NULL)
	{
		printf("二叉排序树的节点数为0，无法进行遍历\n");
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
