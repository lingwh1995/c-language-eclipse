#include <stdio.h>

/**
 * sizeof:返回一个无符号的整型数据
 */

int main()
{
    int a = 10;
    //指针类型的数据在32位系统下占4个字节,64位系统下占8个字节
    char* cp = NULL;
    double* dp = NULL;
    char str[10];
    int arr[10];
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(cp));
    printf("%d\n", sizeof(dp));
    printf("%d\n", sizeof(str));
    printf("%d\n", sizeof(double*));
    //字符串(字符数组)类型末尾有一个额外的\0,会多占据一个字节
    printf("%d\n", sizeof("ufe"));
    printf("%d\n", sizeof(arr));
	return 0;
}