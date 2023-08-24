// Fernando, Fabrício, Luiz Eduardo

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <string.h>

// contém um índice e um peso, representando um item a ser empacotado.
typedef struct
{
	int index;
	int peso;

} item;

// utilizada na busca tabu, guardando informações sobre as movimentações realizadas na matriz.
typedef struct
{
	int from;
	int to;
	int upgrade;
	int tabu;
} Tabela;

// muda a cor do texto para seu proximo printf (nao esqueça de mudar de volta apos)
// Esta é uma função que recebe um caractere que representa uma cor e usa a sequência de escape ANSI para mudar a cor do texto impresso no console.
void color(char color)
{
	switch (color)
	{
	case 1:
	case 'r': // red
		printf("\033[0;31m");
		break;
	case 2:
	case 'g': // green
		printf("\033[0;32m");
		break;
	case 3:
	case 'y': // yellow
		printf("\033[0;33m");
		break;
	case 4:
	case 'b': // blue
		printf("\033[0;34m");
		break;
	case 5:
	case 'p': // purple
		printf("\033[0;35m");
		break;
	case 6:
	case 'c': // cyan
		printf("\033[0;36m");
		break;
	case 7:
	case 'w': // white
		printf("\033[0;37m");
		break;
	case 8:
	case 'd': // dark aka black
		printf("\033[0;30m");
		break;
	default:
		printf("\033[0m");
	}
}

// printa uma caixa no terminal com a cor desejada
void printbox(int numero, char cor)
{
	color(cor);
	for (int i = 0; i < numero; i++)
		printf("%lc", 0x2592);
	color('n');
}

// função de comparação para qsort
// int compara(const void *a, const void *b)
//{
//	return *(item*)b->peso - *(item*)a->peso;
//}

// função para atualizar os totais de todas as caixas se necessário
// 17 -  atualiza a coluna 0 de uma matriz m com o total de cada linha da matriz.
// A função percorre cada linha da matriz usando um loop for. Para cada linha, um loop for interno percorre cada coluna da matriz (exceto a primeira coluna) e soma os pesos dos itens dessa linha. O resultado é armazenado na primeira coluna da linha usando m[i][0].peso = total;.
void refreshTotal(item **m, int lin, int col)
{
	for (int i = 0; i < lin; i++)
	{
		int total = 0;
		for (int j = 1; j <= col; j++)
			total += m[i][j].peso;
		m[i][0].peso = total;
	}
}

// 10 - ESTRATEGIA GULOSA
// os itens em v são distribuidos nas caixas em m
// percorre os itens em ordem decrescente de peso.
// tenta encaixá-los em uma das caixas já preenchidas, escolhendo a caixa que tem a maior capacidade restante.
// Se nenhuma caixa atender aos requisitos, é criada uma nova caixa.
// vetor de itens "vetor", uma matriz de itens "matriz", o tamanho do vetor "Tamanhovetor", o número de linhas da matriz "linhamatriz" e o número de colunas da matriz "colunamatriz".
void gulosa(item *vetor, item **matriz, int Tamanhovetor, int linhamatriz, int colunamatriz)
{
	// percorre todos os itens do vetor de entrada
	for (int i = 0; i < Tamanhovetor; i++)
	{
		// Para cada item, um loop interno percorre todas as linhas da matriz.
		for (int j = 0; j < linhamatriz; j++)
		{
			// Para cada linha, é verificado se o peso do item atual pode ser alocado na coluna seguinte, sem ultrapassar o limite de peso da coluna.
			if (colunamatriz - matriz[j][0].peso >= vetor[i].peso)
			{
				// o peso da primeira posição da linha é atualizado para incluir o peso do item atual, e o item é inserido na primeira coluna disponível da linha.
				matriz[j][0].peso += vetor[i].peso;
				for (int y = 1; y <= colunamatriz; y++)
					if (matriz[j][y].peso == 0)
					{
						matriz[j][y] = vetor[i];
						break;
					}
				// o peso da primeira posição da linha é atualizado para incluir o peso do item atual, e o item é inserido na primeira coluna disponível da linha.
				break;
			}
		}
	}
}

