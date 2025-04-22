#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
 * 单分支
 *	if else
 * 多分支
 *  switch
 * 三元表达式
 */

/*
 * 单分支测试
 */
void SingleBranchTest()
{
    printf("请输入i和j的值,使用空格隔开:\n");
    int i, j, max;
    scanf("%d %d", &i, &j);
    if (i > j) {
        max = i;
    }
    else {
        max = j;
    }
    printf("两个值中最大的值 max = %d\n", max);
}

/*
 * 多分支测试
 */
void MultipleBranchTest1()
{
    printf("请输入i的值:\n");
    int i;
    scanf("%d",&i);
    switch (i) {
        case 1:
            printf("您输入的值是: %d", 1);
            break;
        case 2:
            printf("您输入的值是: %d", 2);
            break;
        case 3:
            printf("您输入的值是: %d", 3);
            break;
        case 4:
            printf("您输入的值是: %d", 4);
            break;
        case 5:
            printf("您输入的值是: %d", 5);
            break;
        default:
            printf("您输入的值是其他值!");
            break;
    }
}

/*
 * 多分支测试
 *  只能匹配大写字母
 */
void MultipleBranchTest2()
{
    printf("please input grade (A B C D E F)\n");
    char grade = getchar();
    switch (grade) {
    case 'A':
        printf("score: 80 - 100\n");
        break;
    case 'B':
        printf("score: 60 - 80\n");
        break;
    case 'C':
        printf("score: 40 - 60\n");
        break;
    case 'D':
        printf("score: 20 - 40\n");
        break;
    case 'E':
        printf("score: 0 - 20\n");
        break;
    default:
        printf("输入数据不合法.....\n");
        break;
    }
}

/*
 * 多分支测试
 *  匹配大小写字母
 */
void MultipleBranchTest3()
{
    printf("please input grade (A B C D E F 或 a b c d e)\n");
    char grade = getchar();
    switch (grade) {
    case 'A':
    case 'a':
        printf("score: 80 - 100\n");
        break;
    case 'B':
    case 'b':
        printf("score: 60 - 80\n");
        break;
    case 'C':
    case 'c':
        printf("score: 40 - 60\n");
        break;
    case 'D':
    case 'd':
        printf("score: 20 - 40\n");
        break;
    case 'E':
    case 'e':
        printf("score: 0 - 20\n");
        break;
    default:
        printf("输入数据不合法.....\n");
        break;
    }
}

/*
 * 多分支测试
 *  switch的嵌套使用
 */
void MultipleBranchTest4()
{
    int a = 1;
    int b = 0;
    switch (a) {
    case -1:
        printf("a = -1\n");
        break;
    case 0:
        printf("a = 0\n");
        break;
    case 1:
        printf("a = 1\n");
        switch (b) {
        case -1:
            printf("b = -1\n");
            break;
        case 0:
            printf("b = 0\n");
            break;
        case 1:
            printf("b = -1\n");
            break;
        }
    }
}

/*
 * 三元表达式测试
 */
void TernaryExpression()
{
    printf("请输入i和j的值,使用空格隔开:\n");
    int i, j, max;
    scanf("%d %d", &i, &j);
    max = i > j ? i : j;
    printf("两个值中最大的值 max = %d\n", max);
}

#if 0
#endif
int main()
{
	//SingleBranchTest();
	//MultipleBranchTest1();
    //MultipleBranchTest2();
    //MultipleBranchTest3();
	MultipleBranchTest4();
    //TernaryExpression();
    return 0;
}
