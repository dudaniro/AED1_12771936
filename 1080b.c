#include <stdio.h>   // Biblioteca que permite usar scanf() e printf()
#include <stdlib.h>  // Biblioteca que permite usar malloc() e free()

int main(void) {

    // cria uma variável n com o valor 100.
    // ela representa a quantidade de números que vamos armazenar.
    int n = 100;

    // malloc() reserva um espaço na memória para guardar 100 números inteiros.
    // sizeof(int) diz quantos bytes um número inteiro ocupa.
    // v é um ponteiro que vai guardar o endereço desse espaço na memória.
    int *v = malloc(n * sizeof(int));

    // percorre as 100 posições do vetor.
    // i começa em 0 e vai até 99.
    for (int i = 0; i < n; i++) {

        // lê um número digitado pelo usuário.
        // &v[i] indica o endereço onde o número deve ser armazenado.
        scanf("%d", &v[i]);
    }

    // considera que o primeiro número do vetor
    // é o maior número que encontramos.
    int maior = v[0];

    // A posição começa em 1 porque as posições
    // são contadas de 1 até 100, e não de 0 até 99.
    int pos = 1;

    // percorre o vetor de novo procurando
    // um número maior que o valor que está em "maior".
    // começa em i = 1 porque v[0] já foi considerado.
    for (int i = 1; i < n; i++) {

        // verifica se o número atual é maior que o maior
        // número encontrado até o momento.
        if (v[i] > maior) {

            // se for maior, atualiza a variável "maior".
            maior = v[i];

            // guarda a posição do novo maior número.
            // como o vetor começa em 0, precisamos somar 1
            // para mostrar a posição de 1 até 100.
            pos = i + 1;
        }
    }

    // mostra o maior número encontrado
    // e a posição onde ele apareceu.
    printf("%d\n%d\n", maior, pos);

    // libera da memória o espaço que foi reservado pelo malloc().
    free(v);

    // indica que o programa terminou corretamente.
    return 0;
}