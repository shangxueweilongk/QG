#pragma once
#include"LinkQueue.h"

char type;

//确定数据类型
void get_type()
{
	while (1)
	{
		type = '\0';
		printf("请输入你要保存的数据的类型:\n");
		printf("输入'i'则存储整型, 输入'f'则存储浮点型，输入'c'则存储字符\n");
		scanf("%c", &type);
		while (getchar() != '\n');
		if (type == 'i' || type == 'f' || type == 'c')
			break;
		else
		{
			printf("输入有误，请重新输入！\n");
			system("pause");
			system("cls");
		}
	}
}


//整型数据
void get_int(void** data)
{
	int* p = (int*)malloc(sizeof(int));
	if (p == NULL)
	{
		printf("内存分配失败，将退出程序\n");
		exit(0);
	}
	char s[50];
	int flag = 1;
	while (1)
	{
		flag = 1;//重置
		system("cls");
		printf("请输入一个整型数:\n");
		gets(s);
		if (*s == '-')
		{
			if (strlen(s) < 7 && strlen(s) > 0)//算上负号
			{
				int i;
				for (i = 1; i < 7 && s[i] != '\0'; i++)
				{
					if (s[i] < '0' || s[i]>'9')
					{
						flag = 0;
						printf("输入类型有误，请重新输入\n");
						break;
					}
				}
				if (flag == 1)
				{
					*p = 0;
					for (i = 1; i < 7 && s[i] != '\0'; i++)
						*p = (*p) * 10 + s[i] - '0';
					(*p) *= -1;
					*data = (void*)p;
					return;
				}
			}
		}
		else if (strlen(s) < 6 && strlen(s) > 0)
		{
			int i;
			for (i = 0; i < 6 && s[i] != '\0'; i++)
			{
				if (s[i] < '0' || s[i]>'9')
				{
					flag = 0;
					printf("输入类型有误，请重新输入\n");
					break;
				}
			}
			if (flag == 1)
			{
				*p = 0;
				for (i = 0; i < 6 && s[i] != '\0'; i++)
					*p = (*p) * 10 + s[i] - '0';
				*data = (void*)p;
				return;
			}
		}
		printf("请输入一个大于-10000.0且小于10000.0的数;\n");
		system("pause");
	}
}

//浮点型数据
void get_float(void** data)
{
	float* p = (float*)malloc(sizeof(float));
	if (p == NULL)
	{
		printf("内存分配失败，将退出程序\n");
		exit(0);
	}
	*p = 0.0;
	char s[50];
	int flag = 1,times=0;//times记录小数点个数
	while (1)
	{
		times = 0;
		flag = 1;//重置
		system("cls");
		printf("请输入一个浮点数\n");
		gets(s);
		if (*s == '-')
		{
			if (strlen(s) < 7 && strlen(s) > 0)//算上负号
			{
				int i, j = 0;
				for (i = 1; i < 7 && s[i] != '\0'; i++)
				{
					if (s[i] == '.')//两个小数点的情况
					{
						times++;
						if (times > 1)
						{
							flag = 0;
							printf("输入类型有误，请重新输入!\n");
							break;
						}
					}
					if ((s[i] < '0' || s[i]>'9') && (s[i] != '.'))
					{
						flag = 0;
						printf("输入类型有误，请重新输入!\n");
						break;
					}
					if (s[i] == '.' && (i == 0 || i == strlen(s) - 1))//.123、213,等错误情况
					{
						flag = 0;
						printf("输入类型有误，请重新输入!\n");
						break;
					}
					if (s[i] == '.' && s[i + 1] == '.')//1..23、2.13等错误情况
					{
						flag = 0;
						printf("输入类型有误，请重新输入!\n");
						break;
					}

				}
				if (flag == 1)
				{
					*p = 0;
					for (i = 1; i < 7 && s[i] != '\0' && s[i] != '.'; i++)
						*p = (*p) * 10 + s[i] - '0';

					if (s[i] == '.')//跳过小数点
					{
						i++;
						j = i;
					}

					for (; i < 7 && s[i] != '\0'; i++)
						*p = (*p) * 10 + s[i] - '0';

					if (j > 0)//转换成小数
					{
						for (; j < 7 && s[j] != '\0'; j++)
							*p = (*p) / 10;
					}

					(*p) *= -1;
					*data = (void*)p;
					return;
				}
			}
		}
		else if (strlen(s) < 6 && strlen(s) > 0)
		{
			int i, j = 0;
			for (i = 0; i < 6 && s[i] != '\0'; i++)
			{
				if (s[i] == '.')//两个小数点的情况
				{
					times++;
					if (times > 1)
					{
						flag = 0;
						printf("输入类型有误，请重新输入!\n");
						break;
					}
				}
				if ((s[i] < '0' || s[i]>'9') && (s[i] != '.'))
				{
					flag = 0;
					printf("输入类型有误，请重新输入!\n");
					break;
				}
				if (s[i] == '.' && (i == 0 || i == strlen(s) - 1))//.123、213,等错误情况
				{
					flag = 0;
					printf("输入类型有误，请重新输入!\n");
					break;
				}
				if (s[i] == '.' && s[i + 1] == '.')//1..23、2.13等错误情况
				{
					flag = 0;
					printf("输入类型有误，请重新输入!\n");
					break;
				}
			}
			if (flag == 1)
			{
				*p = 0;
				for (i = 0; i < 6 && s[i] != '\0' && s[i] != '.'; i++)
					*p = (*p) * 10 + s[i] - '0';

				if (s[i] == '.')//跳过小数点
				{
					i++;
					j = i;
				}

				for (; i < 6 && s[i] != '\0'; i++)
					*p = (*p) * 10 + s[i] - '0';

				if (j > 0)
				{
					for (; j < 6 && s[j] != '\0'; j++)
					{
						*p = (*p) / 10;
					}
				}

				*data = (void*)p;
				return;
			}
		}
		printf("请输入一个大于-10000.0小于10000.0的数且总位数(包括整数位和小数位以及小数点)不超过5位;\n");
		system("pause");
	}
}

