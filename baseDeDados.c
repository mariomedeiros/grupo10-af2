#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "baseDeDados.h"

// guardar o conteudo da tabela X no disco
int guardar(char *tabela, char *dados)
{
    FILE *ficheiro;
    char nome[80];

    strcpy(nome, FICHEIRO_PREFIXO);
    strcat(nome, tabela);
    strcat(nome, FICHEIRO_EXT);

    printf("Guardando tabela '%s' no ficheiro '%s'...\n", tabela, nome);

    ficheiro = fopen(nome, "w");

    if (ficheiro)
    {
        fprintf(ficheiro, "%s", dados);
        fclose(ficheiro);
        return 1;
    }
    else
    {
        printf("ERRO ao guardar ficheiro '%s'!\n", nome);
        return 0;
    }
}

// ler do ficheiro a tabela X
int ler(char *tabela, char *dados)
{
    FILE *ficheiro;
    char nome[80];

    strcpy(nome, FICHEIRO_PREFIXO);
    strcat(nome, tabela);
    strcat(nome, FICHEIRO_EXT);

    printf("Lendo tabela '%s' do ficheiro '%s'...\n", tabela, nome);

    ficheiro = fopen(nome, "rb");

    if (ficheiro)
    {
        char *buffer = 0;
        long length;

        fseek(ficheiro, 0, SEEK_END);
        length = ftell(ficheiro);
        fseek(ficheiro, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer)
        {
            fread(buffer, 1, length, ficheiro);
        }
        fclose(ficheiro);
        strcpy(dados, buffer);
        return 1;
    }
    else
    {
        printf("ERRO ao ler ficheiro '%s'!\n", nome);
        return 0;
    }
}

void AlunoToString(struct Alunos aluno, char *dados)
{
    char str[100];
    strcpy(dados, "");
    sprintf(str, "id='%d'", aluno.id);
    strcat(dados, str);
    sprintf(str, "nome='%s'", aluno.nome);
    strcat(dados, str);
}