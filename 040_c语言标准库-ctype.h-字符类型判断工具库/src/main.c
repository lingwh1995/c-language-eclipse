# include <stdio.h>
# include <ctype.h>

/**
 * getchar()、if-else和ctype.h
 *  ctype.h: 判断一个字符是否为控制字符、数字、大写字母、小写字母
 */

 /**
  * 自己实现判断逻辑
  */
void JudgeCharacterTypeTest1()
{
    printf("请输入一个字符:\n");
    char c = getchar();
    if (c < 32) {
        printf("this is a control char\n");
    }
    else if (c > '0' && c < '9') {
        printf("this is a number\n");
    }
    else if (c > 'a' && c < 'z') {
        printf("this is a lower case\n");
    }
    else if (c > 'A' && c < 'Z') {
        printf("this is a upper case\n");
    }
    else {
        printf("other char\n");
    }
}

/**
 * 调用ctype.h实现判断逻辑
 */
void JudgeCharacterTypeTest2()
{
    printf("请输入一个字符:\n");
    char c = getchar();
    if (iscntrl(c)) {
        printf("this is a control char\n");
    }
    else if (isdigit(c)) {
        printf("this is a number\n");
    }
    else if (islower(c)) {
        printf("this is a lower case\n");
    }
    else if (isupper(c)) {
        printf("this is a upper case\n");
    }
    else {
        printf("other char\n");
    }
}
int main()
{
    //JudgeCharacterTypeTest1();
    JudgeCharacterTypeTest2();
    return 0;
}
