#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkStack_show.h"
#include"LinkQueue_show.h"

int main()
{
	char box[200] = { 0 };
	int flag;
	while (1)
	{
		while (1)
		{
			flag = 0;
			system("cls");
			printf("你可以实现以下功能\n");
			printf("1.对栈进行操作\n");
			printf("2.对队列进行操作\n");
			printf("3.退出程序\n");
			printf("请输入数字实现相应功能\n");
			scanf("%s", box);
			while (getchar() != '\n');
			if (strlen(box) != 1)
			{
				printf("请输入正确的数字!");
				system("pause");
			}
			else if (box[0] < '1' || box[0]>'3')
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
			show_1();
			break;
		case(2):
			show_2();
			break;
		case(3):
			return;

		}
	}
	return 0;
}