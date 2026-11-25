#include <stdio.h>
#include <ctype.h>

static int prec(char c) {
    switch (c) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

int main(void) {
    int n;
    char e[1005];
    scanf("%d", &n);
    while (n--) {
        scanf("%1004s", e);
        char pilha[1005];
        int topo = 0;
        for (int i = 0; e[i]; i++) {
            char c = e[i];
            if (isalnum((unsigned char)c)) {
                putchar(c);
            } else if (c == '(') {
                pilha[topo++] = c;
            } else if (c == ')') {
                while (topo > 0 && pilha[topo - 1] != '(') putchar(pilha[--topo]);
                if (topo > 0) topo--;    // descarta '('
            } else {
                while (topo > 0 && pilha[topo - 1] != '(' &&
                       (prec(pilha[topo - 1]) > prec(c) ||
                        (prec(pilha[topo - 1]) == prec(c) && c != '^')))
                    putchar(pilha[--topo]);
                pilha[topo++] = c;
            }
        }
        while (topo > 0) putchar(pilha[--topo]);
        putchar('\n');
    }
    return 0;
}
