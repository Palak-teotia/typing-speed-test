#include <stdio.h>
#include <time.h>
int main () {
    
    char sentences [100];
    float total_time;
    float words_typed;
    float correct_words;
    float accuracy;
    float wpm;
    
    time_t start, end; // time_taken calcualtion 
    time(&start);// time taken calcualtes starts here



     printf("\tTYPE THE FOLLOWING PARAGRAPH :- \n\n");
     printf("Typing is a basic skill that helps us use computers and phones faster. When we type quickly, we can finish our work in less time. Practicing daily can make our typing better. Make sure to sit straight, relax your fingers, and focus on the screen.\n\n");

     printf("START TYPING HERE :-\t");

     gets (sentences); //get input from user of the paragrapgh

     time(&end); //time_taken calcualtion stoped here
    double time_taken = difftime(end, start); // time_taken calculate in seconds
    
    printf("\nWHERE IS THE SCORE BOARD :\n");
    printf("Total time:-\t",time_taken);
    printf("\nWords typed:-\t");
    printf("\nCorrect words:-\t");
    printf("\nAccuracy %:-\t");
    printf("\nTyping speed (WPM):-\t");
   
    return 0;
}