// 8 - EMBARALHA O VETOR DE ITENS, trocas aleatórias de elementos do vetor
// O tamanho do vetor é usado para gerar números aleatórios que serão usados para selecionar pares de elementos para trocar.
void shuffle(item *vetor, size_t Tamanho)
{
	if (Tamanho > 1)
	{
		// No primeiro loop, os elementos de peso do vetor são trocados aleatoriamente.
		// A variável i é usada como índice para percorrer o vetor e a variável j é calculada aleatoriamente dentro do intervalo [i, Tamanho-1].
		// os elementos de peso nos índices i e j são trocados entre si.
		for (size_t i = 0; i < Tamanho - 1; i++)
		{
			size_t j = i + rand() % (Tamanho - i);
			int t = vetor[j].peso;
			vetor[j].peso = vetor[i].peso;
			vetor[i].peso = t;
		}
		// No segundo loop, os elementos de índice do vetor são trocados aleatoriamente.
		for (size_t i = 0; i < Tamanho - 1; i++)
		{
			size_t j = i + rand() % (Tamanho - i);
			int t = vetor[j].index;
			vetor[j].index = vetor[i].index;
			vetor[i].index = t;
		}
	}
}

// FINAL -printa a matriz como se fosse caixa bonito🗃️
// O loop for externo percorre cada linha da matriz. Caso o peso da primeira coluna da linha (índice 0) seja diferente de zero, ou seja, há pelo menos um item na caixa, então a função imprime o número da caixa e a representação dos itens.
// O loop for interno percorre cada coluna da linha e chama a função printbox para imprimir a representação visual do item presente naquela posição da matriz
// Em seguida, a função chama novamente a função printbox para imprimir o espaço vazio da caixa até atingir o seu peso máximo (coluna), que é coluna - matriz[i][0].peso. Por fim, é impresso o total de peso da caixa.
void printboxes(item **matriz, int linha, int coluna)
{
	for (int i = 0; i < linha; i++)
	{
		if (matriz[i][0].peso != 0)
		{
			printf("Box %2d:|", i + 1);
			for (int j = 1; j <= coluna; j++)
				printbox(matriz[i][j].peso, (j % 7) + 1);
			printbox(coluna - matriz[i][0].peso, 8);
			printf("| total: %d\n", matriz[i][0].peso);
		}
	}
}

// 15, 16 Tira o item de uma caixa e coloca em outra
// os índices "from" e "to" que representam as linhas da matriz de onde e para onde o item será movido
void swap(item **matriz, int iten, int from, int to, int linhas, int colunas)
{
	// A função começa criando duas variáveis "aux" e "aux2" do tipo "item" com valores nulos.
	item aux = {0, 0}, aux2 = {0, 0};

	for (int i = colunas; i > 0; i--) // percorre a linha "from" da matriz, iniciando na última coluna e indo até a primeira.
	{
		// Em cada iteração, a função copia os valores do item atual para a variável "aux" e os valores da variável "aux2" para o item atual.
		aux.index = matriz[from - 1][i].index;
		aux.peso = matriz[from - 1][i].peso;

		matriz[from - 1][i].index = aux2.index;
		matriz[from - 1][i].peso = aux2.peso;

		aux2.index = aux.index;
		aux2.peso = aux.peso;
		if (aux.index == iten)
			break;
	}

	for (int i = 1; i <= colunas; i++) //  percorre a linha "to" da matriz, iniciando na primeira coluna e indo até a última
	{
		//  Em cada iteração, ela procura a primeira coluna vazia na linha e insere os valores da variável "aux".
		if (matriz[to - 1][i].peso == 0)
		{
			matriz[to - 1][i].peso = aux.peso;
			matriz[to - 1][i].index = aux.index;
			break;
		}
	}
	// Em resumo, a função "swap" troca a posição de um item em duas linhas diferentes da matriz.
	// 17
	refreshTotal(matriz, linhas, colunas);
}

