#include <stdio.h>

void maiorRecursivo(int pos, int maior, int pos_maior) {
    //caso base - já leu os 100 numeros, basta imprimir o resultado
    if (pos > 100) {
        printf("%d\n", maior);
        printf("%d\n", pos_maior);
        return;
    }
    
    int atual;
    scanf("%d", &atual);
    
    //se o nº atual for maior, atualiza o maior e a posição
    if (atual > maior) {
        maiorRecursivo(pos + 1, atual, pos);
    }else {
        maiorRecursivo(pos + 1, maior, pos_maior);
    }
}
int main() {
    int primeiro;
    scanf("%d", &primeiro);
    
    //começa na posição 2, usando o 1º nº como o "maior inicial"
    maiorRecursivo(2, primeiro, 1);
    
    return 0;
}