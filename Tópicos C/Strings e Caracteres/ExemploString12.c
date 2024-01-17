/*
    Utilizando strncat.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char teste[10];
    char string[10] = "Luiz";
    const char string2[] = "EduardoGarzon";

    // Concatena os n caracteres de B para A
    strncat(teste, "funcionou\n", 9);
    puts(teste);

    strncat(string, string2, 7);
    puts(string);

    system("pause");
    return 0;
}