/*
    Write a C program that asks the user for a number and displays information about it.
    Analyze another number? (1 = Yes, 0 = No):
    Keep repeating until the user chooses 0.

    Concepts: Data Types, Conditions, Loops, Function Prototyping
*/

#include <stdio.h>

int square(int x);
int cube(int x);
char * type(int x);

int main() {
    while (1) {
        int num, choice;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("\n");
        printf("Number: %d\n", num);
        printf("Square: %d\n", square(num));
        printf("Cube: %d\n", cube(num));
        printf("Type: %s\n", type(num));

        printf("\nAnalyze another number? (1=Yes, 0=No): ");
        scanf("%d", &choice);
        if (choice==0) break;
        else if (choice==1) continue;
        else printf("Invalid Choice!\n");
    }

    return 0;
}

int square(int x) {
    return x*x;
}

int cube(int x) {
    return x*x*x;
}

char * type(int x) {
    if (x%2==0) return "Even";
    else return "Odd";
}
