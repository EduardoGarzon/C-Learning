// Array de structs.

#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char nome[25];
    int idade;
};

int main()
{
    struct Student student1 = {"Luiz", 20};
    struct Student student2 = {"Carlos", 21};
    struct Student student3 = {"Pedro", 22};
    struct Student student4 = {"Marcos", 23};

    struct Student students[4] = {student1, student2, student3, student4};

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++)
    {
        printf("Student: %d\n", i);
        printf("%s | %d\n", students[i].nome, students[i].idade);
        printf("\n");
    }

    system("pause");
    return 0;
}