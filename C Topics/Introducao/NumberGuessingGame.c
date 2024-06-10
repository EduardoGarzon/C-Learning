#include <stdio.h>
#include <stdlib.h>

int main()
{

    const int MIN = 1;
    const int MAX = 100;
    int guess;
    int guesses;
    int answer;

    srand(time(NULL));

    answer = (rand() % MAX) + MIN;

    do
    {
        printf("Enter a guess: ");
        scanf("%d", &guess);

        printf("\n");

        if (guess > answer)
        {
            printf("Too high!\n");
        }
        else if (guess < answer)
        {
            printf("Too low!\n");
        }
        else
        {
            printf("CORRECT!\n");
        }

        printf("\n");

        guesses++;
    } while (guess != answer);

    printf("\n");

    printf("The answer: %d\n", answer);
    printf("Total Guesses: %d\n", guesses);

    system("pause");
    return 0;
}