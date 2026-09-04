/*
================================
       RPG BATTLE SIMULATOR
================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

void clear_screen() {
    // return;
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

void wait_for_enter() {
    printf("\n>> Press Enter to continue...");
    getchar();
    printf("\n\n"); // In case scree is not cleared
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
void eval_choice(int choice);
int check_capacity(int count);

void create_char();
void show_chars();
void view_char();
void train_char();
void battle();
void delete_char();
void battle_history();

void load_data();
void save_data();
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
    printf("8. Load Saved Characters (*=*) \n");
    printf("9. Save Characters (RPG-BS.data) (*o*) \n");
    printf("0. Exit \n");
    printf("\n");
}

struct Character {
    char name[20];
    char class[20];
    int hp;
    int attack;
    int defense;
    int level;
    int wins;
    int losses;
};
typedef struct Character TypeChar;

char *char_class[3] = {"Barbarian", "Archer", "Wizard"};

TypeChar Barbarian = {.hp=120, .attack=15, .defense=12};
TypeChar Archer = {.hp=100, .attack=20, .defense=8};
TypeChar Wizard = {.hp=80, .attack=25, .defense=6};

TypeChar *characters;
int char_count = 0;  // default 0 characters counter
int char_capacity = 2; // default capacity for characters (currently 2)

/* Analogy @1.0
 *
 * Simple Analogy to get whats happening with realloc
 * "realloc" looks for a bigger room.
 * If the current room can't be expanded in place,
 * it copies all your data into a new, larger room, destroys the old room,
 * and gives the new room number (memory address) to `characters` (in our case).
*/

/*
void check_capacity(int count, int *capacity, TypeChar **ptr) {
    if (count >= *capacity) {
        *capacity += 2;
        *ptr = realloc(*ptr, *capacity*sizeof(**ptr));
        printf("[Info] Allocated new size: %d * %zu bytes \n", *capacity, sizeof(**ptr));
    }
}
*/

int main() {
    int choice;

    printf("Size of characters %zu\n", sizeof(*characters));
    // malloc(capacity*sizeof(*characters));
    characters = calloc(char_capacity, sizeof(*characters));

    splash();
    while (true) {
        print_menu();
        input("Choice: ", "%d", &choice);
        printf("\n");
        eval_choice(choice);

        // NO longer needed as we moved all the variables out of main() scope to global scope
        // check_capacity(count, &capacity, &characters);
    }

    return 0;
}

void exit_main() {
    save_data();
    printf("\nBYE BYE! See You Next Time!\n");
    exit(EXIT_SUCCESS);
}

int check_capacity(int count) {
    if (count >= char_capacity) {
        int new_capacity = char_capacity + 2;
        TypeChar *tmp = realloc(characters, new_capacity*sizeof(*characters));
        if (tmp == NULL) {
            printf("[Error] Memory reallocation failed.");
            return 1;
        } else {
            characters = tmp;
            char_capacity = new_capacity;
            printf("[Info] Allocated new size: %d * %zu bytes \n", char_capacity, sizeof(*characters));
            return 0;
        }
    }
    return 0;
}

void eval_choice(int choice) {
    if (choice == 1) create_char();
    else if (choice == 2) show_chars();
    // else if (choice == 3) view_char();
    // else if (choice == 4) train_char();
    // else if (choice == 5) battle();
    else if (choice == 6) delete_char();
    // else if (choice == 7) battle_history();
    else if (choice == 8) load_data();
    else if (choice == 9) save_data();
    else if (choice == 0) exit_main();
}



