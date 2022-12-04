#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 3

struct data
{
    int ano;
    int mes;
    int dia;
};

struct despesa
{
    float salario_devs;
    float custo_hora_extra;
    float custo_reuniao;
    float outros_gastos;
};

struct projeto
{
    int codigo; // max 2
    char gerente[50];
    struct data data_entrega;
    char cliente[50];
    struct despesa despesaProjeto;
    float valor;
};

float lucroTotal(struct projeto projeto[])
{
    float lucro = 0;
    float aux = 0;
    float aux1 = 0;
    for (int i = 0; i < max; i++)
    {
        aux = aux + projeto[i].despesaProjeto.salario_devs + projeto[i].despesaProjeto.custo_hora_extra + projeto[i].despesaProjeto.custo_reuniao + projeto[i].despesaProjeto.outros_gastos;
        aux1 = aux1 + projeto[i].valor;
    }
    lucro = aux1 - aux;
    return lucro;
}

float custoTotal(struct projeto projeto[], int i)
{
    float aux = 0;
    aux = aux + projeto[i].despesaProjeto.salario_devs + projeto[i].despesaProjeto.custo_hora_extra + projeto[i].despesaProjeto.custo_reuniao + projeto[i].despesaProjeto.outros_gastos;
    return aux;
}

float lucro(struct projeto projeto[], int i)
{
    float lucro = 0;
    lucro = projeto[i].valor - custoTotal(projeto, i);
    return lucro;
}

int projetoAtrasado(struct projeto projeto[])
{
    int count = 0;
    for (int i = 0; i < max; i++)
    {
        if (projeto[i].data_entrega.ano < 2022 && projeto[i].data_entrega.mes < 12)
        {
            count++;
        }
    }
    return count;
}

int maisHorasGastas(struct projeto projeto[])
{
    float aux = 0;
    int posicao = 0;
    for (int i = 0; i < max; i++)
    {
        if (projeto[i].despesaProjeto.custo_hora_extra > aux)
        {
            aux = projeto[i].despesaProjeto.custo_hora_extra;
            posicao = i;
        }
    }
    return posicao;
}

int maiorGastoTotal(struct projeto projeto[])
{
    int aux[max];
    int maior = 0;
    int posicao = 0;
    for (int i = 0; i < max; i++)
    {
        aux[i] = aux[i] + projeto[i].despesaProjeto.salario_devs + projeto[i].despesaProjeto.custo_hora_extra + projeto[i].despesaProjeto.custo_reuniao + projeto[i].despesaProjeto.outros_gastos;
        if (aux[i] > maior)
        {
            maior = aux[i];
            posicao = i;
        }
    }
    return posicao;
}

void insertProject(struct projeto projetos[])
{
    for (int i = 0; i < max; i++)
    {
        printf("Digite o do codigo do projeto[%d]:", (i + 1));
        scanf("%d", &projetos[i].codigo);
        while (projetos[i].codigo > 99)
        {
            printf("Valores acima de 2 digitos nao aceitados, por favor digite novamente:");
            scanf("%d", &projetos[i].codigo);
        }
        printf("Digite o nome do gerente do projeto:");
        scanf("%s", projetos[i].gerente);
        printf("Digite o ano de entrega do projeto:");
        scanf("%d", &projetos[i].data_entrega.ano);
        printf("Digite o mes de entrega do projeto:");
        scanf("%d", &projetos[i].data_entrega.mes);
        printf("Digite o dia de entrega do projeto:");
        scanf("%d", &projetos[i].data_entrega.dia);
        printf("Digite o nome do cliente do projeto:");
        scanf("%s", projetos[i].cliente);
        printf("Digite o valor dos desenvolvedores do projeto:");
        scanf("%f", &projetos[i].despesaProjeto.salario_devs);
        printf("Digite o valor das horas extras do projeto:");
        scanf("%f", &projetos[i].despesaProjeto.custo_hora_extra);
        printf("Digite o valor das reunioes do projeto:");
        scanf("%f", &projetos[i].despesaProjeto.custo_reuniao);
        printf("Digite os demais valores do projeto:");
        scanf("%f", &projetos[i].despesaProjeto.outros_gastos);
        printf("Digite o valor do projeto:");
        scanf("%f", &projetos[i].valor);
        printf("------------------------------------------------ \n");
    }
}

