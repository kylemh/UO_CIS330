/* File: rps.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
 
char* getUserChoice() {
    /* Prompt the user "Enter rock, paper, or scissors: " and return
       the string they enter */
    char *choice = malloc(50);

    printf("Enter rock, paper, or scissors:");
    scanf("%s", choice);

    /* Ensure valid choice */
    if(strcmp(choice, "rock") == 0){
        return choice;
    } 
    if(strcmp(choice, "paper") == 0){
        return choice;
    }
    if(strcmp(choice, "scissors") == 0){
        return choice;
    } else {
        printf("Invalid user choice, you must enter rock, paper, or scissors.\n");
    }
    return "error - getUserChoice";
}
 
char* getComputerChoice() {
    srand (time(NULL));
    /* get a pseudo-random integer between 0 and 2 (inclusive) */
    int randChoice = rand() % 3;
    
    /* If randChoice is 0, return "rock"; if randChoice is 1,
     return "paper", and if randChoice is 2, return "scissors". */
    if(randChoice == 0){
        return "rock";
    }
    if(randChoice == 1){
        return "paper";
    }
    if(randChoice == 2){
        return "scissors";
    } 
    return "error - getComputerChoice";
}
 
char* compare(char* choice1, char* choice2)
{
    /* Implement the logic of the game here. If choice1 and choice2
     are equal, the result should be "This game is a tie."
 
     Make sure to use strcmp for string comparison.
     */
     char *rock_wins = "Rock wins.";
     char *paper_wins = "Paper wins.";
     char *scsrs_wins = "Scissors win.";
     char *tie_game = "This game is a tie.";


     if(strcmp(choice1, choice2) == 0){
        return tie_game;
     }
     if(strcmp(choice1, "rock") == 0){
        if(strcmp(choice2, "paper") == 0){
            return paper_wins;
        }
        if(strcmp(choice2, "scissors") == 0){
            return rock_wins;
        }
     }
     if(strcmp(choice1, "paper") == 0){
        if(strcmp(choice2, "rock") == 0){
            return paper_wins;
        }
        if(strcmp(choice2,"scissors") == 0){
            return scsrs_wins;
        }
     }
     if(strcmp(choice1, "scissors") == 0){
        if(strcmp(choice2, "rock") == 0){
            return rock_wins;
        }
        if(strcmp(choice2, "paper") == 0){
            return scsrs_wins;
        }
     } 
        return "error - compare";
}
 
int main(int argc, char** argv)
{
    char *userChoice = NULL, *computerChoice = NULL, *outcome = NULL;
 
    userChoice = getUserChoice();
    while(strcmp(userChoice, "error - getUserChoice") == 0){
        getUserChoice();
    }
    computerChoice = getComputerChoice();
    outcome = compare(userChoice, computerChoice);
 
    printf("You picked %s.\n", userChoice);
    printf("Computer picked %s.\n", computerChoice);
    printf("%s\n", outcome);
 
    return 0;
}
