/* To Print:
 * Multiplication Table using loops
*/

#include <stdio.h>

int main() {
    for (int a=1; a<=10; a++) {
        // printf("%d\t", a); // May include or may not
        for (int i=1; i<=10; i++) {
            printf("%d\t", a*i);
        }
        printf("\n");
    }
    return 0;
}
