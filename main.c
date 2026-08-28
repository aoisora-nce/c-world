#include <stdio.h>

// Data Types: Int(4 bytes)(%d), Float(4 B)(%f), Char(1 B)(%c)

int main() {
	int a = 65.8; // stored value 65 (truncation)
	float b = 66.9; //stored value 66.900002
	char c = 67.7; // stored value 67 ('C' in ASCII)
	printf("%d %f %c \n", a,a,a);
	printf("%d %f %c \n", b,b,b);
	printf("%d %f %c \n", c,c,c);
	
	printf("Hello World\n");
	printf("Midori Sarada \u2665 \n");
	printf("He's %d years old.\n", a); // %d will print int only
	
	char name[10]; // string (up to 9 chars + '\0')
	char grade;
	int age;
	printf("Enter your name: ");
	scanf("%9s", name); // limit input to 9 chars (name instead of &name )
	printf("Enter your grade (A/B/C): ");
	scanf(" %c", &grade); // leading space skips newline, tabs, spaces
	printf("Enter your age: ");
	scanf("%d", &age);
	
	printf("%s is %d years old and scored %c grade.\n", name, age, grade);
	return 0;
}












