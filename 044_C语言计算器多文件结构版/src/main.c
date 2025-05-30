#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "calculator.h"


//使用多文件结构(模块化设计)编写计算器程序:测试部分
int main()
{
	printf("请输入表达式: a op b\n");
	int a = 0, b = 0;
	char op = '\0';
	char ch = '\0';
	do
	{
		scanf("%d %c %d", &a, &op, &b); // 1 + 5\n
		Calc(a, b, op);
		printf("输入y/Y继续:\n");
		//Visual Studio中可以使用这个函数清空stdin缓冲区
		rewind(stdin);
		ch = getchar();
	} while (ch == 'y' || ch == 'Y');

	return 0;
}

//指针
#if 0
int main()
{
	const int c = 30;
	int* pc = &c;
	*pc = 300;
	printf("c = %d\n", c);

	return 0;
}
#endif // 0

//测试多文件结构
#if 0
int main()
{
	fun1();
	fun2();
	return 0;
}
#endif // 0