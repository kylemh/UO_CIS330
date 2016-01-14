/* File: rps.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>      
#include <string.h>
 
char* getUserChoice() {
    /* Prompt the user "Enter rock, paper, or scissors: " and return
       the string they enter */
    printf("Enter rock, paper, or scissors:");
    scanf("%d", &choice);
    if(choice == "rock"){
        return rock;
    } 
    if(choice == "paper"){
        return paper;
    }
    if(choice == "scissors"){
        return scissors;
    } else {
        printf("Invalid user choice, you must enter rock, paper, or scissors.\n");
        continue;
    }
}
 
char* getComputerChoice() {
    srand (time(NULL));
    /* get a pseudo-random integer between 0 and 2 (inclusive) */
    int randChoice = rand() % 3;
    
    /* If randChoice is 0, return "rock"; if randChoice is 1,
     return "paper", and if randChoice is 2, return "scissors". */
    if(randChoice == 0){
        return rock;
    }
    if(randChoice == 1){
        return paper;
    }
    if(randChoice == 2){
        return scissors;
    } 
}
 
char* compare(char* choice1, char* choice2)
{
    /* Implement the logic of the game here. If choice1 and choice2
     are equal, the result should be "This game is a tie."
 
     Make sure to use strcmp for string comparison.
     */
     strcmp rock_wins = "Rock wins."
     strcmp paper_wins = "Paper wins."
     strcmp scsrs_wins = "Scissors win."
     strcmp tie_game = "This game is a tie."


     if(strcmp choice1 == strcmp choice2){
        return tie_game
     }
     if(strcmp choice1 == rock){
        if(strcmp choice2 == paper){
            return paper_wins;
        }
        if(strcmp choice2 == scissors){
            return rock_wins;
        }
     }
     if(strcmp choice1 == paper){
        if(strcmp choice2 == rock){
            return paper_wins;
        }
        if(strcmp choice2 == scissors){
            return scsrs_wins;
        }
     }
     if(strcmp choice1 == scissors){
        if(strcmp choice2 == rock){
            return rock_wins;
        }
        if(strcmp choice2 == paper){
            return scsrs_wins;
        }
     }
}
 
int main(int argc, char** argv)
{
    char *userChoice = NULL, *computerChoice = NULL, *outcome = NULL;
 
    userChoice = getUserChoice();
    computerChoice = getComputerChoice();
    outcome = compare(userChoice, computerChoice);
 
    printf("You picked %s.\n", userChoice);
    printf("Computer picked %s.\n", computerChoice);
    printf("%s\n", outcome);
 
    return 0;
}
