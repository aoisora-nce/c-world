/*
================================
       RPG BATTLE SIMULATOR
================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void clear_screen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void splash() {
    printf(">> Loading ");
    for (int i=1; i<=3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf(" Done ✅\n");
    sleep(1);

}

void input(char *message, char *format, void *address) {
    int count=0;
    while (true) {
        if (count>=5) {
            printf("\nMaximum tries reached. Exiting...\n");
            exit(EXIT_FAILURE); // exit(1)
        }
        count++;
        printf("%s", message);
        int status = scanf(format, address);
        if (status == EOF) {
            printf("\nEOF Triggered, Terminating process.\n");
            exit(EXIT_FAILURE);
        }
        else if (status != 1) {
            printf("Invalid Input, Try Again! x%d\n", count);
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        break; // Success
    }
}
void eval_choice(int);

void create_char();
void show_char();
void view_char();
void train_char();
void battle();
void delete_char();
void battle_history();
void exit_main();

void print_menu() {
    clear_screen();
    printf("================================ \n");
    printf("RPG BATTLE SIMULATOR \n");
    printf("================================ \n");
    printf("\n");
    printf("1. Create Character \n");
    printf("2. Show Characters \n");
    printf("3. View Character \n");
    printf("4. Train Character \n");
    printf("5. Battle \n");
    printf("6. Delete Character \n");
    printf("7. Show Battle History \n");
    printf("0. Exit \n");
    printf("\n");
}

struct Character {
    char name[20];
    char class[20];
    int hp;
    int attack;
    int damage;
    int level;
    int wins;
    int losses;
};
typedef struct Character TypeChar;

/* Analogy @1.0
 *
 * Simple Analogy to get whats happening with realloc
 * "realloc" looks for a bigger room.
 * If the current room can't be expanded in place,
 * it copies all your data into a new, larger room, destroys the old room,
 * and gives the new room number (memory address) to `characters` (in our case).
*/

void check_capacity(int count, int *capacity, TypeChar **ptr) {
    if (count >= *capacity) {
        *capacity += 2;
        *ptr = realloc(*ptr, *capacity*sizeof(**ptr));
        printf("[Info] Allocated new size: %d * %zu bytes \n", *capacity, sizeof(**ptr));
    }
}

int main() {
    TypeChar *characters;
    int choice;
    int count = 0;  // default 0 characters counter
    int capacity = 2; // default capacity for characters (currently 2)
    printf("Size of characters %zu\n", sizeof(*characters));
    characters = calloc(capacity, sizeof(*characters)); // malloc(capacity*sizeof(*characters));

    splash();
    print_menu();
    input("Choice: ", "%d", &choice);
    eval_choice(choice);

    check_capacity(count, &capacity, &characters);


    return 0;
}

void eval_choice(int choice) {
    if (choice == 1) create_char();
    // else if (choice == 2) create_char();
    // else if (choice == 3) show_char();
    // else if (choice == 4) view_char();
    // else if (choice == 4) train_char();
    // else if (choice == 5) battle();
    // else if (choice == 6) delete_char();
    // else if (choice == 7) battle_history();
    else if (choice == 0) exit_main();
}

void exit_main() {
    printf("\nBYE BYE! See You Next Time!\n");
    exit(EXIT_SUCCESS);
}


void create_char() {
    printf("Created\n");
}







