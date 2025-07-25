#include <stdio.h>
#include <string.h>
#include <time.h>

// Function to run typing test
void run_test(char paragraph[]) {
    char sentences[2000];
    double time_taken;
    int word_count = 0, wrong = 0, typed_words = 0;
    float accuracy, wpm;

    printf("\n\tTYPE THE FOLLOWING PARAGRAPH :- \n\n%s\n\n", paragraph);
    printf("START TYPING HERE:\n");

    time_t start, end;
    time(&start);
    fgets(sentences, sizeof(sentences), stdin);
    time(&end);

    time_taken = difftime(end, start);

    // Count words in original
    char orig_copy[2000];
    strcpy(orig_copy, paragraph);
    char *temp = strtok(orig_copy, " ");
    while (temp != NULL) {
        word_count++;
        temp = strtok(NULL, " ");
    }

    // Compare words
    char typed_copy[2000];
    strcpy(orig_copy, paragraph);
    strcpy(typed_copy, sentences);

    char *orig_token = strtok(orig_copy, " ");
    char *typed_token = strtok(typed_copy, " ");

    while (orig_token != NULL) {
        if (typed_token != NULL && strcmp(orig_token, typed_token) != 0) {
            wrong++;
        }
        orig_token = strtok(NULL, " ");
        if (typed_token != NULL)
            typed_token = strtok(NULL, " ");
    }

    // Count typed words
    for (int i = 0; sentences[i] != '\0'; i++) {
        if (sentences[i] == ' ' || sentences[i] == '\n') {
            typed_words++;
        }
    }
    typed_words++;

    float minutes = time_taken / 60.0;
    wpm = typed_words / minutes;
    accuracy = ((float)(word_count - wrong) / word_count) * 100;

    // Output
    printf("\n\n====== SCORE BOARD ======\n");
    printf("Time Taken (seconds):\t%.2lf\n", time_taken);
    printf("Words Typed:\t\t%d\n", typed_words);
    printf("Wrong Words:\t\t%d\n", wrong);
    printf("Accuracy:\t\t%.2f%%\n", accuracy);
    printf("Typing Speed:\t\t%.2f WPM\n", wpm);

    if(wpm >= 80) {
        printf("\n====== EXCELLENT!! =========\n");
    } else if(wpm >= 70) {
        printf("\n====== GOOD!! =======\n");
    } else if(wpm >= 50) {
        printf("\n======= NICE!!  =========\n");
    } else if(wpm >= 40) {
        printf("\n======  NOT BAD BUT DO PRACTICE....=======\n");
    } else {
        printf("\n ======= YOU NEED TO PRACTICE DAILY TO IMPROVE YOUR TYPING SPEED ... =======\n");
    }
}

int main() {
    char user_input;
    char easy_para[] = "Typing is a basic skill that helps us use computers and phones faster. When we type quickly, we can finish our work in less time. Practicing daily can make our typing better. Make sure to sit straight, relax your fingers, and focus on the screen.";

    char inter_para[] = "In today's digital world, typing is not just a skill but a necessity. Students, professionals, and even content creators rely on fast and accurate typing to increase their productivity. Consistent practice not only improves speed but also builds confidence while using a keyboard.";


    printf("\n===== TYPING SPEED TEST - SELECT YOUR LEVEL =====\n");
    printf("(a) EASY LEVEL\n(b) INTERMEDIATE LEVEL\n");
    printf("Enter your choice: ");
    scanf(" %c", &user_input);  // Space before %c to skip newline
    while(getchar() != '\n'); // clear input buffer

    if(user_input == 'a' || user_input == 'A') {
        printf("\n===== YOU SELECTED EASY LEVEL =====\n");
        run_test(easy_para);
    } else if(user_input == 'b' || user_input == 'B') {
        printf("\n===== YOU SELECTED INTERMEDIATE LEVEL =====\n");
        run_test(inter_para);
    } else {
        printf("Invalid selection.\n");
    }

    return 0;
}



