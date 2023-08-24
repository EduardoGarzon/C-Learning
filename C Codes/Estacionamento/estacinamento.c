#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct // struct dos horarios e datas de entrada e saida
{
    int Hentrada, Mentrada, Hsaida, Msaida; // horario de entrada e saida
    int dia_entrada, mes_entrada, ano_entrada;
    int dia_saida, mes_saida, ano_saida; // data de entrada e saida
} tempos;

struct estacionamento // struct para as vagas do estacionamento
{
    tempos datas;  // struct tempo que contem as datas e horarios das vagas ocupadas
    int status;    // status da vaga
    char placa[7]; // placa do carro de 7 digitos
} vagas[10];

float pagamento(int Hduracao, int Mduracao, int dia_total, int mes_total, int ano_total)
{
    float valor = 0;

    if (ano_total == 0) // condicao: mesmo ano, mes e dia
    {
        if (mes_total == 0)
        {
            if (dia_total == 0)
            {
                if ((Hduracao <= 12 && Mduracao == 0)) // ate 12 horas
                {
                    valor = 10 + (5 * Hduracao);
                }
                else if ((Hduracao <= 11 && Mduracao <= 59)) // ate 12 horas
                {
                    valor = 10 + (5 * Hduracao) + (0.08333 * Mduracao);
                }
                else if ((Hduracao >= 12 && Hduracao <= 23) && (Mduracao >= 0 && Mduracao <= 59))
                // acima de 12 e abaixo de 24 horas
                {
                    valor = 100 + (5 * Hduracao) + (0.08333 * Mduracao);
                }
                else
                {
                    valor = 0;
                }
            }
        }
    }

    if (ano_total == 0) // condicao: mesmo ano e mes, dias diferentes
    {
        if (mes_total == 0)
        {
            if (dia_total > 0)
            {
                if (Hduracao == 24 && Mduracao == 0) // 24 horas
                {
                    valor = (5 * 24) + (dia_total * 150);
                }
                else if ((Hduracao <= 12 && Mduracao == 0)) // ate 12 horas
                {
                    valor = (5 * Hduracao) + (dia_total * 150);
                }
                else if ((Hduracao <= 11 && Mduracao <= 59)) // ate 12 horas
                {
                    valor = (5 * Hduracao) + (0.08333 * Mduracao) + (dia_total * 150);
                }
                else if ((Hduracao >= 12 && Hduracao <= 23) && (Mduracao >= 0 && Mduracao <= 59))
                // acima de 12 horas e abaixo de 24 horas
                {
                    valor = (5 * Hduracao) + (0.08333 * Mduracao) + (dia_total * 150);
                }
                else
                {
                    valor = 0;
                }
            }
        }
    }

    if (ano_total == 0) // condicao: mesmo ano, mes e dia diferentes
    {
        if (mes_total > 0)
        {
            if (Hduracao == 24 && Mduracao == 0) // 24 horas
            {
                valor = (5 * Hduracao) + (150 * dia_total);
            }
            else if ((Hduracao <= 12 && Mduracao == 0)) // ate 12 horas
            {
                valor = (5 * Hduracao) + (dia_total * 150);
            }
            else if ((Hduracao <= 11 && Mduracao <= 59)) // ate 12 horas
            {
                valor = (5 * Hduracao) + (0.08333 * Mduracao) + (dia_total * 150);
            }
            else if ((Hduracao >= 12 && Hduracao <= 23) && (Mduracao >= 0 && Mduracao <= 59))
            // acima de 12 horas e abaixo de 24 horas
            {
                valor = (5 * Hduracao) + (0.08333 * Mduracao) + (dia_total * 150);
            }
            else
            {
                valor = 0;
            }
        }
    }

    if (ano_total > 0) // condicao: mesmo ano, mes e dia diferentes
    {
        if (mes_total > 0)
        {
            if (Hduracao == 24 && Mduracao == 0) // 24 horas
            {
                valor = (5 * Hduracao) + ((mes_total * 31) * 150);
            }
            else if ((Hduracao <= 12 && Mduracao == 0)) // ate 12 horas
            {
                valor = (5 * Hduracao) + ((mes_total * 31) * 150);
            }
            else if ((Hduracao <= 11 && Mduracao <= 59)) // ate 12 horas
            {
                valor = (5 * Hduracao) + (0.08333 * Mduracao) + ((mes_total * 31) * 150);
            }
            else if ((Hduracao >= 12 && Hduracao <= 23) && (Mduracao >= 0 && Mduracao <= 59))
            // acima de 12 horas e abaixo de 24 horas
            {
                valor = (5 * Hduracao) + (0.08333 * Mduracao) + ((mes_total * 31) * 150);
            }
            else
            {
                valor = 0;
            }
        }
    }

    return valor;
}

