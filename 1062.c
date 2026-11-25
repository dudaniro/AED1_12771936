#include <stdio.h>

int main(void) {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int perm[1005], pilha[1005];
        for (;;) {
            int a;
            if (scanf("%d", &a) != 1 || a == 0) break;
            perm[0] = a;
            for (int i = 1; i < n; i++) scanf("%d", &perm[i]);

            int topo = 0, prox = 1, ok = 1;
            for (int i = 0; i < n && ok; i++) {
                while (prox <= n && (topo == 0 || pilha[topo - 1] != perm[i]))
                    pilha[topo++] = prox++;
                if (topo > 0 && pilha[topo - 1] == perm[i]) topo--;
                else ok = 0;
            }
            puts(ok ? "Yes" : "No");
        }
        putchar('\n');
    }
    return 0;
}
