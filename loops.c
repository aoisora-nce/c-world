/*
 * while() {}
 * do {} while();
 * for (ini; condition; update) {}
*/

#include <stdio.h>

int main(void)
{
    // To print I LOVE YOU x10
    // int i; // redundant as it can defined in the loop itself.
    int c = 1;
    int d = 1;

    for (int i=1; i<=10; i++) {
        printf("\033[47;31m I LOVE YOU x%d ♥ \033[0m", i);
    }
    printf("\n");
    while (c<=10) {
        printf("\033[47;31m I LOVE YOU x%d ♥ \033[0m", c);
        c += 1;
    }
    printf("\n");
    do {
        printf("\033[47;31m I LOVE YOU x%d ♥ \033[0m", d);
        d += 1;
    } while (d<=10);

    return 0;
}
