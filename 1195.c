#include <stdio.h>

#define MAX 505

int val[MAX], esq[MAX], dir[MAX], n, primeiro;

void insere(int x) {
    int novo = n++;
    val[novo] = x; esq[novo] = dir[novo] = -1;
    if (novo == 0) return;
    int cur = 0;
    for (;;) {
        if (x < val[cur]) {
            if (esq[cur] == -1) { esq[cur] = novo; return; }
            cur = esq[cur];
        } else {
            if (dir[cur] == -1) { dir[cur] = novo; return; }
            cur = dir[cur];
        }
    }
}

void out(int x) { printf(primeiro ? "%d" : " %d", x); primeiro = 0; }
void pr(int u) { if (u < 0) return; out(val[u]); pr(esq[u]); pr(dir[u]); }
void in(int u) { if (u < 0) return; in(esq[u]); out(val[u]); in(dir[u]); }
void po(int u) { if (u < 0) return; po(esq[u]); po(dir[u]); out(val[u]); }

int main(void) {
    int C, N;
    scanf("%d", &C);
    for (int c = 1; c <= C; c++) {
        scanf("%d", &N);
        n = 0;
        for (int i = 0; i < N; i++) { int x; scanf("%d", &x); insere(x); }
        printf("Case %d:\n", c);
        printf("Pre.: "); primeiro = 1; pr(0);  putchar('\n');
        printf("In..: "); primeiro = 1; in(0);  putchar('\n');
        printf("Post: "); primeiro = 1; po(0);  printf("\n\n");
    }
    return 0;
}
