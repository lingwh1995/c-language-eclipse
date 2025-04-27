#include <stdio.h>

/**
 * 标准输入和EOF
 */


 /**
 * 标准输入测试
 */
void StdinAndEOFTest1() {
    printf("请输入,按回车结束:\n");
    int sum = 0;
    while (getchar() != '\n') {
        sum++;
    }
    printf("sum = %d\n", sum);
}


/**
 * 标准输入和EOF测试
 */
void StdinAndEOFTest2() {
    printf("请输入,按 换行符+Ctrl+D 结束:\n");
    int sum = 0;
    while (getchar() != EOF) {
        sum++;
    }
    printf("sum = %d\n", sum);
}


/**
 * 标准输入测试
 *  接收单个字符: 不管输入多少个字符,都只会接收第一个字符
 */
void StdinAndEOFTest3() {
    printf("请输入:\n");
    char ch = getchar();
    printf("ch = %c", ch);
}


/**
 * 标准输入测试
 *  接收多个字符
 */
void StdinAndEOFTest4() {
    printf("请输入:\n");
    char ch = '\0';
    //为什么getchar()可以放在while后面的大括号中,来接收多个字符,因为getchar()有一个缓冲区机制

    //错误写法
    //while (ch = getchar() != '\n') {
    //正确写法
    //while ((ch = getchar()) != '\n') {
    while ((ch = getchar()) != EOF) {
        printf("ch = %c\n", ch);
    }
}

/**
 * 输入IQ值，通过IQ值判断是不是Genius，IQ>=140是Genius
 *  接收多个字符
 */
void StdinAndEOFTest5() {
    printf("请输入IQ值:\n");
    int IQ;
    while (scanf("%d", &IQ) != EOF) {
        if(IQ >= 140)
        {
            printf("Genius\n");
        }
        else
        {
            printf("Not Genius\n");
        }
    }
}

int main() {
    //StdinAndEOFTest1();
	//StdinAndEOFTest2();
    //StdinAndEOFTest3();
    //StdinAndEOFTest4();
	StdinAndEOFTest5();
}
