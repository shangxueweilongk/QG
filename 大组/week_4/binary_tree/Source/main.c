#define _CRT_SECURE_NO_WARNINGS 1
#include"bst_1.h"


int turn()//将字符串转为整数
{
	printf("请输入相应操作的数字(1000以内的正整数)\n");
	while (1)
	{
		int num = 0,flag=1;
		char str[1000] = { 0 };
		scanf("%s", str);
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] < '0' || str[i]>'9')
			{
				flag = 0;
				break;
			}
			num = num * 10 + str[i] - 48;
		}
		if (flag == 1 && num<=1000 && num>=0)
			return num;
		printf("输入格式有误请重新输入\n");
	}
}

int main()
{
	int flag,num;
	char box[200] = { 0 };
	bst* t = NULL;//二叉排序树的初始化
	while (1)
	{
		while (1)
		{
			flag = 0;
			system("cls");
			printf("1.二叉排序树的插入\n");
			printf("2.二叉排序树的删除\n");
			printf("3.二叉排序树的查找\n");
			printf("4.二叉排序树的前序遍历\n");
			printf("5.二叉排序树的中序遍历\n");
			printf("6.二叉排序树的后序遍历\n");
			printf("7.二叉排序树的层序遍历\n");
			printf("8.退出\n");
			printf("请输入数字完成相应操作\n");
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
			num = turn();
			bst_insert(&t, num);
			system("pause");
			break;
		case(2):
			num = turn();
			bst_delete(&t, num);
			system("pause");
			break;

		case(3):
			num = turn();
			bst_search(t, num);
			system("pause");
			break;

		case(4):
			printf("前序遍历(递归)：\n");
			bst_pretraverse_1(t);
			printf("\n");
			printf("前序遍历(非递归)：\n");
			bst_pretraverse_2(t);
			system("pause");
			break;
		case(5):
			printf("中序遍历(递归)：\n");
			bst_intraverse_1(t);
			printf("\n");
			printf("中序遍历(非递归)：\n");
			bst_intraverse_2(t);
			system("pause");
			break;

		case(6):
			printf("后序遍历(递归)：\n");
			bst_posttraverse_1(t);
			printf("\n");
			printf("后序遍历(非递归)：\n");
			bst_posttraverse_2(t);
			system("pause");
			break;

		case(7):
			printf("层序遍历：\n");
			bst_leveltraverse(t);
			system("pause");
			break;

		case(8):
			return;
		}
	}
	return 0;
}