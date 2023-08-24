/* Uma matriz é uma coleção de variáveis de mesmo tipo, acessíveis com um único nome e
armazenados contiguamente na memória. A individualização de cada variável de um vetor é feita
através do uso de índices. Os Vetores são matrizes de uma só dimensão. */

int main()
{
    int matriz[5][3]; // matriz de 5 linhas e 3 colunas, 5x2;

    for (int i = 0; i < 5; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            matriz[i][x] = 10;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\n");
        for (int x = 0; x < 3; x++)
        {
            printf("%d ", matriz[i][x]);
        }
    }

    return 0;
}