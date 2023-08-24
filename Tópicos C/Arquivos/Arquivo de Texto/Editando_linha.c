#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    long pos, tam, tamcp;
    char *copia = NULL;
    
    //Temos um arquivo com o texto "Hello World 123"
    FILE *f = fopen("teste.txt", "w");
    fprintf(f, "Hello World 123\n");
    fclose(f);
    
    
    //Agora vamos alterar o texto para "Hello ABC 123"
    f = fopen("teste.txt", "r+");
    
    fseek(f, 0, SEEK_END); //Manda o cursor para o fim do arquivo
    tam = ftell(f); //A posição final é igual ao tamanho do arquivo
    rewind(f); //Volta para o início do arquivo
    
    //Salva a posição atual e lê a proxima palavra, até encontrar a
    //palavra a ser substituida, no nosso exemplo seria "World".
    //O ciclo para quando encontrar a palavra, e a variável pos terá  
    //o número da posição onde a palavra "World" começa:
    pos = ftell(f);
    while(fscanf(f, "%s%*c", s) == 1 && strcmp(s, "World") != 0){
        pos = ftell(f);
    }
    
    
    tamcp = tam - ftell(f); //tamanho de tudo que vem após a palavra "World"
    copia = malloc(tamcp); //Aloca um vetor para copiar tudo que vem depois de "World"
    fread(copia, tamcp, 1, f); //Copia tudo que vem depois de "World" até o fim do arquivo
    
    fseek(f, pos, SEEK_SET); //Volta para a posição onde a palavra "World" começa
    fprintf(f, "%s", "ABC "); //Sobrepõe com o novo texto "ABC "
    
    fwrite(copia, tamcp, 1, f); //Reescreve tudo que foi copiado
    free(copia); //Libera memória alocada dinamicamente pois não é mais necessária
    
    //Se o novo texto é menor que o original, ficam sobrando caracteres
    //no fim do arquivo, como é acontece nesse exemplo pois "ABC" tem 3 letras,
    //mas "World" tinha 5, então escolhi sobrepor os carateres finais com
    //espaços em branco:
    for(pos = ftell(f); pos < tam; pos++){
        fputc(' ', f);
    }
    
    fclose(f); //Alteração do texto finalizada
    
    
    //Agora podemos verificar o resultado:
    f = fopen("teste.txt", "r");
    while(fscanf(f, "%[^\n]", s) == 1){
        printf("%s\n", s);
    }
    fclose(f);
    
    return 0;
}