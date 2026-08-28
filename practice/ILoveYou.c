#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int count = 0;

    while (count<10) {
        printf("\033[47;31m I LOVE YOU ♥ \033[0m");
        printf("\033[47;31m I LOVE YOU ♥ \033[0m");
        printf("\033[47;31m I LOVE YOU ♥ \033[0m");

        count++;

        if (count % 5 == 0) {
            printf("\n");
        } else {
            printf("  ");
        }
    }

    return 0;
}
