#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char questions[][100] = {"1. Em que ano a linguagen C foi lancada?: ",
                             "2. Quem levou o credito por ter criado a linguagem C?: ",
                             "3. Qual era a linguagen predecessora do C?: "};

    char options[][100] = {"A. 1969", "B. 1972", "C. 1975", "D. 1999",
                           "A. Dennis Ritchie", "B. Nikola Tesla", "C. John Carmack", "D. Doc Brown",
                           "A. Objective C", "B. B", "C. C++", "D. C#"};

    char answers[3] = {'B', 'A', 'B'};

    int numberQuestions = sizeof(questions) / sizeof(questions[0]);

    char guess;
    int score = 0;

    printf("\n");
    printf("*******************\n");
    printf("QUIZ GAME\n");
    printf("*******************\n\n");

    for (int i = 0; i < numberQuestions; i++)
    {
        printf("*************************************************************\n");
        printf("%s\n", questions[i]);
        printf("*************************************************************\n");

        for (int j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf("%s\n", options[j]);
        }

        printf("\n");

        printf("Guess: ");
        scanf("%c", &guess);
        scanf("%c");

        printf("\n");

        guess = toupper(guess);

        if (guess == answers[i])
        {
            printf("CORRECT!\n");
            score++;
        }
        else
        {
            printf("WRONG!\n");
        }

        printf("\n");
    }

    printf("*************************************************************\n");
    printf("FINAL SCORE: %d/%d\n", score, numberQuestions);
    printf("*************************************************************\n");

    system("pause");
    return 0;
}