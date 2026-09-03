/* Topic: Dynamic Memory Allocation
 *
 * #include <stdlib.h>
 * malloc(size) -> returns void pointer
 * calloc(blocks, block-size)
 * realloc(ptr, newSize)
 * free(ptr)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    char *name;
    // printf("How many characters you wanna store? [numbers] ");
    // scanf("%d", &n);
    // name = (char *)malloc((n+1)*sizeof(char));
    // printf("%zu bytes allocated to name.\n", (n+1)*sizeof(char));
    printf("Reading name ptr: %s \n", name);
    printf("Enter a name: ");
    scanf("%s", name);
    printf("Entered name is %s \n", name);

    // free(name);
    return 0;
}
