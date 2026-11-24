#include <stdio.h>
#include <string.h>

static int adj[26][26], vis[26], comp[26], V;

void dfs(int u) {
    vis[u] = 1; comp[u] = 1;
    for (int v = 0; v < V; v++)
        if (adj[u][v] && !vis[v]) dfs(v);
}

int main(void) {
    int N;
    scanf("%d", &N);
    for (int c = 1; c <= N; c++) {
        int E;
        scanf("%d %d", &V, &E);
        memset(adj, 0, sizeof adj);
        memset(vis, 0, sizeof vis);
        while (E--) {
            char a, b;
            scanf(" %c %c", &a, &b);
            adj[a - 'a'][b - 'a'] = adj[b - 'a'][a - 'a'] = 1;
        }
        printf("Case #%d:\n", c);
        int total = 0;
        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;
            memset(comp, 0, sizeof comp);
            dfs(i);
            for (int j = 0; j < V; j++)
                if (comp[j]) printf("%c,", 'a' + j);
            putchar('\n');
            total++;
        }
        printf("%d connected components\n\n", total);
    }
    return 0;
}