// 14 - calcula os melhores vizinhos de cada item
void calculaVizinhos(item **matriz, int linha, int coluna, Tabela *vetor)
{
	// A função "calculaVizinhos" ajuda a resolver um problema específico relacionado a encontrar a melhor combinação de elementos na matriz, levando em consideração o peso e o número de elementos permitidos em cada linha.
	// O primeiro loop "for" itera através de cada linha da matriz e o segundo loop "for" itera através de cada coluna.
	for (int i = 0; i < linha; i++)
	{
		for (int j = 1; j <= coluna; j++)
		{
			if (matriz[i][j].peso != 0) // Se o peso do item na posição atual da matriz é diferente de zero, significa que há um item naquela posição
			{
				int index = matriz[i][j].index;
				for (int k = 0; k < linha; k++)
				{
					if (k == i)
						continue;
					// se a soma do peso do item atual com o peso do primeiro item na linha atual é menor ou igual à variável "coluna", um swap é feito entre o item atual e o item na linha atual.
					if (matriz[i][j].peso + matriz[k][0].peso <= coluna)
					{
						int max;
						if (matriz[i][0].peso > matriz[k][0].peso)
							max = matriz[i][0].peso;
						else
							max = matriz[k][0].peso;
						// 15
						swap(matriz, index, i + 1, k + 1, linha, coluna); // Após o swap, é calculado o valor máximo do peso da linha atual e do peso da linha da posição atual.
						int newmax;
						if (matriz[i][0].peso > matriz[k][0].peso)
							newmax = matriz[i][0].peso;
						else
							newmax = matriz[k][0].peso;
						// 16
						swap(matriz, index, k + 1, i + 1, linha, coluna); // Em seguida, é feito outro swap e é calculado o novo valor máximo de peso.
						// Se a diferença entre os valores máximos de peso antes e depois do swap for maior que o valor armazenado na variável "upgrade" da estrutura correspondente no vetor "vetor", a estrutura é atualizada com o índice da linha atual e a linha de destino e o valor da diferença de peso.
						if (vetor[index - 1].upgrade < newmax - max)
						{
							vetor[index - 1].from = i;
							vetor[index - 1].to = k;
							vetor[index - 1].upgrade = newmax - max;
						}
					}
				}
			}
			else
				break;
		}
	}
}