//字符数据
void get_char(void** data)
{
	printf("请输入一个字符(仅支持单个字符输入，若输入字符串则只对第一个字符进行操作)\n");
	char* p = (char*)malloc(sizeof(char));
	if (p == NULL)
	{
		printf("内存分配失败，将退出程序\n");
		exit(0);
	}
	*p = 0;
	scanf("%c", p);
	while (getchar() != '\n');
	*data = (void*)(p);
}


//数据处理
void get_data(void** data)
{
	if (type == 'i')
		get_int(data);
	else if (type == 'f')
		get_float(data);
	else if (type == 'c')
		get_char(data);
}


//菜单
void show()
{
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	void* add_data = NULL;
	int flag;
	char box[200] = { 0 };
	InitLQueue(Q);
	while (1)
	{
		while (1)
		{
			flag = 0;
			system("cls");
			printf("你可以实现以下功能\n");
			printf("1.判断队列是否为空\n");
			printf("2.获取首节点的数据\n");
			printf("3.入！队！\n");
			printf("4.出！队！\n");
			printf("5.遍历整个队列\n");
			printf("6.获取队列长度\n");
			printf("7.清空队列\n");
			printf("8.销毁队列并退出\n");
			printf("请输入数字实现相应功能\n");
			scanf("%s", box);
			while (getchar() != '\n');
			if (strlen(box) != 1)
			{
				printf("请输入正确的数字!");
				system("pause");
			}
			else if (box[0] < '1' || box[0]>'8')
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
			if (IsEmptyLQueue(Q))
				printf("队列为空!\n");
			else
				printf("队列不为空.\n");
			system("pause");
			break;
		case(2):
			if (GetHeadLQueue(Q) != NULL)
			{
				printf("首节点的数据为：");
				LPrint(GetHeadLQueue(Q), type);
			}
			else
				printf("队列为空!\n");
			system("pause");
			break;

		case(3):
			if (type == 'i')
				get_int(&add_data);
			else if (type == 'f')
				get_float(&add_data);
			else
				get_char(&add_data);

			EnLQueue(Q, add_data);
			printf("入队成功!\n");
			system("pause");
			break;

		case(4):
			if (DeLQueue(Q))
				printf("出队成功\n");
			else
				printf("队列为空!\n");
			system("pause");
			break;
		case(5):
			if (TraverseLQueue(Q, type) == false)
				printf("队列为空!\n");
			system("pause");
			break;

		case(6):
			if (LengthLQueue(Q) >= 0)
				printf("队列长度是：%d.\n", LengthLQueue(Q));
			else
			{
				printf("队列出错!!!\n");
				exit(-1);
			}
			system("pause");
			break;

		case(7):
			ClearLQueue(Q);
			system("pause");
			break;

		case(8):
			DestoryLQueue(Q);
			free(Q);
			system("pause");
			return;
		}
	}
}


void show_2()
{
	get_type();
	show();
	return ;
}
