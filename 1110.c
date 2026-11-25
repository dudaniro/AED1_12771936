#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int v;
    struct No *prox;
} No;

int main(void) {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        No *ini = NULL, *fim = NULL;
        for (int i = 1; i <= n; i++) {
            No *x = malloc(sizeof *x);
            x->v = i; x->prox = NULL;
            if (fim) fim->prox = x; else ini = x;
            fim = x;
        }

        int qtd = n, primeiro = 1;
        printf("Discarded cards:");
        while (qtd >= 2) {
            No *d = ini;                 // descarta a do topo
            ini = ini->prox;
            printf(primeiro ? " %d" : ", %d", d->v);
            primeiro = 0;
            free(d);
            qtd--;

            No *m = ini;                 // a próxima vai para o fundo
            ini = ini->prox;
            m->prox = NULL;
            fim->prox = m;
            fim = m;
        }
        printf("\nRemaining card: %d\n", ini->v);
        free(ini);
    }
    return 0;
}
