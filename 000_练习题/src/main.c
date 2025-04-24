#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * 题目列表
 * 1.循环打印 a-g 方式一：不使用取余运算
 * 2.循环打印 a-g 方式二：使用取余运算
 * 3.求最大公约数 方式一：暴力穷举
 * 4.求最大公约数 方式二：辗转相除法
 * 5.求最大公约数 方式三：更相减损术(辗转相减法)
 * 6.求最小公倍数 方式一：暴力穷举
 * 7.求最小公倍数 方式二：利用最大公约数
 * 8.求最小公倍数 方式三：最小i值法
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
 * 		a.找出a和b中最小的数，把这个数赋值给c
 * 		b.第一个满足 a%c==0 && b%c==0 的数就是a和b的最大公约数
 */
void Question_003_GreatestCommonDivisor()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int c = a<b ? a : b;
	while(c>1)
	{
		if(a%c==0 && b%c==0)
		{
			break;
		}
		c--;
	}
	printf("最大公约数 = %d", c);
}

/**
 * 4.求最大公约数 方式二：辗转相除法
 * 		公式：gcd(a,b) = gcd(b, a mod b);
 */
void Question_004_GreatestCommonDivisor()
{
	int a, b, mod;
	scanf("%d %d", &a, &b);
	while(mod != 0) {
		mod = a % b;
		a = b;
		b = mod;
	}
	printf("最大公约数 = %d",a);
}

/**
 * 5.求最大公约数 方式三：更相减损术(辗转相减法)
 * 		公式：gcd(a, b) = gcd(b, a - b);
 * 		注意：a<b时，要先交换a、b两个数的位置再进行相减
 */
void Question_005_GreatestCommonDivisor()
{
	int a, b, diff;
	scanf("%d %d", &a, &b);
	while(diff != 0) {
        if(a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
		diff = a - b;
		a = b;
		b = diff;
	}
	printf("最大公约数 = %d",a);
}

/**
 * 6.求最小公倍数 方式一：暴力穷举
 */
void Question_006_LeastCommonMultiple()
{
	int a, b, lcm;
	scanf("%d %d", &a, &b);
	lcm = a > b ? a : b;
	while(true)
	{
		if(lcm%a==0 && lcm%b==0)
		{
			break;
		}
		++lcm;
	}
	printf("最小公倍数 = %d", lcm);
}

/**
 * 7.求最小公倍数 方式二：利用最大公约数 int lcm = a*b / gcd(a,b)
 */
int gcd(int a, int b)
{
	int mod;
	while(mod != 0) {
		mod = a % b;
		a = b;
		b = mod;
	}
	return a;
}
void Question_007_LeastCommonMultiple()
{
	int a, b, lcm;
	scanf("%d %d", &a, &b);
	lcm = a*b / gcd(a,b);
	printf("最小公倍数 = %d", lcm);
}

/**
 * 8.求最小公倍数 方式三：最小i值法
 */
void Question_008_LeastCommonMultiple()
{
	int a, b, lcm;
	scanf("%d %d", &a, &b);
	int i = 1;
	while(a*i % b != 0)
	{
		i++;
	}
	lcm = a * i;
	printf("最小公倍数 = %d", lcm);
}

int main()
{
	//Question_001_LoopPrintAToG();
	//Question_002_LoopPrintAToG();
	//Question_003_GreatestCommonDivisor();
	//Question_004_GreatestCommonDivisor();
	//Question_005_GreatestCommonDivisor();
	//Question_006_LeastCommonMultiple();
	//Question_007_LeastCommonMultiple();
	Question_008_LeastCommonMultiple();
	return 0;
}
