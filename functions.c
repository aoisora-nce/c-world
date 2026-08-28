/* const effects on pointers and variable
 *
 * const char *name;
 * name[0] = 'X';   // ERROR
 *
 * char *const name;
 * name = "Alice";  // ERROR
 *
 * const char *const name;
 * name = "Alice"; // ERROR
 * name[0] = 'X';  // ERROR

*/

#include <stdio.h>

// ++++++++++++ Function Prototyping +++++++++++
/*
 void love(const char *name);
 int cube(int num); // Parameter names aren't req, int cube(int); ✅

 int main(void) {
    love("Alice");
    printf("%d\n", cube(4));
    return 0;
 }

 void love(const char name[]) {
    printf("I LOVE %s ♥\n", name);
 }

 int cube(int num) {
    return num * num * num;
 }
 */

void love(const char name[]) {  // ~ const char *name
    if (name==NULL) name = "YOU";
    printf("I LOVE %s ♥\n", name);
}

int cube(int num) {
    return num*num*num;
}

int main() {
    love(NULL);
    love("Alice");
    int a = 4;
    printf("The cube of %d is %d.", a, cube(a));
    return 0;
}









