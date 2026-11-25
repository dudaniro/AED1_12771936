#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1105];
    while (fgets(s, sizeof s, stdin)) {
        char pilha[1105];
        int topo = 0, ok = 1;
        for (int i = 0; s[i] && ok; i++) {
            if (s[i] == '(') pilha[topo++] = '(';
            else if (s[i] == ')') {
                if (topo == 0) ok = 0;
                else topo--;
            }
        }
        if (topo != 0) ok = 0;
        puts(ok ? "correct" : "incorrect");
    }
    return 0;
}
