#include <stdio.h>
#include <stdbool.h>

/**
 * 章节内容:
 *   C语言数据类型
 *     1.基本数据类型：
 *       整型数据类型：short、int、long、long long
 *       字符数据类型：char
 *       浮点型数据类型：float、double
 *       布尔类型：0/false、 1、true
 *     2.构造数据类型
 *		 数组(Array)：一组相同类型元素的集合，可以是一维或多维。
 *		 结构体(Struct)：允许将不同类型的数据组合在一起，每个成员拥有独立的内存空间。
 *		 联合体(Union)：所有成员共享同一块内存空间，同一时间只能存储一种类型的数据。
 *		 ‌枚举(Enum)：用于定义一组命名的整数常量。
 *	   3.指针类型
 *	   	 指针(Pointer)：指向特定类型数据的指针，用于存储变量的内存地址，如int *p表示指向整数的指针。
 *	   4.空类型
 *	   	 void‌：表示没有类型，通常用于函数返回值、函数参数或通用指针。
 *
 */

/**
 * 定义一个结构体Person
 */
struct Student
{
	// 学生id
	int id;
	// 学生姓名
	char name[20];
	// 学生年龄
	int age;
};

/**
 * 颜色枚举
 */
enum Color
{
	RED,	//默认为 0
	GREEN,	//默认为 1
	BLUE	//默认为 2
};
/**
 * 打印颜色
 *   使用枚举约束了case后面的值
 */
void printColor(enum Color color) {
    switch (color) {
        case RED:
            printf("红色\n");
            break;
        case GREEN:
            printf("绿色\n");
            break;
        case BLUE:
            printf("蓝色\n");
            break;
        default:
            printf("参数不合法\n");
    }
}

int main()
{
	// 整型数据类型
    printf("short类型所占字节大小: %d\n", sizeof(short));
    printf("int类型所占字节大小: %d\n", sizeof(int));
    printf("long类型所占字节大小: %d\n", sizeof(long));
    printf("long long类型所占字节大小: %d\n", sizeof(long long));
    printf("-------------------------------------\n");


    // 字符数据类型
    printf("char类型所占字节大小: %d\n", sizeof(char));
    printf("-------------------------------------\n");


    // 浮点型数据类型
    printf("float类型所占字节大小: %d\n", sizeof(float));
    printf("double类型所占字节大小: %d\n", sizeof(double));
    printf("-------------------------------------\n");


    // 使用bool类型,C99中要引用 stdbool.h
    printf("bool类型所占字节大小: %d\n", sizeof(bool));
    printf("-------------------------------------\n");


    // 数组(Array)
    int nums[] = { 10, 20, 30 };
	int i;
	int size = sizeof(nums)/sizeof(nums[0]);
    for(i=0; i<size; i++)
    {
    	printf("%d ",nums[i]);
    }
    printf("\n");
    printf("-------------------------------------\n");


    // 结构体(Struct)
    struct Student alice = { 1,"Alice",18 };
    struct Student bob = { 2,"Bob",23 };
    struct Student studentArr[] = {
    		alice,
    		bob,
    		{ 3,"Charile",29 }
    };
    size = sizeof(studentArr)/sizeof(studentArr[0]);
    for(i=0; i<size; i++)
    {
    	printf("学生编号：%d,学生姓名：%s,学生年龄：%d\n", studentArr[i].id, studentArr[i].name, studentArr[i].age);
    }
    printf("-------------------------------------\n");


    // 枚举(Enum)
    enum Color color = RED;
    printf("%d\n", color);
    printColor(color);
    // 注意：枚举可以像整型数组一样使用
    for(i=RED; i<=BLUE; i++)
    {
    	printf("%d\n", i);
    }
    printf("-------------------------------------\n");

    // 指针
    int a = 100;
    printf("a的地址 = %p\n", &a);
    int arr[5] = { 1,2,3,4,5 };
    //数组的地址
    printf("数组的地址 = %p\n", &arr);
    printf("-------------------------------------\n");
    return 0;
}
