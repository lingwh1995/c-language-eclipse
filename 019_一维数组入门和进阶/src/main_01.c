#include <stdio.h>
#include <stdbool.h>

/**
  * 返回每个月有多少天
  *     数组最佳应用场景: 查表
  * 直接使用数组来获取每个月的天数,比使用switch-case要快很多
  * @param month
  */
int getDaysByMonth(int month)
{
    // 默认为闰年
    bool isLeap = true;
    static const int days[] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && isLeap) {
        month = 0;
    }
    return days[month];
}


/**
 * 输入月份和日期,获取从第一天到这个日期总共有多少天
 * @param month
 * @param day
 * @return
 */
 //引入枚举提高程序健壮性,好处是可以在getDays()方法之外做输入数据有误的处理逻辑,而不是直接在getDays()方法中做输入数据有误的处理逻辑
 //这是一种很有用的编程思维,也可以使用宏定义来实现类似于枚举的作用,可以实现更好的分离代码逻辑和异常处理逻辑
enum
{
    MONTH_ERROR = -1,
    DAY_ERROR = -2
};

int getDays(int month, int day)
{
    // 返回-1代表输入的月份不合理
    if (month < 1 || month > 12) {
        return MONTH_ERROR;
    }
    // 返回-2代表输入的天数不合理
    if (day < 1 || day > 31) {
        return DAY_ERROR;
    }
    int totalDays = 0;
    for (int i = 1; i < month; i++) {
        // 测试查表法使用数组
        totalDays += getDaysByMonth(i);
    }
    return totalDays = totalDays + day;
}

#if 0
#endif
int main()
{
    // 获取从第一天到这个日期总共有多少天
    int days = getDays(2, 1);
    switch (days) {
    case -1:
        printf("输入的月份有误!\n");
        break;
    case -2:
        printf("输入的日期有误!\n");
        break;
    default:
        printf("总天数: %d\n", days);
        break;
    }

}