int main()
{
    struct projeto projeto[max];
    insertProject(projeto);
    int choose = 1;
    printf("\t");
    printf("Bem Vindo ao Sistema:\n\t");
    printf("Como podemos te ajudar?\n\t");
    printf("Para visualizar o lucro total dos projetos em andamento, digite 1:\n\t");
    printf("Para visualizar quantos projetos estao atrasados, digite 2:\n\t");
    printf("Para visualizar o codigo eo nome do gerente com maior gasto com horas extras, digite 3:\n\t");
    printf("Para visualizar o codigo eo nome do gerente com maior gasto no total, digite 4:\n\t");
    printf("Para pesquisar por gerente, digite 5:\n\t");
    printf("Para pesquisar por cliente digite 6:\n\t");
    printf("Para finalizar o sistema digite 0!\n\t");
    printf("Sua Escolha aqui:");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        /* code */
        printf("O Lucro total dos projetos em andamentos e de: %.2f", lucroTotal(projeto));
        printf("\n");
        break;
    case 2:
        printf("O numero de projetos atrasados e de: %d", projetoAtrasado(projeto));
        printf("\n");
        break;
    case 3:
        printf("O Codigo do projeto com mais gasto com hora extra e: %d", projeto[maisHorasGastas(projeto)].codigo);
        printf(" e o Nome do gerente do projeto com mais gasto com hora extra e: %s", projeto[maisHorasGastas(projeto)].gerente);
        printf("\n");
        break;
    case 4:
        printf("O Codigo do projeto com mais gasto no geral e: %d", projeto[maiorGastoTotal(projeto)].codigo);
        printf("O nome do gerente do projeto com mais gasto no geral e: %s", projeto[maiorGastoTotal(projeto)].gerente);
        printf("\n");
        break;
    case 5:
        printf("Digite o nome de um gerente para consulta:");
        char gerente[50];
        int resultado[max];
        int count = 0;
        scanf("%s", gerente);
        for (int i = 0; i < max; i++)
        {
            if (strcmp(projeto[i].gerente, gerente) == 0)
            {
                resultado[count] = i;
                count++;
            }
        }
        for (int i = 0; i < count; i++)
        {
            printf("---------------------------------------\n");
            printf("Codigo do projeto: %d \n", projeto[resultado[i]].codigo);
            printf("Cliente do projeto: %s \n", projeto[resultado[i]].cliente);
            printf("Data prevista do projeto: %d/%d/%d \n", projeto[resultado[i]].data_entrega.dia, projeto[i].data_entrega.mes, projeto[i].data_entrega.ano);
            printf("O lucro total desse projeto foi de: %.2f \n", lucro(projeto, i));
            printf("---------------------------------------\n");
            printf("\n");
        }

        break;
    case 6:
        printf("Digite o nome de um cliente para consulta:");
        char cliente[50];
        int resultado_cliente[max];
        int count_cliente = 0;
        scanf("%s", cliente);
        for (int i = 0; i < max; i++)
        {
            if (strcmp(projeto[i].gerente, gerente) == 0)
            {
                resultado_cliente[count_cliente] = i;
                count_cliente++;
            }
        }
        for (int i = 0; i < count_cliente; i++)
        {
            printf("---------------------------------------\n");
            printf("Codigo do projeto: %d \n", projeto[resultado[i]].codigo);
            printf("Gerente do projeto: %s \n", projeto[resultado[i]].cliente);
            printf("Data prevista do projeto: %d/%d/%d \n", projeto[resultado[i]].data_entrega.dia, projeto[i].data_entrega.mes, projeto[i].data_entrega.ano);
            printf("O Custo total desse projeto foi de: %.2f \n", custoTotal(projeto, i));
            printf("---------------------------------------\n");
            printf("\n");
        }
        break;
    default:

        printf("opcao invalida!");
        break;
    }
    return 0;
}
