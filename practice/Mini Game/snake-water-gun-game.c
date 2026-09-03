/* MINI-GAME @2.1.1
 * Problem: Build a simple Snake, Water, Gun game using conditional statements
 * and random number generation.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_screen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int win(int choice1, int choice2) {
    int c1 = choice1;
    int c2 = choice2;

    if ((c1==1 || c1==2) && (c2==2 || c2==1)) { printf("Snake(🐍) drank the water(💦)...(hisss)\n"); return 1;}
    if ((c1==2 || c1==3) && (c2==3 || c2==2)) { printf("Water(💦) drowned the Gun(🔫)...(splash)\n"); return 2;}
    if ((c1==3 || c1==1) && (c2==1 || c2==3)) { printf("Gun(🔫) killed the Snake(🐍)...(pew pew)\n"); return 3;}
    return 0;
}

int main() {
    srand(time(NULL));
    while (1) {
        int bot_choice = (rand()%3)+1;
        int user_choice = 1;
        char *CHOICES[] = {"Snake", "Water", "Gun"};

        printf("*** A MINI TEXT BASED GAME ***\n");
        printf("=== SNAKE WATER GUN ===\n\n");
        printf("1. %s \n", CHOICES[0]);
        printf("2. %s \n", CHOICES[1]);
        printf("3. %s \n", CHOICES[2]);

        while(1) {
            printf("Enter your choice [1-3]: ");
            if (scanf("%d", &user_choice) == 1) {
                if (user_choice<4 && user_choice>0) break;
            }
            printf(">> Not a valid choice! [Hint: Enter a number between 1-3]\n");
            while(getchar() != '\n');
        }
        printf("Your Choice: %s \t BOT Choice: %s \n", CHOICES[user_choice-1], CHOICES[bot_choice-1]);
        if (user_choice == bot_choice ) printf("\nResult: Round Tie! 😵‍💫 \n");
        else if (user_choice == win(user_choice, bot_choice)) {
            printf("\nYou WIN, congratulations! 👏🎊 \n");
        }
        else printf("\nYou LOSE, better luck next time! 💔 \n");

        char again;
        printf("Play Again? [y/n] ");
        scanf(" %c", &again);
        while(getchar() != '\n');
        if (again=='y' || again=='Y') { clear_screen(); continue; }
        break;
    }

    return 0;
}
