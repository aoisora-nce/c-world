#include <stdio.h>
#include <string.h>

struct student {
    int class;
    int roll;
    char name[20];
    float dues;
    char *fname;
};
typedef struct student std;

int main() {
    struct student s1;
    s1.class = 10;
    s1.roll = 21;
    // s1.name = "Aoi"; // wrong..why?
    char name[] = "Aoi Sora";
    strcpy(s1.name, name);
    s1.dues = 2500;
    s1.fname = "Hikari";

    struct student s2 = {8, 12, "Aki Sora", 1800, "Tanaka"};

    char input_fname[20];
    printf("Enter Father's Name for student %s: ","Miuna");
    scanf("%s", input_fname);
    std s3 = {.fname=input_fname, .name="Miuna Nagi", .dues=9999, .roll=9, .class=11};

    printf("Class\tRoll\tStudent's Name\tFather's Name\tDues (Rs.)\n\n");
    printf("%d\t %d\t %s\t %s\t\t %.2f\n",s1.class,s1.roll,s1.name,s1.fname,s1.dues);
    printf("%d\t %d\t %s\t %s\t\t %.2f\n",s2.class,s2.roll,s2.name,s2.fname,s2.dues);
    printf("%d\t %d\t %s\t %s\t\t %.2f\n",s3.class,s3.roll,s3.name,s3.fname,s3.dues);

    // can create array of students students[0],students[1]...
    std students[] = {
        {10, 21, "Aoi Sora", 2500.0f, "Hikari"},
        {8,  12, "Aki Sora", 1800.0f, "Tanaka"},
        {11, 9,  "Miuna Nagi", 9999.0f, "Tsumugu"}
    };
    printf("\n\n");
    printf("%-6s %-6s %-15s %-15s %-10s\n", "Class", "Roll", "Student Name", "Father's Name", "Dues (Rs.)");
    printf("------------------------------------------------------------\n");
    int count = sizeof(students) / sizeof(students[0]);
    for (int i = 0; i < count; i++) {
        printf("%-6d %-6d %-15s %-15s %-10.2f\n",
               students[i].class,
               students[i].roll,
               students[i].name,
               students[i].fname,
               students[i].dues);
    }

    return 0;
}
