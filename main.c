#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAX 100

//Função para imprimir a matriz
void imprimirMatriz(char **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

//Abaixo estarão as funções de busca na matriz.

//Verifica horizontal direta
void horizontal_direita(char **matriz, int linhas, int colunas, char *palavra)
{
    int tamanho = strlen(palavra);
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            if (c + tamanho <= colunas) {
                int encontrada = 1;
                for (int i = 0; i < tamanho; i++) {
                    if (matriz[l][c + i] != palavra[i]) {
                        encontrada = 0;
                        break;
                    }
                }
                if (encontrada == 1) {
                    printf("Palavra \"%s\" ocorre na horizontal direta, iniciando na posição [%d,%d] e terminando na posição [%d,%d]\n", palavra, l + 1, c + 1, l + 1, c + tamanho);
                    return;
                }
            }
        }
    }
}

//Verifica horizontal reversa
void horizontal_reversa(char **matriz, int linhas, int colunas, char *palavra)
{
    int tamanho = strlen(palavra);
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            if (c - tamanho + 1 >= 0) {
                int encontrada = 1;
                for (int i = 0; i < tamanho; i++) {
                    if (matriz[l][c - i] != palavra[i]) {
                        encontrada = 0;
                        break;
                    }
                }
                if (encontrada == 1) {
                    printf("Palavra \"%s\" ocorre na horizontal reversa, iniciando na posição [%d,%d] e terminando na posição [%d,%d]\n", palavra, l + 1, c + 1, l + 1, c - tamanho + 1);
                    return;
                }
            }
        }
    }
}

//Verifica vertical direta
void vertical_direta(char **matriz, int linhas, int colunas, char *palavra)
{
    int tamanho = strlen(palavra);
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            if (l + tamanho <= linhas) {
                int encontrada = 1;
                for (int i = 0; i < tamanho; i++) {
                    if (matriz[l + i][c] != palavra[i]) {
                        encontrada = 0;
                        break;
                    }
                }
                if (encontrada == 1) {
                    printf("Palavra \"%s\" ocorre na vertical direta, iniciando na posição [%d,%d] e terminando na posição [%d,%d]\n", palavra, l + 1, c + 1, l + tamanho, c + 1);
                    return;
                }
            }
        }
    }
}

//Verifica vertical reversa
void vertical_reversa(char **matriz, int linhas, int colunas, char *palavra)
{
    int tamanho = strlen(palavra);
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            if (l - tamanho + 1 >= 0) {
                int encontrada = 1;
                for (int i = 0; i < tamanho; i++) {
                    if (matriz[l - i][c] != palavra[i]) {
                        encontrada = 0;
                        break;
                    }
                }
                if (encontrada== 1) {
                    printf("Palavra \"%s\" ocorre na vertical reversa, iniciando na posição [%d,%d] e terminando na posição [%d,%d]\n", palavra, l + 1, c + 1, l - tamanho + 1, c + 1);
                    return;
                }
            }
        }
    }
}

//Verifica diagonal principal direta
void diagonal_principal_direta(char **matriz, int linhas, int colunas, char *palavra)
{
    int tamanho = strlen(palavra);
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            if (c + tamanho <= colunas && l + tamanho <= linhas) {
                int encontrada = 1;
                for (int i = 0; i < tamanho; i++) {
                    if (matriz[l + i][c + i] != palavra[i]) {
                        encontrada = 0;
                        break;
                    }
                }
                if (encontrada== 1) {
                    printf("Palavra \"%s\" ocorre na diagonal principal direta, iniciando na posição [%d,%d] e terminando na posição [%d,%d]\n", palavra, l + 1, c + 1, l + tamanho, c + tamanho);
                    return;
                }
            }
        }
    }
}