float tempo(struct estacionamento vagas) // funcao que calcula o tempo permanecido
{
    int Hduracao = vagas.datas.Hsaida - vagas.datas.Hentrada;        // horas totais
    int Mduracao = vagas.datas.Msaida - vagas.datas.Mentrada;        // minutos totais
    int dia_total = vagas.datas.dia_saida - vagas.datas.dia_entrada; // dias percorridos
    int mes_total = vagas.datas.mes_saida - vagas.datas.mes_entrada; // meses percorridos
    int ano_total = vagas.datas.ano_saida - vagas.datas.ano_entrada; // anos percorridos

    if (Hduracao > 0 && Mduracao < 0) // Minutos negativos e Horas Positivos
    {                                 // Horas e minutos
        Hduracao -= 1;
        Mduracao += 60;
    }
    else if (Hduracao < 0 && Mduracao >= 0 || Hduracao == 0 && Mduracao == 0)
    { // dias completos e dias incompletos
        Hduracao += 24;
    }
    else if (Hduracao == 0 && Mduracao < 0 || Hduracao < 0 && Mduracao < 0)
    { // dias completos e dias incompletos
        Hduracao += 23;
        Mduracao += 60;
    }

    if (mes_total > 0 && ano_total == 0) // total de dias pela diferenca dos meses no mesmo ano
    {
        int x = vagas.datas.dia_saida;
        int y = vagas.datas.dia_entrada;

        int w = vagas.datas.mes_saida;
        int o = vagas.datas.mes_entrada;

        int z = 0;
        int ok = 0;

        while (ok == 0)
        {
            if (o < w)
            {
                if (y == 31)
                {
                    y = 1;
                    o += 1;
                    z++;
                }
                else
                {
                    y += 1;
                    z++;
                }
            }

            if (o == w)
            {
                if (y == x)
                {
                    ok = 1;
                }
                else
                {
                    y++;
                    z++;
                }
            }
        }
        dia_total = z;
    }

    if (ano_total > 0) // anos diferentes
    {
        int w = vagas.datas.mes_saida;
        int o = vagas.datas.mes_entrada;

        int a = vagas.datas.ano_entrada;
        int b = vagas.datas.ano_saida;

        int z = 0;

        if ((a < b && o > w)) // anos diferentes com mes de entrada maior que o mes de saida
        {
            while (a != b && o != w)
            {
                if (o == 12)
                {
                    o = 1;
                    a++;
                    z++;
                }
                else
                {
                    o++;
                    z++;
                }
            }

            mes_total = z;
        }
        else if ((a < b && o < w)) // anos diferentes, mes de entrada menor que o de saida
        {
            while (a < b && o < w)
            {
                if (o < 12 && a < b)
                {
                    o++;
                    z++;
                }
                else if (o == 12 && a < b)
                {
                    o = 1;
                    a = b;
                    z++;
                }
                else if (o < w && a == b)
                {
                    o++;
                    z++;
                }
            }
            mes_total = (ano_total * 12) + z;
        }
        else if (a < b && o == w) // anos diferentes, meses iguais
        {
            mes_total = (ano_total * 12);
        }
    }
    float valor = pagamento(Hduracao, Mduracao, dia_total, mes_total, ano_total);

    return valor;
}

