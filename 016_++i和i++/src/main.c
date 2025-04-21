#include <stdio.h>

/**
 * i++ : 先用后+
 * ++i : 先加后用
 */
int main()
{
	// i++
	int i = 10;
    printf("i: %d\n", i++);

    // ++i
    i = 10;
    printf("i: %d\n", ++i);
}
