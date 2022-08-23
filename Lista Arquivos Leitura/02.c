/*
2. Com base no arquivo “temperatura.txt”, crie um programa que realize a
leitura das informações contidas no mesmo e apresente a maior e menor
temperatura presente no mesmo.
*/

#include <stdio.h>
#include <float.h>

int main()
{
    float maior = FLT_MIN, valor;
    FILE *arquivo;
    arquivo = fopen("temperatura.txt", "r"); // abertura de arquivo
    if (arquivo == NULL)                     // teste de abertura de arquivo
    {
        printf("Erro na abertura de arquivo.\n");
    }
    while (fscanf(arquivo, "%f", &valor) != -1) // alternativa para !feof(arquivo)
    {
        if (valor >= maior) // teste para maior valor
        {
            maior = valor;
        }
        fflush(stdin);
    }
    printf("Maior temperatura encontrada no arquivo: %0.2f\n", maior);
    fclose(arquivo);
    return 0;
}