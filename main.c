#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 50

typedef struct {
    int matricula;
    float notas[3];
    int faltas;
} Aluno;

int num_alunos = 0;
Aluno alunos[MAX_ALUNOS];

void imprimir_menu() {
    printf("MENU:\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Alterar dados de um aluno\n");
    printf("3 - Listar alunos cadastrados\n");
    printf("4 - Listar alunos aprovados\n");
    printf("5 - Listar alunos reprovados por média\n");
    printf("6 - Listar alunos reprovados por faltas\n");
    printf("0 - Sair\n");
}

int buscar_aluno(int matricula) {
    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1; // aluno não encontrado
}

void cadastrar_aluno() {
    if (num_alunos >= MAX_ALUNOS) {
        printf("Erro: número máximo de alunos atingido.\n");
        return;
    }

    Aluno novo_aluno;
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &novo_aluno.matricula);

    if (buscar_aluno(novo_aluno.matricula) != -1) {
        printf("Erro: matrícula já cadastrada.\n");
        return;
    }

    printf("Digite as três notas do aluno (separadas por espaço): ");
    scanf("%f %f %f", &novo_aluno.notas[0], &novo_aluno.notas[1], &novo_aluno.notas[2]);

    printf("Digite a quantidade de faltas do aluno: ");
    scanf("%d", &novo_aluno.faltas);

    alunos[num_alunos] = novo_aluno;
    num_alunos++;

    printf("Aluno cadastrado com sucesso.\n");
}

void alterar_dados_aluno() {
    if (num_alunos == 0) {
        printf("Erro: nenhum aluno cadastrado.\n");
        return;
    }

    int matricula;
    printf("Digite a matrícula do aluno a ser alterado: ");
    scanf("%d", &matricula);

    int posicao = buscar_aluno(matricula);
    if (posicao == -1) {
        printf("Erro: aluno não encontrado.\n");
        return;
    }

    printf("Digite as três novas notas do aluno (separadas por espaço): ");
    scanf("%f %f %f", &alunos[posicao].notas[0], &alunos[posicao].notas[1], &alunos[posicao].notas[2]);

    printf("Digite a nova quantidade de faltas do aluno: ");
    scanf("%d", &alunos[posicao].faltas);

    printf("Dados do aluno alterados com sucesso.\n");
}

void listar_alunos() {
    if (num_alunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("Alunos cadastrados:\n");
    printf("Matrícula  |  Nota 1  |  Nota 2  |  Nota 3  |  Faltas\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("%-11d|  %-8.2f|  %-8.2f|  %-8.2f|  %-6d\n",
                alunos[i].matricula, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], alunos[i].faltas);
    }
}

void listar_alunos_aprovados() {
    if (num_alunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
}

    printf("Alunos aprovados:\n");
    for (int i = 0; i < num_alunos; i++) {
    float media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
        if (media >= 7 && alunos[i].faltas <= 15) {
        printf("Matrícula: %d, Nota média: %.2f, Faltas: %d\n", alunos[i].matricula, media, alunos[i].faltas);
    }
}
}

void listar_alunos_reprovados_media() {
    if (num_alunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
}
printf("Alunos reprovados por média:\n");
    for (int i = 0; i < num_alunos; i++) {
        float media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
            if (media < 5) {
            printf("Matrícula: %d, Nota média: %.2f\n", alunos[i].matricula, media);
    }
}
}

void listar_alunos_reprovados_faltas() {
    if (num_alunos == 0) {
    printf("Nenhum aluno cadastrado.\n");
    return;
}
printf("Alunos reprovados por faltas:\n");
    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i].faltas > 15) {
        printf("Matrícula: %d, Faltas: %d\n", alunos[i].matricula, alunos[i].faltas);
    }
}
}

int main() {
int opcao;

do {
    imprimir_menu();
    printf("Digite uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            cadastrar_aluno();
            break;
        case 2:
            alterar_dados_aluno();
            break;
        case 3:
            listar_alunos();
            break;
        case 4:
            listar_alunos_aprovados();
            break;
        case 5:
            listar_alunos_reprovados_media();
            break;
        case 6:
            listar_alunos_reprovados_faltas();
            break;
        case 0:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
} while (opcao != 0);

return 0;
}