#include <stdio.h>

void maiorRecursivo(int pos, int maior, int pos_maior) {
    
    if (pos > 100) {                                //caso base: já leu os 100 numeros, só imprime o resultado.
        printf("%d\n", maior);
        printf("%d\n", pos_maior);
        return;
    }
    
    int atual;
    scanf("%d", &atual);
    
    if (atual > maior) {                            //se o nº atual for maior, atualiza o maior e a posição.
        maiorRecursivo(pos + 1, atual, pos);
    }else {
        maiorRecursivo(pos + 1, maior, pos_maior);
    }
}

int main() {                                        
    int primeiro;
    scanf("%d", &primeiro);
    maiorRecursivo(2, primeiro, 1);                  //começa na posição 2, usando o 1º nº como o "maior inicial".
    return 0;
}
