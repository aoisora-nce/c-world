#include <stdio.h>

/*
 ===== NUMBER MANAGER =====

 1. Show all numbers
 2. Show square and cube of every number
 3. Find the largest number
 4. Double a number [Which number do you want to double? (1-5): 3]
 5. Show even/odd status
 6. Reset all numbers to 0
 7. Change numbers
 0. Exit

 Choice:
*/

void input_nums(int nums[]);
void show_nums(const int nums[]);
void squares(int *), cubes(int *);  // skipped arg in prototype
int largest(int nums[]);
int twice(int *num);
void doubles(int nums[]);
void type(int nums[]);
void reset_nums(int nums[]);
void swap(int *);

int main() {
    int numbers[5];
    input_nums(numbers);
    while (1) {
        int c = 0;
        printf("\n===== NUMBER MANAGER =====\n\n");
        printf("1. Show all numbers\n");
        printf("2. Show square and cube of every number\n");
        printf("3. Find the largest number\n");
        printf("4. Double a number\n");
        printf("5. Show even/odd status\n");
        printf("6. Reset all numbers to 0\n");
        printf("7. Change numbers\n");
        printf("8. Swap numbers\n");
        printf("0. Exit\n\n");

        printf("Choice: ");
        scanf("%d", &c);

        if (c==1) show_nums(numbers);
        else if (c==2) { squares(numbers); printf("\n"); cubes(numbers); }
        else if (c==3) printf("The largest number is %d.\n", largest(numbers));
        else if (c==4) doubles(numbers);
        else if (c==5) type(numbers);
        else if (c==6) reset_nums(numbers);
        else if (c==7) input_nums(numbers);
        else if (c==8) swap(numbers);
        else if (c==0) { printf("Exited Successfully.\n"); break;}
        else printf("Invalid Choice!");




    }
    return 0;
}

void input_nums(int nums[]) {
    for (int i=0; i<5; i++)  {
        printf("Enter number %d: ", i+1);
        scanf("%d", &nums[i]);
    }
}

void show_nums(const int nums[]) {
    for (int i=0; i<5; i++)  {
        printf("Number %d: %d \n", i+1, nums[i]);
    }
}

void squares(int nums[]) {
    printf("Squares: ");
    for (int i=0; i<5; i++) {
        int num = nums[i];
        printf("[%d->%d] ", num, num*num );
    }
}

void cubes(int nums[]) {
    printf("Cubes: ");
    for (int i=0; i<5; i++) {
        int num = nums[i];
        printf("[%d->%d] ", num, num*num*num );
    }
}

int twice(int *num) {
    *num *= 2;
    return *num;
}
void doubles(int nums[]) {
    int i;
    printf("Which number do you want to double? (1-5): ");
    scanf("%d", &i);
    int num = nums[i-1];
    printf("Num %d has been doubled. [%d->%d] \n",i,num,twice(&nums[i-1]));
}

int largest(int nums[]) {
    /* ********* Method 1: Using conditionals **********
     * Change > with >= for handling duplicates numbers
    int a=nums[0], b=nums[1], c=nums[2], d=nums[3], e=nums[4];
    int largest = e;
    if (a>b && a>c && a>d && a>e) largest = a;
    else if (b>a && b>c && b>d && b>e) largest = b;
    else if (c>a && c>b && c>d && c>e) largest = c;
    else if (d>a && d>b && d>c && d>e) largest = d;
    return largest;
    */

    /* ********* Method 2: Using loops **********
    int largest = nums[0];
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (nums[i] < nums[j]) {
                break;
            }
            largest = nums[i];
        }
    }
    return largest;
    */

    // ******** Method 3: Simple ************
    int largest = nums[0];
    for (int i=0; i<5; i++){
        if (nums[i]>largest) largest=nums[i];
    }
    return largest;
}

void reset_nums(int nums[]) {
    // reset all data to 0
    for (int i=0; i<5; i++) {
        nums[i] = 0;
    }
    printf("All numbers reset to 0 successfully.\n");
}

// void type(int nums[]) {
//     int even[] = {0,0,0,0,0};
//     int odd[] = {0,0,0,0,0};
//     for (int i=0; i<5; i++) {
//         if (nums[i] % 2 == 0) even[i]=nums[i];
//         else odd[i]=nums[i];
//     }
//     int *e=even, *o=odd; // Eff. int *e = &even[0]; int *o = &odd[0];
//     printf("Even numbers: %d %d %d %d %d\n", e[0],e[1],e[2],e[3],e[4]);
//     printf("Odd numbers: %d %d %d %d %d\n", o[0],o[1],o[2],o[3],o[4]);
// }


void type(int nums[]) {
    printf("Even numbers: ");
    for (int i=0; i<5; i++) {
        if (nums[i]%2==0) printf("%d ", nums[i]);
    }

    printf("\nOdd numbers: ");
    for (int i=0; i<5; i++) {
        if (nums[i]%2!=0) printf("%d ", nums[i]);
    }
    printf("\n");
}

void swap(int *nums) {
    int a,b;
    printf("Enter indexes to swap [1-5]: ");
    scanf("%d %d", &a, &b);
    int num1=nums[a-1];
    nums[a-1]=nums[b-1];
    nums[b-1]=num1;
    printf("Swapped successfully.\n");
}



















