#include <stdio.h>                                 // biblioteca que permite usar scanf() e printf()
#include <stdlib.h>                                // biblioteca que permite usar malloc() e free()

int main(void) {

    int n = 100;                                   // cria uma variável n com o valor 100 (representa a quantidade de números armazenados).

    int *v = malloc(n * sizeof(int));              // malloc() reserva um espaço na memória para guardar 100 números inteiros.
                                                   // sizeof(int) diz quantos bytes um número inteiro ocupa.
                                                   // v é um ponteiro que vai guardar o endereço desse espaço na memória.

    for (int i = 0; i < n; i++) {                  // percorre as 100 posições do vetor com i de 0 a 99.
        scanf("%d", &v[i]);                        // lê um número digitado pelo usuário e indica o endereço onde o número deve ser armazenado.
    }   

    int maior = v[0];                              // considera que o primeiro número do vetor é o maior número encontrado.
    int pos = 1;                                   // posições contadas de 1 a 100.

    for (int i = 1; i < n; i++) {                  // começa em i = 1 porque v[0] já foi considerado.
         if (v[i] > maior) {                       // verifica se o número atual é maior que o maior número encontrado até o momento.
            maior = v[i];                          // se for maior, atualiza a variável "maior".
            pos = i + 1;                           // guarda a posição do novo maior número, como o vetor começa em 0, precisamos somar 1 para sair de 1 a 100 e não 0 a 99.
        }
    }

    printf("%d\n%d\n", maior, pos);

    free(v);                                       // libera da memória o espaço que foi reservado pelo malloc().

    return 0;
}