// 13 TABU - realizar a busca tabu para otimizar a solução encontrada pela heurística gulosa.
int fazTabu(item **matriz, int linha, int coluna, item **melhor)
{
	int aspira = 0, totalmelhor = 0, totalatual = 0;

	// armazenar informações sobre cada item, como o melhor vizinho, o tempo em que o item ficará na lista tabu e a quantidade de melhorias realizadas.
	Tabela *tablete = (Tabela *)malloc(sizeof(Tabela) * linha);

	// preencher uma área de memória com um determinado valor.
	// memset está preenchendo a área de memória apontada pelo ponteiro tablete com zeros, para garantir que os campos da estrutura Tabela sejam inicializados com valores válidos.
	memset(tablete, 0, sizeof(Tabela) * linha);

	// atualizar as informações do vetor tablete com os melhores vizinhos de cada item na matriz m
	// 14
	calculaVizinhos(matriz, linha, coluna, tablete);

	for (int i = 0; i < linha; i++)
		tablete[i].tabu = 0;
	int menospior = 0, meiopior = 0;

	//  percorre todos os itens da matriz e encontra o item com a maior quantidade de melhorias (maior valor no campo upgrade de tablete) e o item com a segunda maior quantidade de melhorias, encontra as duas soluções mais problemáticas
	for (int i = 0; i < linha; i++)
	{
		if (tablete[i].upgrade > tablete[menospior].upgrade)
			menospior = i;
		else if (tablete[i].upgrade > tablete[meiopior].upgrade)
			meiopior = i;
	}

	//  Se a primeira melhor solução é pelo menos duas vezes melhor que a segunda e se a troca desse item para outro lugar na matriz não ultrapassar a capacidade da mochila (somatório dos pesos dos itens na linha da matriz é menor ou igual à coluna), então a troca é realizada imediatamente. "aspiração", que permite que a solução seja melhorada mesmo que ela esteja na lista tabu.
	if (tablete[menospior].upgrade >= 2 * tablete[meiopior].upgrade && matriz[tablete[menospior].to + 1][0].peso + matriz[tablete[menospior].from + 1][0].peso <= coluna)
	{
		swap(matriz, menospior + 1, tablete[menospior].from + 1, tablete[menospior].to + 1, linha, coluna);
		aspira = 1;
	}
	// verifica se a primeira melhor solucao não está na lista tabu e se não ultrapassa a capacidade da mochila. Se essas condições forem atendidas, então a troca é realizada.
	else if (tablete[menospior].tabu <= 0 && matriz[tablete[menospior].to + 1][0].peso + matriz[tablete[menospior].from + 1][0].peso <= coluna)
	{
		tablete[menospior].tabu = 4;
		swap(matriz, menospior + 1, tablete[menospior].from + 1, tablete[menospior].to + 1, linha, coluna);
	}
	// Se não, a segunda melhor solução é verificada e, se a troca for possível, é realizada.
	else if (matriz[tablete[meiopior].to + 1][0].peso + matriz[tablete[meiopior].from + 1][0].peso <= coluna)
	{
		tablete[menospior].tabu = 4;
		swap(matriz, meiopior + 1, tablete[meiopior].from + 1, tablete[meiopior].to + 1, linha, coluna);
	}

	// O loop seguinte percorre novamente todos os itens da matriz para atualizar a variável totalatual, que armazena a quantidade de itens na solução atual. Se algum item ultrapassar a capacidade da mochila, totalatual recebe um valor alto (9999).
	for (int i = 0; i < linha; i++)
	{
		if (melhor[i][0].peso != 0)
			totalmelhor++;
		if (matriz[i][0].peso > coluna)
		{
			totalatual = 9999;
			break;
		}
		else if (matriz[i][0].peso != 0)
		{
			totalatual++;
		}
	}

	// compara totalatual com totalmelhor para verificar se a solução atual é melhor que a melhor solução encontrada até o momento. Se for, a matriz atual é copiada para melhor.
	if (totalatual < totalmelhor)
		for (int i = 0; i < linha; i++)
			for (int j = 0; j <= coluna; j++)
				melhor[i][j] = matriz[i][j];

	// decrementa o tempo em que cada item ficará na lista tabu
	for (int i = 0; i < linha; i++)
		tablete[i].tabu--;

	//  indicar se a solução atual foi melhorada através da técnica de aspiração.
	// 	aspira é definida como 1 significa que a solução atual foi melhorada mesmo que estivesse na lista tabu.
	// Se a solução atual foi melhorada através da técnica de aspiração, então ela não é adicionada à lista tabu, pois a solução foi considerada suficientemente boa para ser explorada novamente no futuro. Se a solução atual não foi melhorada através da técnica de aspiração, então ela é adicionada à lista tabu.
	return aspira;
}

