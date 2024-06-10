#include <stdlib.h>
#include <stdio.h>

void sort(int[], int);
void printArray(int[], int);

int main()
{
    // char array[] = {F, B, C, D, A}; // Tambem ordena chars
    int array[] = {9, 8, 5, 6, 0, 1, 3, 4, 7, 2};
    int size = sizeof(array) / sizeof(array[0]);

    sort(array, size);
    printArray(array, size);

    system("pause");
    return 0;
}

void sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1]) // for reverse just use <
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}