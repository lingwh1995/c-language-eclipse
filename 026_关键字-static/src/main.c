#include <stdio.h>

/**
 * static关键字:
 *  1.被static修饰的局部变量,生存期是从程序开始调用方法一直到程序结束运行,而且只会被初始化一次
 *  2.含有静态变量的函数,称为记忆函数
 *  3.被static修饰的局部变量,作用域没有改变,生存期发生了改变
 *  4.被static修饰的全局变量和函数,作用域受到限制,只在本文件中有效,在其他文件中使用extern声明,虽然可以通过编译,但
 *      是无法正常调用,生存期不会改变，详细见 mylib.h、mylib.c、main_01.c         
 */


/*
 * 普通函数
 */
void OrdinaryFunctionTest()
{
	// 定义一个普通变量a,本方法每次调用时变量a都会被初始化
    int a = 0;
    // 定义一个普通变量b,本方法每次调用时变量b都会被初始化
    int b = 0;
    a++;
    b++;
    printf("a = %d,b = %d\n", a, b);
}

/*
 * 记忆函数
 */
void MemoryFunctionTest()
{
	// 定义一个普通变量a,本方法每次调用时变量a都会被初始化
    int a = 0;
    // 定义一个静态变量b,只有本方法第一次调用时变量b都会被初始化,且b变量的生存期一直到程序结束运行
    static int b = 0;
    a++;
    b++;
    printf("a = %d,b = %d\n", a, b);
}

#if 0
int main()
{
    for (int i = 0; i < 5; i++)
    {
    	//OrdinaryFunctionTest();
        MemoryFunctionTest();
    }
    return 0;
}
#endif
