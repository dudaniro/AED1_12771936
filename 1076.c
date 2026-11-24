#include <stdio.h>
#include <string.h>

static char adj[1001][1001];
static char vis[1001];
static int V, cnt;

void dfs(int u) {
    vis[u] = 1; cnt++;
    for (int v = 0; v < V; v++)
        if (adj[u][v] && !vis[v]) dfs(v);
}

int main(void) {
    int T, N, A;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &N, &V, &A);
        for (int i = 0; i < V; i++) { memset(adj[i], 0, V); vis[i] = 0; }
        while (A--) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a][b] = adj[b][a] = 1;
        }
        cnt = 0;
        dfs(N);
        printf("%d\n", 2 * (cnt - 1));
    }
    return 0;
}
