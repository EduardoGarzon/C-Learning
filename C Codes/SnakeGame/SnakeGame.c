#include <stdio.h>
#include <stdlib.h>

int N = 20;               // rows
int M = 40;               // columns
int i, j;                 // for the field
int Field[20][40];        // Field Positions
int x, y, Gy, Head, Tail; // Snake

void StartSnake()
{
    for (i = 0; i < N; i++) // all game area set to 0
    {
        for (j = 0; j < M; j++)
        {
            Field[i][j] = 0;
        }
    }

    x = N / 2;
    y = M / 2;
    Gy = y;
    Head = 5;
    Tail = 1;

    for (i = 0; i < Head; i++)
    {
        Gy++;
        Field[x][Gy - Head] = i + 1;
    }
}

void print_field()
{
    for (i = 0; i <= M + 1; i++) // top field
    {
        if (i == 0)
        {
            printf("%c", 201);
        }
        else if (i == M + 1)
        {
            printf("%c", 187);
        }
        else
        {
            printf("%c", 205);
        }
    }
    printf("\n");
    for (i = 0; i < N; i++) // rows
    {
        printf("%c", 186);
        for (j = 0; j < M; j++)
        {
            if (Field[i][j] == 0)
            {
                printf(" ");
            }
            if (Field[i][j] > 0 && Field[i][j] != 0)
            {
                printf("%c", 176);
            }
            if (Field[i][j] == Head)
            {
                printf("%c", 178);
            }
            if (j == 39)
            {
                printf("%c\n", 186);
            }
        }
    }
    for (i = 0; i <= M + 1; i++) // bottle field
    {
        if (i == 0)
        {
            printf("%c", 200);
        }
        else if (i == M + 1)
        {
            printf("%c", 188);
        }
        else
        {
            printf("%c", 205);
        }
    }
}

int main()
{
    StartSnake();
    print_field();
}