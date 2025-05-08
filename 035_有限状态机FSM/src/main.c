#include <stdio.h>
#include <ctype.h>

/**
 * 章节内容:
 *      多分支switch-case实现有限状态机(Finite state machine)
 *      需求:
 *          统计 字符串 {" hello    c   lang  nice   "} 中单词的个数
 *
 */

//宏定义实现状态码
# define BEGIN 0
# define IN_WORD 1
# define OUT_WORD 2
# define END 3

//枚举实现状态码(推荐使用)
/*
enum state {
    BEGIN_ENUM,
    IN_WORD_ENUM,
    OUT_WORD_ENUM,
    END_ENUM
};
*/


/*
 * 统计单词中出现的所有字母
 */
void FSM1(char str[])
{
    int i = 0;
    //记录单词个数
    int sum_alpha = 0;
    int state = BEGIN;
    //遍历字符串的新方式: 利用字符串最后一个字符是 \0 的特性
    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (state) {
        case BEGIN:
            if (isalpha(str[i])) {
                state = IN_WORD;
            }
            else {
                state = OUT_WORD;
            }
            break;
        case IN_WORD:
            if (!isalpha(str[i])) {
                sum_alpha++;
                state = OUT_WORD;
            }
            break;
        case OUT_WORD:
            if (isalpha(str[i])) {
                state = IN_WORD;
            }
            break;
        }
    }
    if (state == IN_WORD)
    {
        sum_alpha++;
        state = END;
    }
    printf("sum_alpha = %d\n", sum_alpha);
}

/*
 * 统计单词中出现的所有字母和空格
 */
void FSM2(char str[])
{
    int i = 0;
    //记录单词个数
    int sum_alpha = 0;
    int sum_space = 0;
    int state = BEGIN;
    //遍历字符串的新方式: 利用字符串最后一个字符是 \0 的特性
    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (state) {
        case BEGIN:
            if (isalpha(str[i]))
            {
                state = IN_WORD;
            }else {
                state = OUT_WORD;
                sum_space++;
            }
            break;
        case IN_WORD:
            if (!isalpha(str[i]))
            {
                sum_alpha++;
                state = OUT_WORD;
            }
            break;
        case OUT_WORD:
            if (isalpha(str[i]))
            {
                state = IN_WORD;
            }
            sum_space++;
            break;
        }
    }
    if (state == IN_WORD)
    {
        sum_alpha++;
        state = END;
    }
    printf("sum_alpha = %d\n", sum_alpha);
    printf("sum_space = %d\n", sum_space);
}

int main()
{
    char str[] = { " hello  c   lang    nice     " };
    FSM1(str);
    //FSM2(str);
    return 0;
}