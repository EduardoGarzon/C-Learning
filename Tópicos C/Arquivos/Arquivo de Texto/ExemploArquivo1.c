// Exemplo de utilizacao de arquivo em C.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char nome[100];
	int idade;

	// ponteiro do tipo FILE que manipula um arquivo
	// apontando para a localizacao de seu registro
	FILE *teste;
	teste = fopen("exemplo.txt", "w+"); // abrindo arquivo, nome/diretorio e modo

	// testando abertura do arquivo
	if (teste == NULL)
	{
		printf("Arquivo nao existe...\n");
		return 1;
	}

	printf("Primeira linha foi escrita no arquivo...\n");
	fprintf(teste, "primeira linha\n"); // escrita de saida formata, semelhante ao printf()

	printf("Primeira linha foi escrita no arquivo...\n");
	char frase[] = "segunda linha\n";
	fputs(frase, teste); // inserindo uma string no arquivo, variavel e ponteiro

	printf("O caracter 3 foi escrito no arquivo...\n");
	char caractere = '3';
	fputc(caractere, teste); // inserindo caracter no arquivo
	fprintf(teste, "\n");	 // escrevendo os conteudos inseridos

	printf("Informe sua idade\n");
	scanf("%d", &idade);
	fprintf(teste, "%d", idade); // escrevendo a variavel idade no arquivo
	fclose(teste);				 // fechando arquivo

	system("pause");
	return 0;
}