void create_char() {
    char char_name[20];
    int choice;
    input("Character name: ", "%s", char_name);
    printf("\nChoose class:- \n");
    printf("1. Barbarian \n");
    printf("2. Archer \n");
    printf("3. Wizard \n");
    input("\nChoice: ", "%d", &choice);

    int tmp_count = char_count + 1;
    if (check_capacity(tmp_count) != 0) {
        printf("Character creation failed due to low memory.\n");
        wait_for_enter();
        return;
    }
    TypeChar selected_class;
    if (choice == 1) selected_class = Barbarian;
    else if (choice == 2) selected_class = Archer;
    else if (choice == 3) selected_class = Wizard;

    characters[char_count] = (TypeChar){
        .hp= selected_class.hp,
        .attack=selected_class.attack,
        .defense=selected_class.defense,
        .level=1,
        .wins=0,
        .losses=0,
    };
    strcpy(characters[char_count].name, char_name);
    strcpy(characters[char_count].class, char_class[choice-1]);

    char_count = tmp_count;
    printf("[Success] Character [%s] (ID: %d) created successfully.\n", char_name, char_count);
    wait_for_enter();
}

void show_chars() {
    if (char_count == 0) {
        printf("[404] Characters not found, Add a character first (+_-)!\n");
        wait_for_enter();
        return;
    }

    printf("\n========== CHARACTERS ==========\n");
    printf("%-4s %-15s %-15s %-5s %-5s %-5s\n", "ID", "NAME", "CLASS", "LVL", "HP", "W/L");

    for (int i=1; i<=char_count; i++) {
        printf("%-4d %-15s %-15s %-5d %-5d %-d/%-d\n",
               i,
               characters[i-1].name,
               characters[i-1].class,
               characters[i-1].level,
               characters[i-1].hp,
               characters[i-1].wins,
               characters[i-1].losses
               );
    }
    wait_for_enter();
}

void delete_char() {
    int choice;
    char confirm[5];
    input("Enter character ID: ", "%d", &choice);
    TypeChar selected_char = characters[choice-1];
    printf("Are you sure you want to delete [%s] [%s]\n", selected_char.name, selected_char.class);
    input("\nType yes to confirm deletion: ", "%4s", confirm);

    if (strcmp(confirm, "yes") == 0) {
        for (int i=choice; i<=char_count; i++) {
            characters[i-1] = characters[i];
        }
         char_count--;
        printf("[SUCCESS] Character [%s] deleted successfully.\n", selected_char.name);
    } else {
        printf("[Info] Delete Cancelled by the user (O_o)!\n");
    }
    wait_for_enter();
}


void load_data() {
    printf("Are you sure, you want to load game-data, it may overwrite all your current temporary characters?");
    char confirm[5];
    input("\nType yes to proceed: ", "%4s", confirm);
    if (strcmp(confirm, "yes") != 0) return;

    FILE *fptr = fopen("RPG-BS.data", "rb");
    if (fptr == NULL) {
        printf("[IO Error] Error opening saved file, possibly doesnt exist.\n");
        fclose(fptr);
        wait_for_enter();
        return;
    }
    int count=0;
    while (true) {
        check_capacity(char_count);
        int status = fread(&characters[char_count], sizeof(*characters), 1, fptr);
        if (status==1) {
            count++;
            char_count++;
            // loop continues...
        } else {
            if (feof(fptr)) {
                printf("[Info] Successfully reached end of file.\n");
            } else if (ferror(fptr)) {
                printf("[IO Error] Error reading file data.\n");
            }
            break; // break loop on EOF or error
        }
    }
    printf("Succefully loaded %d characters. Cheers \\|+_+|/\n", count);
    fclose(fptr);
    wait_for_enter();
}

void save_data() {
    int count = char_count;
    if (count==0) {
        printf("[IO Warn] No characters exist! Add a character first (+_-)!\n");
        wait_for_enter();
        return;
    }

    char confirm[5];
    printf("Are you sure, you want to overwrite your game-data file (+_+)?\n");
    input("\nType yes to proceed: ", "%4s", confirm);
    if (strcmp(confirm, "yes") != 0) return;

    FILE *fptr = fopen("RPG-BS.data", "wb");
    int status = fwrite(characters, sizeof(*characters), count, fptr);
    if (status == count) {
        printf("[IO Info] Succefully saved %d characters into data file.\n", count);
    } else if (status < count) {
        printf("[IO Error] An error occured while saving char data.\n");
        printf("In %d Out %d (elements)\n", count, status);
    }
    fclose(fptr);
}








