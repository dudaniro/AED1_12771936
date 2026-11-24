#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAXN 1010
#define MAXQ (MAXN * MAXN) /* a fila pode receber o mesmo vértice várias vezes */

int n, m, c, k;
int grafo[MAXN][MAXN];
int custo[MAXN];

/* fila circular */
static int fila[MAXQ];
static int ini = 0, fim = 0, tam = 0;

static void push(int x) {
    fila[fim] = x;
    fim = (fim + 1) % MAXQ;
    tam++;
}

static int pop(void) {
    int x = fila[ini];
    ini = (ini + 1) % MAXQ;
    tam--;
    return x;
}

/* função de infinitar o grafo e o vetor custo */
void infinito(void) {
    for (int i = 0; i <= n; i++) {
        custo[i] = INF;
        for (int j = 0; j <= n; j++)
            grafo[i][j] = INF;
    }
}

/* algoritmo de Dijkstra (na prática, uma busca tipo Bellman-Ford com fila) */
int dijkstra(int ori, int dest) {
    custo[ori] = 0;
    push(ori);
    while (tam > 0) {
        int i = pop();
        for (int j = 0; j < n; j++) {
            if (grafo[i][j] != INF && custo[j] > custo[i] + grafo[i][j]) {
                custo[j] = custo[i] + grafo[i][j];
                push(j);
            }
        }
    }
    return custo[dest];
}

int main(void) {
    while (scanf("%d %d %d %d", &n, &m, &c, &k), (n || m || c || k)) {

        /* esvazia a fila entre os casos de teste */
        ini = fim = tam = 0;

        infinito();

        for (int i = 1; i <= m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            if (u >= c && v >= c) {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
            if (u >= c && v < c) grafo[u][v] = p;
            if (u < c && v >= c) grafo[v][u] = p;

            if (u < c && v < c && abs(u - v) == 1) {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
        }

        printf("%d\n", dijkstra(k, c - 1));
    }
    return 0;
}
