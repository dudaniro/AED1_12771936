#include <stdio.h>
#include <string.h>

void posfixa(const char *pre, const char *in, int n) {
    if (n <= 0) return;
    char raiz = pre[0];
    int k = 0;
    while (k < n && in[k] != raiz) k++;
    posfixa(pre + 1, in, k);
    posfixa(pre + 1 + k, in + k + 1, n - k - 1);
    putchar(raiz);
}

int main(void) {
    int C, N;
    char pre[64], in[64];
    scanf("%d", &C);
    while (C--) {
        scanf("%d %63s %63s", &N, pre, in);
        posfixa(pre, in, N);
        putchar('\n');
    }
    return 0;
}
