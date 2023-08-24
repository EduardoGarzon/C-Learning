#include <stdio.h>

int main()
{
	char nome[100];
	int idade;

	FILE *teste;						// ponteiro do tipo FILE que manipula um arquivo apontando para a localizacao de seu registro
	teste = fopen("exemplo.txt", "w+"); // abrindo arquivo, nome/diretorio e modo

	if (teste == NULL)
	{ // testando abertura do arquivo
		printf("arquivo nao existe...");
		return 0;
	}

	printf("Primeira linha foi escrita no arquivo...\n");
	fprintf(teste, "primeira linha\n"); // escrita de saida formata, semelhante ao printf()

	printf("Primeira linha foi escrita no arquivo...\n");
	char frase[] = "segunda linha\n";
	fputs(frase, teste); // inserindo uma string no arquivo, variavel e ponteiro

	printf("o caracter 3 foi escrito no arquivo...\n");
	char caractere = '3';
	fputc(caractere, teste); // inserindo caracter no arquivo
	fprintf(teste, "\n");	 // escrevendo os conteudos inseridos

	printf("informe sua idade\n");
	scanf("%i", &idade);
	fprintf(teste, "%d", idade); // escrevendo a variavel idade no arquivo
	fclose(teste);				 // fechando arquivo
}