#include <stdio.h>

// 1. FUNCTION PROTOTYPES (Declarations)
int add(int a, int b);
void print_greeting(const char *name);

// 2. MAIN FUNCTION (Entry point)
int main(void) {
    int sum = add(5, 10);
    printf("Sum: %d\n", sum);

    print_greeting("Midori");

    return 0;
}

// 3. FUNCTION DEFINITIONS (Implementations)
int add(int a, int b) {
    return a + b;
}

void print_greeting(const char *name) {
    printf("Welcome back, %s!\n", name);
    // 'void' functions don't need a return statement
}
