#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() {
    char sentences[1000]; 
    double time_taken;
    int word_count = 0;
    int wrong = 0;
    float accuracy, wpm;

    time_t start, end;

    // paragraph
    char original[] = "Typing is a basic skill that helps us use computers and phones faster. When we type quickly, we can finish our work in less time.Practicing daily can make our typing better.Make sure to sit straight, relax your fingers, and focus on the screen.";

    printf("\n\tTYPE THE FOLLOWING PARAGRAPH :- \n\n");
    printf("%s\n\n", original);

    printf("START TYPING HERE:\n");

    time(&start); // Start timer
    fgets(sentences, sizeof(sentences), stdin); 
    time(&end);   // End timer

    time_taken = difftime(end, start); // Total time in seconds

    // Create modifiable copies
    char orig_copy[1000];
    char typed_copy[1000];
    strcpy(orig_copy, original);
    strcpy(typed_copy, sentences);

    // Count total words in original paragraph
    char *temp = strtok(orig_copy, " ");
    while (temp != NULL) {
        word_count++;
        temp = strtok(NULL, " ");
    }

    // Reset and compare each word
    strcpy(orig_copy, original); // reset again for tokenizing
    char *orig_token = strtok(orig_copy, " ");
    char *typed_token = strtok(typed_copy, " ");

    char corrected_para[1000] = ""; // to store final corrected para

    while (orig_token != NULL) {
        if (typed_token != NULL && strcmp(orig_token, typed_token) == 0) {
            strcat(corrected_para, orig_token);
            strcat(corrected_para, " ");
        } else {
            wrong++;
        }

        orig_token = strtok(NULL, " ");
        if (typed_token != NULL)
            typed_token = strtok(NULL, " ");
    }

    // Accuracy and WPM
    accuracy = ((float)(word_count - wrong) / word_count) * 100;
    float minutes = time_taken / 60.0;
    int typed_words = 0;

    // Count typed words
    for (int i = 0; sentences[i] != '\0'; i++) {
        if (sentences[i] == ' ' || sentences[i] == '\n') {
            typed_words++;
        }
    }
    typed_words++; // last word

    wpm = typed_words / minutes;

    // Show results
    printf("\n\n====== SCORE BOARD ======\n");
    printf("Time Taken (seconds):\t%.2lf\n", time_taken);
    printf("Words Typed:\t\t%d\n", typed_words);
    printf("Wrong Words:\t\t%d\n", wrong);
    printf("Accuracy:\t\t%.2f%%\n", accuracy);
    printf("Typing Speed:\t\t%.2f WPM\n", wpm);

    if(wpm >= 40 && wpm < 50 ){
        printf("\n======  NOT BAD BUT DO PRACTICE....=======");
    }

    else if(wpm >= 50 && wpm < 70 ){
        printf("\n======= NICE!!  =========");
    }

    else if(wpm >=70 && wpm < 80 ){
        printf("\n====== GOOD!! =======");
    }

    else if(wpm >= 80) {
    printf("\n====== EXCELLENT!! =========");
    }


    else {
        printf("\n ======= YOU NEED TO PRACTICE DAILY TO IMPROVE YOUR TYPING SPEED ... =======");
    }

    return 0;
}


