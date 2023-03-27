#pragma once
#include "LinkStack.h" 

//将中缀表达式转化为后缀表达式存到数组中

//判断是否为数字
bool isNum(char c)
{
	if (c > 73 || c < 48)//不是数字
		return false;
	return true;
}

//判断运算符符号(包括括号)
int judge_operator(char c)
{
	if (c == '+')
		return 1;//优先级
	else if (c == '-')
		return 1;//优先级
	else if (c == '*')
		return 2;//优先级
	else if (c == '/')
		return 2;//优先级
	return 0;
}

//判断是否为左括号
bool isLeft(char c)
{
	if (c == '(')
		return true;
	return false;
}


//判断是否为右括号
bool isReft(char c)
{
	if (c == ')')
		return true;
	return false;
}


//将中缀表达式变为后缀表达式
char* turn()
{
	int j = 0;
	int flag = 0;//判断有没有运算符
	char nums[100] = { 0 };//存储数字
	char str[1000] = { 0 };//中缀表达式
	LinkStack p;
	initLStack(&p);
	printf("输入中缀表达式\n");
	gets(str);
	if (strlen(str) == 0)
		return NULL;
	for (int i = 0; i < strlen(str); i++)//遍历中缀表达式每一个字符
	{
		if (str[i] == '0' && (judge_operator(str[i - 1]) == true && isNum(str[i + 1]) == true))//排除+0123这种情况
			return NULL;

		if (i == 0 && (isNum(str[i]) == false || (str[i] == '0' && isNum(str[i + 1]) == true)) && isLeft(str[i]) == false)//排除开头为a123、+123、0123等情况
			return NULL;


		if (isNum(str[i]))//是数字
		{
			if (isNum(str[i + 1]))
				nums[j++] = str[i];
			else//区分一位数，二位数等
			{
				nums[j++] = str[i];
				nums[j++] = ' ';
			}
		}

		else if (isLeft(str[i]))//左括号
			pushLStack(&p, str[i]);//直接压栈

		else if (isReft(str[i]))//右括号
		{

			while (getTopLStack(&p)->data != '(')
			{
				nums[j++] = popLStack(&p);//popLStack(&p)返回栈顶数据的首地址
				if (isEmptyLStack(&p))//没找到左括号
					return NULL;
			}


			popLStack(&p);//将左括号出栈
		}

		else if (judge_operator(str[i]) && judge_operator(str[i + 1]))//1+-2等情况
			return NULL;

		else if (str[i] == '/' && str[i + 1] == '0')//2/0等情况
			return NULL;

		else if (judge_operator(str[i]))//是运算符
		{
			flag = 1;//有运算符
			while (isEmptyLStack(&p) == 0 && (judge_operator(str[i]) <= judge_operator(getTopLStack(&p)->data)))
				//栈不为空且此时的运算符的优先级不高于栈顶运算符的优先级
				nums[j++] = popLStack(&p);//popLStack(p)返回栈顶数据的首地址
			pushLStack(&p, str[i]);//将此时的运算符压栈
		}

		else
			return NULL;
	}
	if (flag == 0)//没有运算符报错
		return NULL;
	while (isEmptyLStack(&p) == 0)//全部出栈
	{
		if (getTopLStack(&p)->data == '(')//右左括号未匹配
			return NULL;
		nums[j++] = popLStack(&p);
	}
	return nums;
}