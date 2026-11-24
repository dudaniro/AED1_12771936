#include <stdio.h>

#define MAXN 10005
#define MAXM 20005

int head[MAXN], nxt[MAXM], to[MAXM], indeg[MAXN], fila[MAXN];

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) { head[i] = -1; indeg[i] = 0; }
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            to[i] = b; nxt[i] = head[a]; head[a] = i;
            indeg[b]++;
        }
        int ini = 0, fim = 0, proc = 0;
        for (int i = 1; i <= n; i++) if (indeg[i] == 0) fila[fim++] = i;
        while (ini < fim) {
            int u = fila[ini++];
            proc++;
            for (int e = head[u]; e != -1; e = nxt[e])
                if (--indeg[to[e]] == 0) fila[fim++] = to[e];
        }
        puts(proc < n ? "SIM" : "NAO");
    }
    return 0;
}
