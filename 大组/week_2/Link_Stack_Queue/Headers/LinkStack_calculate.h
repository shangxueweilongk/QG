#pragma once

//对后缀表达式进行运算
#include"LinkStack_turn.h"

int operate(char c, int x, int y)
{
	if (c == '+')
		return(x + y);
	else if (c == '-')
		return(x - y);
	else if (c == '*')
		return(x * y);
	else if (c == '/')
	{
		if (y == 0)//
		{
			printf("计算式中分母为0，将退出程序\n");
			exit(0);
		}
		return(x / y);
	}

}

void calculate()
{
	char* nums_1 = turn();//接收
	if (nums_1 == NULL)
	{
		printf("中缀表达式有误,请重新输入(仅支持非负整数间的运算且不允许使用空格将表达式隔开)\n");
		return ;
	}
	LinkStack p;
	initLStack(&p);
	for (int i = 0; i < strlen(nums_1); i++)//遍历
	{
		if (isNum(nums_1[i]))
		{
			int sum = 0;
			for (; isNum(nums_1[i]); i++)
				sum = nums_1[i] - 48 + sum * 10;
			pushLStack_1(&p, sum);
		}
		if (judge_operator(nums_1[i]))
		{
			pushLStack_1(&p, operate(nums_1[i], popLStack_1(&p), popLStack_1(&p)));
		}
	}
	if (abs(getTopLStack(&p)->result) > 100000)//溢出
		printf("表达式结果过大(小)可能导致溢出，无法计算\n");
	else
		printf("结果为(向下取整)：%d\n", getTopLStack(&p)->result);
}