//Verifica diagonal principal reversa
void diagonal_principal_reversa(char **matriz, int linhas, int colunas, char *palavra)
{
    int tamanho = strlen(palavra);
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            if (c - tamanho + 1 >= 0 && l - tamanho + 1 >= 0) {
                int encontrada = 1;
                for (int i = 0; i < tamanho; i++) {
                    if (matriz[l - i][c - i] != palavra[i]) {
                        encontrada = 0;
                        break;
                    }
                }
                if (encontrada == 1) {
                    printf("Palavra \"%s\" ocorre na diagonal principal reversa, iniciando na posição [%d,%d] e terminando na posição [%d,%d]\n", palavra, l + 1, c + 1, l - tamanho + 1, c - tamanho + 1);
                    return;
                }
            }
        }
    }
}

//Verifica diagonal secundária direta
void diagonal_secundaria_direta(char **matriz, int linhas, int colunas, char *palavra)
{
    int tamanho = strlen(palavra);
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            if (c - tamanho + 1 >= 0 && l + tamanho <= linhas) {
                int encontrada = 1;
                for (int i = 0; i < tamanho; i++) {
                    if (matriz[l + i][c - i] != palavra[i]) {
                        encontrada = 0;
                        break;
                    }
                }
                if (encontrada == 1) {
                    printf("Palavra \"%s\" ocorre na diagonal secundária direta, iniciando na posição [%d,%d] e terminando na posição [%d,%d]\n", palavra, l + 1, c + 1, l + tamanho, c - tamanho + 1);
                    return;
                }
            }
        }
    }
}

//Verifica diagonal secundária reversa
void diagonal_secundaria_reversa(char **matriz, int linhas, int colunas, char *palavra)
{
    int tamanho = strlen(palavra);
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            if (c + tamanho <= colunas && l - tamanho + 1 >= 0) {
                int encontrada = 1;
                for (int i = 0; i < tamanho; i++) {
                    if (matriz[l - i][c + i] != palavra[i]) {
                        encontrada = 0;
                        break;
                    }
                }
                if (encontrada == 1) {
                    printf("Palavra \"%s\" ocorre na diagonal secundária reversa, iniciando na posição [%d,%d] e terminando na posição [%d,%d]\n", palavra, l + 1, c + 1, l - tamanho + 1, c + tamanho);
                    return;
                }
            }
        }
    }
}

//Função que chama as outras funções de busca
void chamaFuncoes(char **matriz, int linhas, int colunas, char *palavra)
{
    horizontal_direita(matriz, linhas, colunas, palavra);
    horizontal_reversa(matriz, linhas, colunas, palavra);
    vertical_direta(matriz, linhas, colunas, palavra);
    vertical_reversa(matriz, linhas, colunas, palavra);
    diagonal_principal_direta(matriz, linhas, colunas, palavra);
    diagonal_principal_reversa(matriz, linhas, colunas, palavra);
    diagonal_secundaria_direta(matriz, linhas, colunas, palavra);
    diagonal_secundaria_reversa(matriz, linhas, colunas, palavra);
}

int main() {
    int linhas, colunas;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    //Aloca dinamicamente a matriz
    char **matriz = (char **)malloc(linhas * sizeof(char *));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (char *)malloc(colunas * sizeof(char));
    }

    printf("Digite o texto que será inserido na matriz: ");
    getchar();  //Descarta o caractere de nova linha
    char textoEntrada[TAMANHO_MAX];
    fgets(textoEntrada, TAMANHO_MAX, stdin);

    //Remove espaços em branco do texto e armazena na matriz
    int l = 0, c = 0;
    for (int i = 0; textoEntrada[i] != '\0'; i++) {
        if (textoEntrada[i] != ' ' && textoEntrada[i] != '\n') {
            matriz[l][c] = textoEntrada[i];
            c++;
            if (c == colunas) {
                l++;
                c = 0;
            }
        }
    }
    
    printf("\nMatriz:\n");
    imprimirMatriz(matriz, linhas, colunas);

    //Busca palavras na matriz
    while (1) {
        printf("\nDigite uma palavra para buscar na matriz (ou digite 'exit' para encerrar): ");
        char palavra[TAMANHO_MAX];
        scanf("%s", palavra);
        if (strcmp(palavra, "exit") == 0) {
            break;
        }
        chamaFuncoes(matriz, linhas, colunas, palavra);
    }

    //Libera a memória alocada para a matriz
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
