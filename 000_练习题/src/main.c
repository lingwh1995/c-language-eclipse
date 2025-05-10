#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * 题目列表
 * 001.循环打印 a-g 方式一：不使用取余运算
 * 002.循环打印 a-g 方式二：使用取余运算
 * 003.求最大公约数 方式一：暴力穷举
 * 004.求最大公约数 方式二：辗转相除法
 * 005.求最大公约数 方式三：更相减损术(辗转相减法)
 * 006.求最小公倍数 方式一：暴力穷举
 * 007.求最小公倍数 方式二：利用最大公约数
 * 008.求最小公倍数 方式三：最小i值法
 * 009.输入三个整型数据，求最小值
 * 010.输入三个整型数据，求中间值
 * 011.输入三个整型数据，求最大值
 * 012.统计字符串中一共有多少个单词
 */

/**
 * 001.循环打印 a-g 方式一：不使用取余运算
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
 * 002.循环打印 a-g 方式二：使用取余运算
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
 * 003.求最大公约数 方式一：暴力穷举
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
 * 004.求最大公约数 方式二：辗转相除法
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
 * 005.求最大公约数 方式三：更相减损术(辗转相减法)
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
 * 006.求最小公倍数 方式一：暴力穷举
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
 * 007.求最小公倍数 方式二：利用最大公约数 int lcm = a*b / gcd(a,b)
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
 * 008.求最小公倍数 方式三：最小i值法
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

/**
 * 009.输入三个整型数据，求最小值
 */ 
void Question_009_GetMinValue()
{
	printf("请输入三个整型数据，使用空格分隔:\n");
	int a, b, c, min;
	scanf("%d %d %d", &a, &b, &c);
	min = a < b ? a : b;
	min = min < c ? min : c;
	printf("min = %d\n", min);
}

/**
 * 010.输入三个整型数据，求中间值
 */ 
void Question_010_GetMidValue()
{
	printf("请输入三个整型数据，使用空格分隔:\n");
	int a, b, c, min, mid, max;
	scanf("%d %d %d", &a, &b, &c);
	// 求出三个数里面最小值
	min = a < b ? a : b;
	min = min < c ? min : c;
	// 求出三个数里面最大值
	max = a > b ? a : b;
	max = max > c ? max : c;
	mid = a + b + c - min - max;
	printf("mid = %d\n", mid);
}

/**
 * 011.输入三个整型数据，求最大值
 */ 
void Question_011_GetMaxValue()
{
	printf("请输入三个整型数据，使用空格分隔:\n");
	int a, b, c, max;
	scanf("%d %d %d", &a, &b, &c);
	max = a > b ? a : b;
	max = max > c ? max : c;
	printf("max = %d\n", max);
}

/**
 * 012.统计字符串中一共有多少个单词
 */ 
void Question_012_CountWord()
{
	char str[] = " one  two   three    four     five ";
    int i, j, c = 0;
    c = str[0] == ' ' ? 0 : 1;
    for(i=0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ')
        {
            if(j == 0)
            {
                c++;
            }
            j++;
        }
        else
        {
            j = 0;
        }
    }
    printf("单词个数 = %d\n", c);
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
	//Question_008_LeastCommonMultiple();
	//Question_009_GetMinValue();
	//Question_010_GetMidValue();
	//Question_011_GetMaxValue();
	Question_012_CountWord();
	return 0;
}
