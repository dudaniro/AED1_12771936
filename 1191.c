#include <stdio.h>
#include <string.h>

void posfixa(const char *pre, const char *in, int n) {
    if (n <= 0) return;

    char raiz = pre[0];
    int k = 0;
    while (k < n && in[k] != raiz) k++;

    posfixa(pre + 1, in, k);                    // subárvore esquerda
    posfixa(pre + 1 + k, in + k + 1, n - k - 1); // subárvore direita
    putchar(raiz);
}

int main(void) {
    char pre[64], in[64];

    while (scanf("%63s %63s", pre, in) == 2) {
        posfixa(pre, in, (int)strlen(pre));
        putchar('\n');
    }
    return 0;
}
