#include <stdio.h>

//错误定义
//#define SUM(x,y) x*y
//正确定义
#define SUM(x,y) (x)*(y)

/**
 * 宏定义: 宏定义的变量会在预编译的时候替换,不会开辟空间,也没有类型,不会进行类型检查
 * 宏的根本特性: 展开,所以定义宏参时要用括号括起来
 */

int main()
{
    //测试宏参
    int a = 2;
    int b = 3;
    int c = SUM(a, b);
    printf("c = %d\n", c);
    int d = SUM(a + 5, b + 5);
    // int d = a + 5 * b + 5
    printf("d = %d\n", d);
    return 0;
}
