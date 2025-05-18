//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

/**
 * 自增运算符
 * i++ : 先用后+
 * ++i : 先加后用
 */
void IncrementOperator()
{
	// i++
	int i = 10;
    printf("i: %d\n", i++);

    // ++i
    i = 10;
    printf("i: %d\n", ++i);
}

/**
 * 三目运算符
 */
void TernaryConditionalOperator()
{
	int a, b, max;
	scanf("%d %d", &a, &b);
	max = a > b ? a : b;
	printf("max = %d\n", max);
}

/* 
 * 加等运算符
 */
void AddEqualOperator()
{
	int nums[] = { 1,2,3,4,5 };
	int len = sizeof(nums) / sizeof(nums[0]);
	int sum = 0 ;
	for (int i=0; i<len; i++)
	{
		sum += nums[i];
	}
	printf("sum = %d\n", sum);
}

/*
 * 乘等运算符
 */
void MultiplyEqualOperator()
{
	int nums[] = { 1,2,3,4,5 };
	int len = sizeof(nums) / sizeof(nums[0]);
	int sum = 1;
	for (int i = 0; i < len; i++)
	{
		sum *= nums[i];
	}
	printf("sum = %d\n", sum);
}

/**
 * 取余运算符
 */
void ModOperator()
{
	int i;
	for (i = 0; i < 100; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%4d", i);
	}


	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 1)
		{
			printf("\n");
		}
		printf("%4d", i);
	}
}

int main()
{
	//IncrementOperator();
	//TernaryConditionalOperator();
	AddEqualOperator();
	//MultiplyEqualOperator();
	//ModOperator();
}
