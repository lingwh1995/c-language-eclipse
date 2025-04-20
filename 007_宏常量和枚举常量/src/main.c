# include <stdio.h>
//定义一个宏常量,预编译之后会被替换掉
#define PI 3.14f

/**
 * 章节内容:
 *      1.宏常量和枚举常量
 *          宏常量: 定义宏常量时最后面不要加分号
 *          枚举常量:
 */


int main()
{
    /**
     * 宏常量
     */
     // 打印宏常量
    printf("宏定义的常量PI = %f\n", PI);
    printf("-----------------------\n");

    /**
     * 枚举常量(枚举也是一种常量)
     *  注意:枚举常量的值只能是整形数据
     */
    enum sex
    {
        MALE,//男性
        FEMALE,//女性
        SECRET//保密
    };
    printf("MALE = %d\n", MALE);
    printf("FEMALE = %d\n", FEMALE);
    printf("SECRET = %d\n", SECRET);

    enum week
    {
        MON = 1,
        TUE = 2,
        WED = 3
    };
    enum week wk;
    wk = MON;
    printf("wk = %d\n", wk);
    wk = TUE;
    printf("wk = %d\n", wk);

    enum animal
    {
        DOG = 5,
        CAT,
        SHEEP
    };
    printf("DOG = %d\n", DOG);
    printf("CAT = %d\n", CAT);
    printf("SHEEP = %d\n", SHEEP);
    return 0;
}
