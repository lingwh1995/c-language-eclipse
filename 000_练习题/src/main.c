#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

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
 * 013.小球从100米落下,每次落地后跳回原来的高度一半，再落下，求它在第10次落下时共经过多少米?反弹高度是多少?
 * 014.有一对兔子，从出生后第三个月起每个月都生一对兔子，小兔子长到第三个月后又生一对兔子，假如兔子都不死，问每个月有多少对兔子?（递归求解）
 * 015.有一对兔子，从出生后第三个月起每个月都生一对兔子，小兔子长到第三个月后又生一对兔子，假如兔子都不死，问每个月有多少对兔子?（非递归求解）
 * 016.牛顿迭代法求平方根，要求两次求出的平方根的差的绝对值小于0.00001
 * 017.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数
 * 018.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数和该完数的因数（方式一）
 * 019.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数和该完数的因数（方式二）
 * 020.打印九九乘法表
 */

/**
 * 001.循环打印 a-g 方式一：不使用取余运算
 */
void Question_001_LoopPrintAToG()
{
	char str[] = "abcdefg";
	int len = strlen(str);
	for(int i=0; i<len; i++)
	{
		int k = i;
		for(int j=0; j<len; j++)
		{
			printf("%c", str[k]);
			k = k + 1;
			if(k == len)
			{
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
	int len = strlen(str);
	for(int i=0; i<len; i++)
	{
		int k = i;
		for(int j=0; j<len; j++)
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
	while(mod != 0)
	{
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
	while(diff != 0)
	{
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
	while(mod != 0)
	{
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
    int j;
    int c = str[0] == ' ' ? 0 : 1;
    for(int i=0; str[i] != '\0'; i++)
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

/**
 * 013.小球从100米落下,每次落地后跳回原来的高度一半，再落下，求它在第10次落下时共经过多少米?反弹高度是多少?
 */
void Question_013_BallFalls()
{
    //下落经过的总高度
    double sumHeight = 100.00;
    //每一次的反弹高度
    double currentJumpHeight = sumHeight / 2;
    for (int i = 2; i <= 10; i++)
    {
        sumHeight = sumHeight + currentJumpHeight * 2;
        currentJumpHeight = currentJumpHeight / 2;
    }
    printf("经过的总高度 sumHeight = %f\n", sumHeight);
    printf("第10次反弹高度 currentJumpHeight = %f\n", currentJumpHeight);
}

/**
 * 递归求解
 * 014.有一对兔子，从出生后第三个月起每个月都生一对兔子，小兔子长到第三个月后又生一对兔子，假如兔子都不死，问每个月有多少对兔子?
 * 月份     1       2       3       4       5       6       7       8
 * 对数     1       1       2       3       5       8       13      21
 */
int RabbitCount(int m)
{
	if(m == 1 || m == 2)
	{
		return 1;
	}
	return RabbitCount(m-1) + RabbitCount(m-2);
}

void Question_014_RabbitCount_Recursion()
{
	int m = 8;
	int totalRabbit = RabbitCount(m);
	printf("第%d个月兔子总数 = %d\n", m, totalRabbit);
}

/**
 * 非递归求解
 * 015.有一对兔子，从出生后第三个月起每个月都生一对兔子，小兔子长到第三个月后又生一对兔子，假如兔子都不死，问每个月有多少对兔子?
 * 月份     1       2       3       4       5       6       7       8
 * 对数     1       1       2       3       5       8       13      21
 */
void Question_015_RabbitCount_No_Recursion()
{
    //c代表后续月份兔子个数
    int a = 1, b = 1, c = 1, m = 10;
    for (int i = 3; i <= m; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    printf("第%d个月的兔子对数 = %d\n", m, c);
}

/**
 * 016.牛顿迭代法求平方根，要求两次求出的平方根的差的绝对值小于0.00001
 */
void Question_016_NewtonRaphson_Method_Sqrt()
{
	double d = 4.0;
	double x0 = d / 2;
	double x1 = (x0 + d/x0) / 2;
	while(fabs(x0-x1) > 0.00001)
	{
		x0 = x1;
		x1 = (x0 + d/x0) / 2;
	}
	printf("%f的平方根是 = %f", d, x1);
}

/**
 * 017.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数
 */
void Question_017_PerfectNumber()
{
    int n = 1000;
    for (int i = 2; i <= n; i++)
    {
        int sum = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                sum = sum + j;
            }
        }
        if (sum == i)
        {
            printf("%d\n", i);
        }
    }
}

/**
 * 018.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数和该完数的因数（方式一）
 */
void Question_018_PerfectNumberFactor()
{
    int n = 1000;
    for (int i = 2; i <= n; i++)
    {
        int sum = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                sum = sum + j;
            }
        }
        if (sum == i)
        {
            printf("%d => ", i);
            for (int x = 1; x <= i/2; x++)
            {
                if (i % x == 0)
                {
                    printf("%d ", x);
                }
            }
            printf("\n");
        }
    }
}

/**
 * 019.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数和该完数的因数（方式二）
 */
void Question_019_PerfectNumberFactor()
{
    int n = 1000;
    for (int i = 2; i <= n; i++)
    {
        int sum = 1;
        int factor[30] = {1};
        int index = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                sum = sum + j;
                factor[index++] = j;
            }
        }
        if (sum == i)
        {
            printf("%d => ", i);
            for (int x = 0; x < index; x++)
            {
            	printf("%d ", factor[x]);
            }
            printf("\n");
        }
    }
}

/**
 * 020.打印九九乘法表
 */
void Question_020_MultiplicationTable()
{
	for(int i=1; i<=9; i++)
	{
		for(int j=1; j<=i; j++)
		{
			printf("%d * %d =%3d\t", j, i, i*j);
		}
		printf("\n");
	}
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
	//Question_012_CountWord();
	//Question_013_BallFalls();
	//Question_014_RabbitCount_Recursion();
	//Question_015_RabbitCount_No_Recursion();
	//Question_016_NewtonRaphson_Method_Sqrt();
	//Question_017_PerfectNumber();
	//Question_018_PerfectNumberFactor();
	//Question_019_PerfectNumberFactor();
	Question_020_MultiplicationTable();
	return 0;
}
