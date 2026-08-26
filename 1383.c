#include <stdio.h>
 
int main(void) {
    int n, k = 1; // n = numero de instâncias, k = contador da instância atual
    scanf("%d", &n); // lê quantas matrizes serão testadas 
    
    while (n--) {        // repete 1 vez pra cada instância
        int m[9][9] = {0};  // matriz do sudoku a ser validada
        int linha[9][10] = {0};  // linha [i][v] = 1 se o valor v já apareceu na linha i 
        int coluna[9][10] = {0};  // coluna [j][v] = 1 se o valor v já apareceu na coluna j
        int bloco[9][10] = {0};   // bloco [b][v] = 1 se o valor v já apareceu no bloco b
        int valido = 1; // assume valido até encontrar algum problema 
        
        //leitura da matriz
        for (int i = 0; i < 9; i++){  // percorre as linhas 
            for (int j = 0; j < 9; j++){ // percorre as colunas 
                scanf("%d", &m[i][j]); // lê cada nº da matriz
        
            }
        }
        //validação: cada linha , coluna e bloco só pode ter cada valor de 1 a 9 uma vez
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++){
            int v = m[i][j];               // valor atual da posição
            int b = (i / 3) * 3 + (j / 3); // converte (i,j) no índice do bloco 3x3 (0 a 8)
            
            // se o valor estiver fora do intervalo permitido = matriz inválida
            if(v < 1 || v > 9) {
                valido = 0;
                continue;  // pula para proxima sem marcar v (inválido)
            }
            
            // se v já apareceu antes na mesma linha, coluna ou bloco = inválido
            if (linha[i][v] || coluna[j][v] || bloco [b][v]) {
                valido = 0;
            }else {
                linha [i][v] = 1;
                coluna[j][v] = 1;
                bloco [b][v] = 1;
            }
        }
    }
    
    printf("Instancia %d\n", k++); // imprime o nº da instância e incrementa k
    printf("%s\n\n", valido ? "SIM" : "NAO");
    
    }
    return 0;
}