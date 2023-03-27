#pragma once
#include"LinkStack_calculate.h"

void show_1()
{
	LinkStack s;
	initLStack(&s);
	int flag;
	char box[200] = { 0 },data_1[200]={0}, data, c;//data_1只是输入的数据，data才是入栈元素数据，c为出栈元素数据
	while (1)
	{
		while (1)
		{
			flag = 0;
			system("cls");
			printf("你可以实现以下功能\n");
			printf("1.判断栈是否为空\n");
			printf("2.获取栈顶节点的数据\n");
			printf("3.压栈\n");
			printf("4.出栈\n");
			printf("5.遍历整个栈\n");
			printf("6.获取栈的长度\n");
			printf("7.清空栈\n");
			printf("8.栈的四则运算器\n");
			printf("9.销毁栈并退出\n");
			printf("请输入数字实现相应功能\n");
			scanf("%s", box);
			while (getchar() != '\n');
			if (strlen(box) != 1)
			{
				printf("请输入正确的数字!");
				system("pause");
			}
			else if (box[0] < '1' || box[0]>'9')
			{
				printf("请输入正确的数字!");
				system("pause");
			}
			else
			{
				flag = box[0] - 48;
				break;
			}
		}
		system("cls");
		switch (flag)
		{
		case(1):
			if (isEmptyLStack(&s))
				printf("栈为空!\n");
			else
				printf("栈不为空.\n");
			system("pause");
			break;
		case(2):
			if (getTopLStack(&s) != NULL)
			{
				printf("栈顶节点的数据为：%c",s.top->data);
			}
			else
				printf("队列为空!\n");
			system("pause");
			break;

		case(3):
			printf("请输入数据(仅接收一个字符若为字符串则只对第一个字符进行操作)\n");
			scanf("%s", data_1);
			data = data_1[0];
			pushLStack(&s,data);
			printf("压栈成功!\n");
			system("pause");
			break;

		case(4):
			c = popLStack(&s);
			if (c==0)
				printf("栈为空\n");
			else
				printf("出栈成功，出栈节点的数据为：%c\n",c);
			system("pause");
			break;
		case(5):
			if (traverseLSueue(&s) == false)
				printf("栈为空!\n");
			system("pause");
			break;

		case(6):
			if (LStackLength(&s) >= 0)
				printf("队列长度是：%d.\n", LStackLength(&s));
			else
			{
				printf("栈出错!!!\n");
				exit(0);
			}
			system("pause");
			break;

		case(7):
			clearLStack(&s);
			printf("栈已经清空\n");
			system("pause");
			break;

		case(8):
			calculate();
			system("pause");
			break;

		case(9):
			destroyLStack(&s);
			system("pause");
			return;
		}

	}
}