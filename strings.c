/* #include <string.h>
 *
 * strlen(str1) -> returns(int) str length except \0 (null char)
 * strcpy(target, source) -> copies string to target
 * strcat(str1,str2) -> join them
 * strcmp(str1,str2) -> 0(sama), +(str1>str2)(ASCII comp)
 * gets() -> input multi words strings (DEPRECTED due to memeory overflow)
 * puts() -> prints multi words strings + \n (newline)


*/

#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    char name1[10], name2[10];
    printf("Enter first name: ");
    scanf("%s", name1);
    printf("Enter last name: ");
    scanf("%s", name2);
    if (strcmp(name1, name2)==0) printf("Warning: First and Last name is same.\n");
    // gets(name);
    // puts(name);  // prints a new line at the end
    strcat(name1," ");
    strcat(name1,name2);
    strcpy(name,name1);
    printf("name1: %s \nname2: %s\n",name1,name2);
    printf("\nYour name is %s\n", name);
    return 0;
}