int main()
{
    int i = 0;        // indices dos lacos de repeticao
    int vaga = -1;    // variavel para escolher a vaga
    int resposta = 0; // variavel de escolha para navegar no programa
    int opcoes = -1;  // variavel para navegar pelo menu
    float valor = 0;  // variavel que recebe o preco calculado pelas funcoes
    int flag = 0, flag2 = 0;
    int erro1 = 0, erro2 = 0;
    do
    {
        // resets
        i = 0;
        vaga = -1;
        resposta = 0;
        opcoes = -1;
        flag = 0, flag2 = 0;
        erro1 = 0; erro2 = 0;

        printf("\n");
        printf("|--------------------------------|\n");
        printf("|    UNIOESTE - ESTACIONAMENTO   |\n");
        printf("|--------------------------------|\n");
        printf("\n|------------ MENU --------------|\n"); // menu de opcoes do programa
        printf("| [0] - Cadastrar vagas          |\n");
        printf("| [1] - Liberar vagas            |\n");
        printf("| [2] - Status de todas as vagas |\n");
        printf("| [4] - Finalizar programa       |\n");
        printf("|--------------------------------|\n");
        printf("Informe a opcao: "); // lendo a opcao desejada
        scanf("%d", &opcoes);
        fflush(stdin);
        printf("\n");

        if (opcoes == 0) // estrura que contem as opcoes selecionadas
        {
            while (resposta == 0) // cadastra vagas enquanto a resposta for 0
            {
                do
                {
                    printf("Informe o numero da vaga desejada [0 ate 10]: "); // lendo a vaga desejada
                    scanf("%d", &vaga);
                    fflush(stdin);
                    if (vaga >= 0 && vaga <= 10)
                    {
                        flag = 1;
                    }
                } while (flag == 0);

                if (vagas[vaga].status != 1) // teste para vaga vazia
                {
                    printf("Informe a placa do carro [7 caracteres]: "); // lendo a placa
                    fgets(vagas[vaga].placa, 7, stdin);
                    fflush(stdin);

                    do
                    {
                        printf("Informe a data de entrada [31/5/2002] [dia mes ano]: "); // data de entrada
                        scanf("%d%d%d", &vagas[vaga].datas.dia_entrada, &vagas[vaga].datas.mes_entrada, &vagas[vaga].datas.ano_entrada);
                        fflush(stdin);

                        if (vagas[vaga].datas.dia_entrada > 0 && vagas[vaga].datas.dia_entrada <= 31)
                        {
                            if (vagas[vaga].datas.mes_entrada > 0 && vagas[vaga].datas.mes_entrada <= 12)
                            {
                                if (vagas[vaga].datas.ano_entrada > 0)
                                {
                                    flag = 0;
                                }
                            }
                        }

                    } while (flag == 1);

                    do
                    {
                        printf("Informe Hora e Minuto de entrada [13 30] [hora min]: "); // hora de entrada
                        scanf("%d%d", &vagas[vaga].datas.Hentrada, &vagas[vaga].datas.Mentrada);
                        fflush(stdin);
                        if (vagas[vaga].datas.Hentrada <= 23 && vagas[vaga].datas.Hentrada >= 0)
                        {
                            if (vagas[vaga].datas.Mentrada >= 0 && vagas[vaga].datas.Mentrada <= 59)
                            {
                                flag = 1;
                            }
                        }
                    } while (flag == 0);

                    vagas[vaga].status = 1; // status recebe 1 para indicar que esta ocupado

                    printf("\n");
                    printf("-----------------------------\n");
                    printf(" VAGA CADASTRADA COM SUCESSO \n");
                    printf("-----------------------------\n");

                    do
                    {
                        printf("\n");
                        printf("[0] Continuar cadastrando\n");
                        printf("[1] Voltar ao Menu\n");
                        printf("Informe: ");
                        scanf("%d", &resposta);
                        fflush(stdin);
                        printf("\n");
                        if (resposta == 0 || resposta == 1)
                        {
                            flag = 0;
                        }
                    } while (flag == 1);
                }
                else if (vagas[vaga].status == 1) // teste para vaga ocupada
                {
                    printf("\n");
                    printf("------------------------------------\n");
                    printf(" A VAGA SELECIONADA JA ESTA OCUPADA \n");
                    printf("------------------------------------\n");

                    printf("\n");
                    printf("[0] Continuar cadastrando\n");
                    printf("[1] Voltar ao Menu\n");
                    printf("Informe: ");
                    scanf("%d", &resposta);
                    fflush(stdin);
                    printf("\n");
                }
            }
        }
        else if (opcoes == 1) // liberar vagas ocupadas
        {
            while (resposta == 0)
            {
                do
                {
                    printf("Informe o numero da vaga para liberar [0 ate 10]: "); // leitura da vaga desejada
                    scanf("%d", &vaga);
                    fflush(stdin);
                    if (vaga >= 0 && vaga <= 10)
                    {
                        flag2 = 1;
                    }
                } while (flag2 == 0);

                if (vagas[vaga].status == 1) // informa a vaga ocupada se os status for == 1
                {
                    vagas[vaga].status = 0;

                    do
                    {
                        printf("Informe a data de saida [31/5/2002] [dia mes ano]: ");
                        scanf("%d%d%d", &vagas[vaga].datas.dia_saida, &vagas[vaga].datas.mes_saida, &vagas[vaga].datas.ano_saida);
                        fflush(stdin);
                        if (vagas[vaga].datas.ano_saida > vagas[vaga].datas.ano_entrada)
                        {
                            if (vagas[vaga].datas.mes_saida > 0 && vagas[vaga].datas.mes_saida <= 12)
                            {
                                if (vagas[vaga].datas.dia_saida > 0 && vagas[vaga].datas.dia_saida <= 31)
                                {
                                    flag2 = 0;
                                }
                            }
                        }
                        else if (vagas[vaga].datas.ano_saida == vagas[vaga].datas.ano_entrada)
                        {
                            if (vagas[vaga].datas.mes_saida > vagas[vaga].datas.mes_entrada)
                            {
                                if (vagas[vaga].datas.dia_saida > 0 && vagas[vaga].datas.dia_saida <= 31)
                                {
                                    flag2 = 0;
                                }
                            }
                            else if (vagas[vaga].datas.mes_saida == vagas[vaga].datas.mes_entrada)
                            {
                                if (vagas[vaga].datas.dia_saida >= vagas[vaga].datas.dia_entrada)
                                {
                                    flag2 = 0;
                                }
                            }
                        }

                    } while (flag2 == 1);

                    do
                    {
                        printf("Informe o horario de saida [13 30] [hora min]: ");
                        scanf("%d%d", &vagas[vaga].datas.Hsaida, &vagas[vaga].datas.Msaida);
                        fflush(stdin);
                        if (vagas[vaga].datas.ano_entrada == vagas[vaga].datas.ano_saida && vagas[vaga].datas.mes_entrada == vagas[vaga].datas.mes_saida && vagas[vaga].datas.dia_entrada == vagas[vaga].datas.dia_saida)
                        {
                            if (vagas[vaga].datas.Hsaida >= 0 && vagas[vaga].datas.Hsaida <= 23)
                            {
                                if (vagas[vaga].datas.Msaida >= 0 && vagas[vaga].datas.Msaida <= 59)
                                {
                                    if (vagas[vaga].datas.Hsaida > vagas[vaga].datas.Hentrada)
                                    {
                                        flag2 = 1;
                                    }
                                    else if (vagas[vaga].datas.Hsaida == vagas[vaga].datas.Hentrada && vagas[vaga].datas.Msaida >= vagas[vaga].datas.Mentrada)
                                    {
                                        flag2 == 1;
                                    }
                                    else
                                    {
                                        flag2 = 0;
                                    }
                                }
                            }
                        }
                        else
                        {
                            flag2 = 1;
                        }
                    } while (flag2 == 0);

                    valor = tempo(vagas[vaga]); // chamada da funcao que calcula o pagamento

                    printf("\n");
                    printf("\nVAGA [%d]", vaga); // escrevendo as informacoes da vaga paga e liberada
                    printf("\nPlaca: %s", vagas[vaga].placa);
                    printf("\nHora de entrada: %dh:%dmin", vagas[vaga].datas.Hentrada, vagas[vaga].datas.Mentrada);
                    printf("\nData de entrada: %d/%d/%d", vagas[vaga].datas.dia_entrada, vagas[vaga].datas.mes_entrada, vagas[vaga].datas.ano_entrada);
                    printf("\nHora de saida: %dh:%dmin", vagas[vaga].datas.Hsaida, vagas[vaga].datas.Msaida);
                    printf("\nData de saida: %d/%d/%d", vagas[vaga].datas.dia_saida, vagas[vaga].datas.mes_saida, vagas[vaga].datas.ano_saida);
                    printf("\nTotal pago: %0.2f", valor);
                    printf("\nStatus da Vaga: PAGO E LIBERADO\n");

                    erro1 = 0;
                    do
                    {
                        printf("\n");
                        printf("[0] Informar outra vaga\n");
                        printf("[1] Voltar ao Menu\n");
                        printf("Informe: ");
                        scanf("%d", &resposta);
                        fflush(stdin);
                        if (resposta == 0 || resposta == 1)
                        {
                            erro1 = 1;
                        }
                    } while (erro1 == 0);
                }
                else if (vagas[vaga].status != 0) // informa que a vaga esta livre se os status == 0
                {
                    printf("\nA VAGA NAO ESTA OCUPADA");

                    erro2 = 0;
                    do
                    {
                        printf("\n");
                        printf("[0] Informar outra vaga\n");
                        printf("[1] Voltar ao Menu\n");
                        printf("Informe: ");
                        scanf("%d", &resposta);
                        fflush(stdin);
                        if (resposta == 1 || resposta == 0)
                        {
                            erro2 = 1;
                        }
                        
                    } while (erro2 == 0);
                }
            }
        }
        else if (opcoes == 2) // status do estacionamento
        {
            printf("\nSTATUS DO ESTACIONAMENTO\n");
            for (i = 0; i < 10; i++)
            {
                if (vagas[i].status != 1) // vagas livres
                {
                    printf("\nVAGA [%d]", i);
                    printf("\nPlaca: Nao Cadastrado");
                    printf("\nHora de Entrada: Nao Cadastrado");
                    printf("\nData de Entrada: Nao Cadastrado");
                    printf("\nStatus da Vaga: LIVRE\n");
                }
                else if (vagas[i].status == 1) // vagas ocupadas
                {
                    printf("\nVAGA [%d]", i);
                    printf("\nPlaca: %s\n", vagas[i].placa);
                    printf("Hora de Entrada: %dh:%dmin", vagas[i].datas.Hentrada, vagas[i].datas.Mentrada);
                    printf("\nData de Entrada: %d/%d/%d", vagas[i].datas.dia_entrada, vagas[i].datas.mes_entrada, vagas[i].datas.ano_entrada);
                    printf("\nStatus da Vaga: OCUPADO\n");
                }
            }
            resposta = 1;
        }
        else if (opcoes == 4) // finaliza o programa
        {
            printf("\nPROGRAMA FINALIZADO\n");
        }
        else if ((opcoes >= 5 || opcoes < 0) || isdigit(opcoes) == 0) // opcao invalida
        {
            printf("\nOPCAO INVALIDA, TENTE NOVAMENTE\n\n");
            resposta = 1;
        }

    } while (resposta == 1);

    return 0;
}