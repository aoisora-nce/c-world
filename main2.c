// Safe input and handling stdin
// return 0 in functions : no error
// return non-zero in fun : error 

#include <stdio.h>

int input(const char *desc, const char *format, void *var) {
	char buffer[100];
	printf("%s", desc);
	if (fgets(buffer, sizeof(buffer), stdin)) {
		if (sscanf(buffer, format, var) == 1) {
			return 0; // Input parse success
		} else {
			printf("Invalid Input! \n");
			return 1;
		}
	} else {
		printf("Parse error! \n");
		return 1;
	}
}

int main() {
	char name[10], location[10], hobby[10];
	int age;
	if (input("Enter your name: ", "%9s", name)) return 1;
	if (input("Where are you from: ", "%9s", location)) return 1;
	if (input("What's your age: ", "%d", &age)) return 1;
	if (input("What is/are your hobby/hobbies?: ", "%9s", hobby)) return 1;
	printf("Hello %s, you are %d years old, from %s, and you love %s.\n",
           name, age, location, hobby);
	return 0;
}
