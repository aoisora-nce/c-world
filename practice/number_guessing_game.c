/*
    === NUMBER GUESSING GAME ===
    I have generated a number between 1 and 100.
    Can you guess it?
    Enter your guess: 50
    Higher number please
    Enter your guess: 75
    Lower number please
    Enter your guess: 65
    Congratulations! You guessed the number 65
    in 3 attempts!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator (call it once)

  while (1) {
    int num = (rand() % 100) + 1;
    int counter = 0, guess = 0;
    printf("=== NUMBER GUESSING GAME ===\n\n");
    printf("A random number has been generated between 1 and 100.\n");
    printf("[HINT] %d\n", num);
    printf("Can you guess it?\n");
    while (1) {
      printf("\nEnter your guess: ");
      int status = scanf("%d", &guess);
      if (status == EOF) {
        printf("EOF Triggered.\n");
        printf("\nExiting game. Goodbye!\n");
        return 0;
      }
      if (status != 1) {
        printf("Invalid Input! Enter a valid integer.\n");
        while (getchar() != '\n')
          ;
        continue;
      }
      counter++;
      if (guess == num) {
        printf("\nCongratulations! You guessed the number %d in %d attempts.\n",
               num, counter);
        break;
      } else if (guess < num)
        printf("Higher number please!\n");
      else if (guess > num)
        printf("Lower number please!\n");
    }
    char choice;
    printf("Play again? [y/n] ");
    scanf(" %c", &choice);
    if (choice=='y' || choice=='Y') {printf("\n\n");continue;}
    break;
  }
  printf("\nExiting game. Goodbye!\n");
  return 0;
}





