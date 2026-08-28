/*
    File: pointers.c (26/08)

    BASIC POINTER IDEA

    int age = 25;     // an int containing the value 25
    int *ptr = &age;  // ptr stores the memory address of age
    *ptr = 30;        // dereference ptr and change age to 30

    &variable         -> "address of variable"
    *pointer          -> "value at the address stored in pointer"

    %p expects a void * pointer, so cast object pointers:
        printf("%p", (void *)&age);

    Memory addresses are commonly displayed in hexadecimal:
        0x7ffd1234abcd

*/

#include <stdio.h>

int main(void)
{
    /*
        x is an int.
        &x is the address of x and has type int *.
    */
    int x = 10;

    /*
        name is an array containing:

        +---+---+---+---+---+---+---+---+---+
        | A | o | i |   | S | o | r | a |\0 |
        +---+---+---+---+---+---+---+---+---+

        name usually decays to a pointer to its first character.
        &name is a pointer to the entire array.
    */
    char name[] = "Aoi Sora";

    /*
        buffer is a pointer variable.

        buffer ------> "She's a good Japanese film artist.\0"

        The string literal is stored elsewhere in memory.
        buffer stores its address.
    */
    const char *buffer = "She's a good Japanese film artist.";

    /* -------------------------------------------------
       INT
       ------------------------------------------------- */

    printf("x = %d\n", x);
    printf("&x = %p (address of x)\n\n", (void *)&x);

    /* -------------------------------------------------
       ARRAY
       ------------------------------------------------- */

    printf("name = %s\n", name);

    /*
        In this context, name points to its first character.

        name has array type: char[9]
        name usually decays to: char *

        &name has type: char (*)[9]
        (pointer to the entire array)
    */
    printf("name = %p (address of first character)\n", (void *)name);
    printf("&name = %p (address of whole array)\n\n", (void *)&name);

    /*
        name and &name may print the same numeric address,
        but they have DIFFERENT types and different pointer
        arithmetic behavior:

        name + 1    -> moves forward 1 char
        &name + 1   -> moves forward sizeof(name) bytes
    */

    /* -------------------------------------------------
       POINTER TO STRING
       ------------------------------------------------- */

    printf("buffer = %s\n", buffer);

    /*
        buffer is a pointer variable.
        Its VALUE is an address pointing to the first
        character of the string literal.
    */
    printf("buffer = %p (address stored in pointer)\n", (void *)buffer);

    /*
        &buffer is the address of the pointer variable itself.

        buffer   != &buffer

        buffer   -> address of the string
        &buffer  -> address of the pointer variable
    */
    printf("&buffer = %p (address of pointer variable)\n", (void *)&buffer);

    return 0;
}
