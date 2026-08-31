#include <stdio.h>

int main()
{
	int a = 5; int *i_ptr = &a;
	char c = 'A'; char *c_ptr = &c;
	printf("Size of int: %zu bytes\n", sizeof(int));
	printf("Size of float: %zu bytes\n", sizeof(float));
	printf("Size of char: %zu bytes\n", sizeof(char));
	printf("Size of double: %zu bytes\n", sizeof(double));
	printf("Size of i_ptr: %zu bytes\n", sizeof(i_ptr));
	printf("Size of *i_ptr: %zu bytes\n", sizeof(*i_ptr));
	printf("Size of c_ptr: %zu bytes\n", sizeof(c_ptr));
	printf("Size of *c_ptr: %zu bytes\n", sizeof(*c_ptr));


	return 0;
}