// ./pacote\ 1d.x PEU1.txt
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "en_US.UTF-8");
	srand(time(NULL));

	int TamanhoPacote, nItens, total = 0, iteracoes;
	char loop = 'c';

	printf("Numero de iterações maxima: ");
	scanf("%d", &iteracoes);

	// 1 - LEITURA DO ARQUIVO PARA TAMANHO DO PACOTE E NUMERO DE ITENS

	FILE *p = fopen(argv[1], "r"); // argumento no terminal é nome do arquivo com as informacoes

	fscanf(p, "%d\n%d", &TamanhoPacote, &nItens);

	// 2 - CRIACAO DE UM VETOR DE ITENS DE ESTRUTURAS DE DADOS COM INDEX E PESO

	// int v[nItens];
	item *v = (item *)malloc(sizeof(item *) * nItens);

	// 3 - CRIACAO DE UMA MATRIZ PARA REPRESENTAR AS CAIXAS
	// COLUNA 0 É O PESO DE CADA CAIXA, COLUNA + 1 REPRESENTA OS ITENS DA CAIXA
	// CADA LINHA REPRESENTA UMA CAIXA

	// int m[nItens][TamanhoPacote + 1];
	item **m = (item **)malloc(sizeof(item **) * nItens);
	for (int i = 0; i < nItens; i++)
		m[i] = (item *)malloc(sizeof(item *) * (TamanhoPacote + 1));

	// 4 - 	MATRIZ IDENTICA A DE CIMA ARMAZENA O SUBCONJUNTO DE DADOS A SEREM SELECIONADOS
	item **melhor = (item **)malloc(sizeof(item **) * nItens);
	for (int i = 0; i < nItens; i++)
		melhor[i] = (item *)malloc(sizeof(item *) * (TamanhoPacote + 1));

	// 5 - INICIALIZA OS ITENS DAS CAIXAS COM PESO E INDEX 0
	for (int i = 0; i < nItens; i++)
		for (int j = 0; j <= TamanhoPacote; j++)
		{
			m[i][j].index = 0;
			m[i][j].peso = 0;
		}

	// 6 - INICIALIZA OS INDEX E PESOS DE CADA ITEM DO VETOR DE ITENS
	for (int i = 0; i < nItens; i++)
	{
		v[i].index = i + 1;
		fscanf(p, "%d", &v[i].peso);
	}

	fclose(p);

	// 7 - EMBARALHA O VETOR DE ITENS
	// Depois de aplicar a função shuffle() no vetor de itens, cada elemento pode assumir um peso e um índice diferentes do que tinha originalmente. Isso porque a função troca aleatoriamente os valores dos campos "peso" e "índice" de cada elemento do vetor.
	shuffle(v, nItens);

	// sort decrescente
	// qsort(v, nItens, sizeof(item), compara);

	// 9 - O objetivo é colocar o maior número possível de itens em uma caixa, sem exceder a capacidade máxima da caixa.
	gulosa(v, m, nItens, nItens, TamanhoPacote);

	// 11 - o código copia a matriz "m" para a matriz "melhor", para que seja possível comparar as soluções encontradas e verificar qual é a melhor solução. Assim, ao final do código, a matriz "melhor" contém a melhor solução encontrada pela abordagem gulosa.
	for (int i = 0; i < nItens; i++)
		for (int j = 0; j <= TamanhoPacote; j++)
			melhor[i][j] = m[i][j];
	// teste da função swap
	// swap(m, 2, 1, 2, nItens, TamanhoPacote);

	system("clear");

	// 12 - TABU - PROXIMA ITERACAO OU EXIBIR MELHOR SOLUCAO ATE O MOMENTO
	for (int i = 0; i < iteracoes; i++)
	{
		total += fazTabu(m, nItens, TamanhoPacote, melhor);
		// se a variável "loop" é igual a 'c' é exibida a matriz "m" na tela, e o usuário é solicitado a escolher se deseja continuar para a próxima iteração ('c') ou apenas exibir a melhor solução encontrada até o momento ('m').
		if (loop == 'c')
		{
			printboxes(m, nItens, TamanhoPacote);
			printf("Proxima iteração [c] ou somente melhor solução [m]: ");
			scanf("\n%c", &loop);
			system("clear");
		}
		if (total == 50)
			break;
	}

	// FINAL
	printboxes(melhor, nItens, TamanhoPacote);

	for (int i = 0; i < nItens; i++)
		free(m[i]);

	free(m);
	free(v);

	return 0;
}
