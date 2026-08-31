/* Problem: Create an array of size 3×10 containing
 * multiplication tables of the numbers 2, 7 and 9 respectively.
 */

#include <stdio.h>

int main() {
    int table[3][10];
    int base[3] = {2, 7, 9};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            table[i][j] = base[i] * (j + 1);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%2d ", table[i][j]);
        }
        printf("\n");
    }
    return 0;
}
