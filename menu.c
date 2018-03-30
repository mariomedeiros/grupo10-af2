#include <stdio.h>

#include "config.h"
#include "menu.h"

// Funcao auxiliar para imprimir todas as linhas do menu
void mostar(int bloco)
{
    if (bloco == 0)
    {
        printf("----------------------------------\n");
        printf("              MENU                \n");
        printf("----------------------------------\n");
        printf("Escolha uma das opcao: \n");
        printf("(%d) - Inscrever\n", OPCAO_INSCREVER);
        printf("(%d) - Anular\n", OPCAO_ANULAR);
        printf("(%d) - Listagem de inscricoes por UC e por aluno\n", OPCAO_LISTAR);
        printf("(%d) - Calcular Propinas de cada aluno\n", OPCAO_CALCULAR);
        printf("(%d) - Gravar\n", OPCAO_GRAVAR);
        printf("(%d) - Sair\n", OPCAO_SAIR);
    }
}

// capturar o input do user e retornar
int menu(int inicial)
{
    mostar(inicial);

    int opcao = -1;

    while (opcao < OPCAO_MIN || opcao > OPCAO_MAX)
    {
        scanf("%d", &opcao);
    }

    return opcao;
}
