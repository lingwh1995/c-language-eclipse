#include <stdio.h>
#include <string.h>

/**
 * 题目列表
 * 1.循环打印 a-g 方式一：不使用取余运算
 * 2.循环打印 a-g 方式二：使用取余运算
 * 3.求最大公约数 方式一：暴力穷举
 *
 */

/**
 * 1.循环打印 a-g 方式一：不使用取余运算
 */
void Question_001_LoopPrintAToG()
{
	char str[] = "abcdefg";
	int i, j, k;
	int len = strlen(str);
	for(i=0; i<len; i++)
	{
		k = i;
		for(j=0; j<len; j++)
		{
			printf("%c", str[k]);
			k = k + 1;
			if(k == len) {
				k = 0;
			}
		}
		printf("\n");
	}
}

/**
 * 2.循环打印 a-g 方式二：使用取余运算
 */
void Question_002_LoopPrintAToG()
{
	char str[] = "abcdefg";
	int i, j, k;
	int len = strlen(str);
	for(i=0; i<len; i++)
	{
		k = i;
		for(j=0; j<len; j++)
		{
			printf("%c", str[k]);
			k = k + 1;
			k =  k % len;
		}
		printf("\n");
	}
}

/**
 * 3.求最大公约数 方式一：暴力穷举
 */
void Question_003_GreatestCommonDivisor()
{
	//int a, b;
	//scanf("%d %d", &a, &b);
	int a = 100, b = 38;
	int c = a<b ? a : b;
	while(!(a%c==0 && b%c==0)){
		c--;
	}
	printf("c = %d", c);
}

int main()
{
	//Question_001_LoopPrintAToG();
	//Question_002_LoopPrintAToG();
	Question_003_GreatestCommonDivisor();
	return 0;
}
