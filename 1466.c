#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void percursoPorNivel(No* raiz) {
    if (raiz == NULL) return;

    // Como N <= 500, um array estático de 505 posições é suficiente para a fila
    No* fila[505];
    int inicio = 0;
    int fim = 0;

    fila[fim++] = raiz;
    int primeiro = 1;

    while (inicio < fim) {
        No* atual = fila[inicio++];

        if (!primeiro) {
            printf(" ");
        }
        printf("%d", atual->valor);
        primeiro = 0;

        if (atual->esq != NULL) {
            fila[fim++] = atual->esq;
        }
        if (atual->dir != NULL) {
            fila[fim++] = atual->dir;
        }
    }
    printf("\n");
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    int c;
    if (scanf("%d", &c) != 1) return 0;

    for (int caso = 1; caso <= c; caso++) {
        int n, val;
        scanf("%d", &n);

        No* raiz = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            raiz = inserir(raiz, val);
        }

        printf("Case %d:\n", caso);
        percursoPorNivel(raiz);
        printf("\n"); // Linha em branco obrigatória após cada caso

        liberarArvore(raiz);
    }

    return 0;
}
