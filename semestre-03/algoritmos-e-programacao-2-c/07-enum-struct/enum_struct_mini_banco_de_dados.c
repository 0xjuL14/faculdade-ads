//
// Created by juh on 11/12/25 on CLion
//

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

enum eSexo { // serve para limitar, tipo uma "etiqueta"
    Masculino, // valor 0
    Feminino, // valor 1
    Outro // valor 3
};

struct stAluno { // estrutura, como um "molde"
    int numMatricula;
    bool ativo;
    enum eSexo sexo; // Reserva um espaço para a "etiqueta" (eSexo)
    char nome[101];
    float valorMensalidade;
};

int main()
{
    setlocale(LC_ALL, "portuguese-brazilian");

        struct stAluno alunosAlgII[5]; // delimita o registro para 5 alunos (indices 0 a 4)
    // preenchimento dos dados do 1º aluno (índice 0):
        alunosAlgII[0].numMatricula = 1000; // o '.' acessa um campo quando tem a estrutura diretamente
        alunosAlgII[0].ativo = true;
        alunosAlgII[0].sexo = Masculino;
        strcpy(alunosAlgII[0].nome,"Aluno 1"); // strcpy porque o nome é uma string
        alunosAlgII[0].valorMensalidade = 250.23;
    // preenchimento dos dados do 2º aluno (índice 1):
        alunosAlgII[1].numMatricula = 1001;
        alunosAlgII[1].ativo = true;
        alunosAlgII[1].sexo = Outro;
        strcpy(alunosAlgII[1].nome,"Aluno 2");
        alunosAlgII[1].valorMensalidade = 198.44;
    // preenchimento dos dados do 3º aluno (índice 2)
        alunosAlgII[2].numMatricula = 1002;
        alunosAlgII[2].ativo = true;
        alunosAlgII[2].sexo = Feminino;
        strcpy(alunosAlgII[2].nome,"Aluna 1");
        alunosAlgII[2].valorMensalidade = 200.00;
    // preenchimento dos dados do 4º aluno (índice 3)
        alunosAlgII[3].numMatricula = 1003;
        alunosAlgII[3].ativo = false;
        alunosAlgII[3].sexo = Feminino;
        strcpy(alunosAlgII[3].nome,"Aluna 2");
        alunosAlgII[3].valorMensalidade = 302.10;
    // preenchimento dos dados do 5º aluno (índice 4)
        alunosAlgII[4].numMatricula = 1004;
        alunosAlgII[4].ativo = true;
        alunosAlgII[4].sexo = Masculino;
        strcpy(alunosAlgII[4].nome,"Aluno 3");
        alunosAlgII[4].valorMensalidade = 270.22;

        printf("Tamanho da estrutura: %lu\n\n", sizeof(struct stAluno)); // Mostra quanto espaço de memória cada ficha ocupa

        for (int i=0; i<5; i++) { // loop para imprimir toda estrutura
            struct stAluno *aluno = alunosAlgII + i; // Cria um ponteiro (aluno) e aponta ele para a ficha atual (alunosAlgII[i])
            printf("Dados da %dª estrutura: (Endereço: %d)\n",i + 1, aluno); // Imprime o número da ficha e o endereço da memória correspondente
            printf("N�mero Matrícula: %d\n", aluno -> numMatricula); // Imprime a Matrícula da ficha que o ponteiro (aluno) está apontando
            printf("Aluno(a) Ativo..: %s\n", aluno -> ativo ? "Sim" : "Não"); // '->' acessa um campo quando tem um ponteiro para a estrutura (o endereço da ficha) e não a ficha em si
            printf("Sexo............: %s\n",
                (aluno -> sexo == Masculino) ? "Masculino" :
                (aluno -> sexo == Feminino)  ? "Feminino" : "Outro");;
            printf("Nome do Aluno...: %s\n", aluno -> nome);
            printf("Valor Mensalid..: %4.2f\n", aluno -> valorMensalidade);
            printf("\n");
        } // o loop volta para o início e repete para a próxima ficha

    return 0; // GG! :)
}