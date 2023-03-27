#pragma once
#include "LinkStack.h" 

//����׺���ʽת��Ϊ��׺���ʽ�浽������

//�ж��Ƿ�Ϊ����
bool isNum(char c)
{
	if (c > 73 || c < 48)//��������
		return false;
	return true;
}

//�ж����������(��������)
int judge_operator(char c)
{
	if (c == '+')
		return 1;//���ȼ�
	else if (c == '-')
		return 1;//���ȼ�
	else if (c == '*')
		return 2;//���ȼ�
	else if (c == '/')
		return 2;//���ȼ�
	return 0;
}

//�ж��Ƿ�Ϊ������
bool isLeft(char c)
{
	if (c == '(')
		return true;
	return false;
}


//�ж��Ƿ�Ϊ������
bool isReft(char c)
{
	if (c == ')')
		return true;
	return false;
}


//����׺���ʽ��Ϊ��׺���ʽ
char* turn()
{
	int j = 0;
	int flag = 0;//�ж���û�������
	char nums[100] = { 0 };//�洢����
	char str[1000] = { 0 };//��׺���ʽ
	LinkStack p;
	initLStack(&p);
	printf("������׺���ʽ\n");
	gets(str);
	if (strlen(str) == 0)
		return NULL;
	for (int i = 0; i < strlen(str); i++)//������׺���ʽÿһ���ַ�
	{
		if (str[i] == '0' && (judge_operator(str[i - 1]) == true && isNum(str[i + 1]) == true))//�ų�+0123�������
			return NULL;

		if (i == 0 && (isNum(str[i]) == false || (str[i] == '0' && isNum(str[i + 1]) == true)) && isLeft(str[i]) == false)//�ų���ͷΪa123��+123��0123�����
			return NULL;


		if (isNum(str[i]))//������
		{
			if (isNum(str[i + 1]))
				nums[j++] = str[i];
			else//����һλ������λ����
			{
				nums[j++] = str[i];
				nums[j++] = ' ';
			}
		}

		else if (isLeft(str[i]))//������
			pushLStack(&p, str[i]);//ֱ��ѹջ

		else if (isReft(str[i]))//������
		{

			while (getTopLStack(&p)->data != '(')
			{
				nums[j++] = popLStack(&p);//popLStack(&p)����ջ�����ݵ��׵�ַ
				if (isEmptyLStack(&p))//û�ҵ�������
					return NULL;
			}


			popLStack(&p);//�������ų�ջ
		}

		else if (judge_operator(str[i]) && judge_operator(str[i + 1]))//1+-2�����
			return NULL;

		else if (str[i] == '/' && str[i + 1] == '0')//2/0�����
			return NULL;

		else if (judge_operator(str[i]))//�������
		{
			flag = 1;//�������
			while (isEmptyLStack(&p) == 0 && (judge_operator(str[i]) <= judge_operator(getTopLStack(&p)->data)))
				//ջ��Ϊ���Ҵ�ʱ������������ȼ�������ջ������������ȼ�
				nums[j++] = popLStack(&p);//popLStack(p)����ջ�����ݵ��׵�ַ
			pushLStack(&p, str[i]);//����ʱ�������ѹջ
		}

		else
			return NULL;
	}
	if (flag == 0)//û�����������
		return NULL;
	while (isEmptyLStack(&p) == 0)//ȫ����ջ
	{
		if (getTopLStack(&p)->data == '(')//��������δƥ��
			return NULL;
		nums[j++] = popLStack(&p);
	}
	return nums;
}