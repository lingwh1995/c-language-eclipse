#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/**
 * 章节内容:
 *      结构体变量,因为结构体是变量,所以可以使用下面形式
 *      定义一个全局结构体变量的两种方法
 *      方式一:
 *          struct Student {
 *              char id[32];
 *              char name[50];
 *              int age;
 *          }Stud;
 *      方式二:
 *          struct Student {
 *              char id[32];
 *              char name[50];
 *              int age;
 *          };
 *      struct Student Stud;
 *
 *      注意:
 *          1.结构体可以理解为是属性的集合
 *          2.结构体可以定义在主函数之外,也可以定义在主函数之内
 *          3.全局结构体默认是公有的,这意味着所有的方法都可以修改结构体变量中属性的值,而且在一个方法中给属性赋值
 *           之后,在另一个方法中也可以获取到该变量修改后的的值
 */

/**
* 定义结构体和定义结构体变量:
*  方式一: 先定义结构体,再定义结构体变量
*/
//下面struct默认是全局的,因为定义在main()方法之外
struct Student
{
    char id[32];
    char name[50];
    int age;
};
// 错误定义结构体(下面一行代码放开会报错,因为没有在变量前加struct)
//Student student_g;
// 正确定义结构体，此处定义的结构体变量为全局变量
struct Student student_g;

/**
 * 定义结构体和定义结构体变量:
 *  方式二: 定义结构体的同时定义结构体变量
 */
 // 下面struct默认是全局的,因为定义在main()方法之外
struct User
{
    char id[32];
    char name[50];
    int age;
} user_g, * pUser_g; //结构体变量,此处定义的结构体变量为全局变量,这里甚至可以直接初始化结构体变量

/**
 * 测试在其他方法中使用全局结构体变量
 */
void GolbalStructTest()
{
    // 为什么这里可以使用user_g这个结构体变量?因为这个结构体变量是全局的,相当于是公共的,一个方法中赋值,其他方法中也可以获取到值
    printf("测试在其他方法中使用全局结构体,user_g.age = %d\n", user_g.age);
}

int main()
{    
    /**
     * 测试方式一定义的结构体
     */      
    // 全局结构体部分
        // 定义结构体并初始化(定义一个全局结构体)
    //struct User user_g = {"001","张三",20};

    // 定义结构体并初始化(定义一个局部结构体)
    struct Student student = { "001","张三",20 };
    // 访问结构体成员变量方式一：普通方法访问结构体成员变量
    printf("id:%s\n", student.id);
    printf("name:%s\n", student.name);
    printf("age:%d\n", student.age);
    printf("------------------------------\n");

    // 访问结构体成员变量方式二：使用指针访问结构体成员变量
    struct Student* pStudent = &student;
    printf("id:%s\n", (*pStudent).id);
    printf("name:%s\n", (*pStudent).name);
    printf("age:%d\n", (*pStudent).age);
    printf("------------------------------\n");

    // 访问结构体成员变量方式三：指针箭头访问结构体成员变量,注意: 使用箭头访问: 前面不需要加*
    printf("id:%s\n", pStudent->id);
    printf("name:%s\n", pStudent->name);
    printf("age:%d\n", pStudent->age);

    printf("------------------------------\n");

    /**
     * 测试方式二定义的结构体
     */
    // 给数组类型变量赋值使用strcpy()函数
    strcpy(user_g.id, "002");
    strcpy(user_g.name, "lisi");
    user_g.age = 20;

    // 测试在其他方法中使用全局结构体变量
    GolbalStructTest();

    // 普通方法访问结构体成员变量
    printf("id:%s\n", user_g.id);
    printf("name:%s\n", user_g.name);
    printf("age:%d\n", user_g.age);

    // 使用指针访问结构体成员变量
    pUser_g = &user_g;
    printf("id:%s\n", (*pUser_g).id);
    printf("name:%s\n", (*pUser_g).name);
    printf("age:%d\n", (*pUser_g).age);

    // 指针箭头访问结构体成员变量,注意: 使用箭头访问: 前面不需要加*
    printf("id:%s\n", pUser_g->id);
    printf("name:%s\n", pUser_g->name);
    printf("age:%d\n", pUser_g->age);
    printf("------------------------------\n");


    /**
     * 定义一个局部结构体
     */
    struct Person
    {
        char id[32];
        char name[32];
        int age;
    };
    // 定义一个结构体变量
    struct Person person = { "003","wangwu",36 };
    // 普通方法访问结构体成员变量
    printf("id:%s\n", person.id);
    printf("name:%s\n", person.name);
    printf("age:%d\n", person.age);

    // 使用指针访问结构体成员变量
    struct Person* pPerson = &person;
    printf("id:%s\n", (*pPerson).id);
    printf("name:%s\n", (*pPerson).name);
    printf("age:%d\n", (*pPerson).age);

    // 指针箭头访问结构体成员变量,注意: 使用箭头访问: 前面不需要加*
    printf("id:%s\n", pPerson->id);
    printf("name:%s\n", pPerson->name);
    printf("age:%d\n", pPerson->age);
    printf("------------------------------\n");
}
