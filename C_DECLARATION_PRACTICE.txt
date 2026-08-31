C DECLARATION PRACTICE — QUESTIONS + ANSWERS

1. int x;
-> x is an integer.

2. int *p;
-> p is a pointer to an int.

3. int arr[5];
-> arr is an array of 5 integers.

4. int *arr[5];
-> arr is an array of 5 pointers to int.

5. int (*p)[5];
-> p is a pointer to an array of 5 ints.

6. char *str;
-> str is a pointer to a char.
-> Commonly used to point to a C string, but fundamentally it is a pointer to char.

7. char *names[10];
-> names is an array of 10 pointers to char.

8. char (*p)[10];
-> p is a pointer to an array of 10 chars.

9. int **p;
-> p is a pointer to a pointer to int.

10. int ***p;
-> p is a pointer to a pointer to a pointer to int.


FUNCTION POINTERS

11. int *func(void);
-> func is a function taking no arguments and returning a pointer to int.

12. int (*func)(void);
-> func is a pointer to a function taking no arguments and returning int.

13. int (*func[5])(void);
-> func is an array of 5 pointers to functions taking no arguments and returning int.

14. int *(*func)(void);
-> func is a pointer to a function taking no arguments and returning a pointer to int.


CONST + POINTERS

15. const int *p;
-> p is a pointer to a const int.
-> The data cannot be modified through p.
-> p itself can point somewhere else.

16. int *const p;
-> p is a const pointer to an int.
-> p cannot point somewhere else.
-> The pointed-to int can be modified through p.

17. const int *const p;
-> p is a const pointer to a const int.
-> p cannot point somewhere else.
-> The pointed-to int cannot be modified through p.


MORE COMPLEX DECLARATIONS

18. int **p[5];
-> p is an array of 5 pointers to pointers to int.

19. int (*p[5])[10];
-> p is an array of 5 pointers to arrays of 10 ints.

20. int (*(*p)[5]);
-> p is a pointer to an array of 5 pointers to int.


CORE RULE

Start at the variable name and read outward.

[] binds tighter than *.

int *arr[5];
   ^
   arr -> [5] -> * -> int
   array of 5 pointers to int

int (*p)[5];
    ^
    p -> * -> [5] -> int
    pointer to an array of 5 ints

Parentheses change what * belongs to.


CONST RULE

const int *p;
-> pointer to const int
-> data cannot be changed through p
-> p can change

int *const p;
-> const pointer to int
-> p cannot change
-> data can change

const int *const p;
-> const pointer to const int
-> neither p nor the data can change
