#include <stdio.h>

int main(void) {
    char *one = "hello";
    char *many[] = {"hello", "world"};

    printf("%s\n", one);      // hello
    printf("%s\n", many[0]);  // hello
    printf("%s\n", many[1]);  // world
}
