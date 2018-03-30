#ifndef BASEDEDADOS_H_INCLUDED
#define BASEDEDADOS_H_INCLUDED

struct Alunos
{
    int id;
    char nome[50];
} aluno;

int guardar(char *tabela, char *dados);
int ler(char *tabela, char *dados);

void AlunoToString(struct Alunos aluno, char *dados);

#endif