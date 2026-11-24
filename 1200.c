#include <stdio.h>
#include <string.h>

#define MAX 1005

char val[MAX];
int esq[MAX], dir[MAX], n = 0, primeiro;

void insere(char x) {
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

int busca(char x) {
    int cur = n ? 0 : -1;
    while (cur != -1) {
        if (x == val[cur]) return 1;
        cur = (x < val[cur]) ? esq[cur] : dir[cur];
    }
    return 0;
}

void pr(int u) { if (u < 0) return; printf(primeiro ? "%c" : " %c", val[u]); primeiro = 0; pr(esq[u]); pr(dir[u]); }
void in(int u) { if (u < 0) return; in(esq[u]); printf(primeiro ? "%c" : " %c", val[u]); primeiro = 0; in(dir[u]); }
void po(int u) { if (u < 0) return; po(esq[u]); po(dir[u]); printf(primeiro ? "%c" : " %c", val[u]); primeiro = 0; }

int main(void) {
    char cmd[16];
    while (scanf("%15s", cmd) == 1) {
        if (strcmp(cmd, "I") == 0) {
            char x; scanf(" %c", &x); insere(x);
        } else if (strcmp(cmd, "P") == 0) {
            char x; scanf(" %c", &x);
            printf("%c %s\n", x, busca(x) ? "existe" : "nao existe");
        } else {
            primeiro = 1;
            if (n) {
                if (strcmp(cmd, "PREFIXA") == 0) pr(0);
                else if (strcmp(cmd, "INFIXA") == 0) in(0);
                else po(0);
            }
            putchar('\n');
        }
    }
    return 0;
}
