#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, k = 1;
    scanf("%d", &n);                                      // lê quantas matrizes serão testadas

    while (n--) {                                         // repete 1 vez pra cada instância

        int **m = malloc(9 * sizeof(int *));              // aloca a matriz do sudoku (9x9)
        for (int i = 0; i < 9; i++) {
            m[i] = malloc(9 * sizeof(int));
        }

        int **linha = malloc(9 * sizeof(int *));          // aloca os vetores de controle (9x10), já zerados com calloc
        int **coluna = malloc(9 * sizeof(int *));
        int **bloco = malloc(9 * sizeof(int *));
        for (int i = 0; i < 9; i++) {
            linha[i] = calloc(10, sizeof(int));
            coluna[i] = calloc(10, sizeof(int));
            bloco[i] = calloc(10, sizeof(int));
        }

        int valido = 1;                                   // assume valido até encontrar algum problema

       							                          // leitura da matriz
        for (int i = 0; i < 9; i++) {                     // percorre as linhas
            for (int j = 0; j < 9; j++) {                 // percorre as colunas
                scanf("%d", &m[i][j]);                    // lê cada nº da matriz
            }
        }

        for (int i = 0; i < 9; i++) {			          // validação: cada linha, coluna e bloco só pode ter cada valor de 1 a 9 uma vez
            for (int j = 0; j < 9; j++) {
                int v = m[i][j];                          // valor atual da posição
                int b = (i / 3) * 3 + (j / 3);            // converte (i,j) no índice do bloco 3x3 (0 a 8)
					
                if (v < 1 || v > 9) {                     // se o valor estiver fora do intervalo permitido = matriz inválid
                    valido = 0;
                    continue;                             // pula para próxima sem marcar v (inválido)
                }

                
                if (linha[i][v] || coluna[j][v] || bloco[b][v]) {     // se v já apareceu antes na mesma linha, coluna ou bloco = inválido
                    valido = 0;
                } else {
                    linha[i][v] = 1;
                    coluna[j][v] = 1;
                    bloco[b][v] = 1;
                }
            }
        }

        printf("Instancia %d\n", k++);
        printf("%s\n\n", valido ? "SIM" : "NAO");

        for (int i = 0; i < 9; i++) {       			 // libera toda a memória alocada

            free(m[i]);
            free(linha[i]);
            free(coluna[i]);
            free(bloco[i]);
        }
        free(m);
        free(linha);
        free(coluna);
        free(bloco);
    }

    return 0;
}