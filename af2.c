#include <stdio.h>
#include <string.h>

#include "config.h"
#include "baseDeDados.h"
#include "menu.h"

// para compilar com as dependencias usar o commando (windows):
// gcc -Wall config.h af2.c baseDeDados.c menu.c -o af2.exe

int main()
{
    printf("Grupo %d! - AF%d versao %d \n", 10, 2, VERSAO);

    int opcao;
    opcao = menu(0);

    if (opcao == OPCAO_INSCREVER)
    {
        printf("  Inscrever...\n");
    }
    else if (opcao == OPCAO_ANULAR)
    {
        printf("  Anular ...\n");
    }
    else if (opcao == OPCAO_LISTAR)
    {
        printf("  Listagem...\n");

        char dados[10];

        ler(ALUNOS, dados);

        printf("Dados dos alunos: %s\n", dados);
    }
    else if (opcao == OPCAO_GRAVAR)
    {
        struct Alunos aluno1;
        aluno1.id = 111;
        strcpy(aluno1.nome, "nome do aluno 111");

        char dados[10];
        AlunoToString(aluno1, dados);

        printf("Dados dos alunos: %s\n", dados);

        guardar(ALUNOS, dados);
        guardar("unidades", "linha1\nlinha2\nlinha3");
        guardar("inscricoes", "linha1\nlinha2\nlinha3");
    }

    return 0;
}
