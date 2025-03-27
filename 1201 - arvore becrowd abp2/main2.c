#include <stdio.h>
#include <stdlib.h>
#include "abp2.h"

int main() {
    char entrada[150];
    char elem;
    Arvore* arv = NULL;

    while (fgets(entrada, sizeof(entrada), stdin) != NULL) {
        int len = strlen(entrada);
        if (len > 1 && entrada[len - 1] == '\n') {
            entrada[len - 1] = '\0';
        }

        if (entrada[0] == 'I' && entrada[1] == ' ') {
            elem = entrada[2];
            insereArv(&arv, elem);
        } else if (strcmp(entrada, "INFIXA") == 0) {
            infixa(arv);
        } else if (strcmp(entrada, "PREFIXA") == 0) {
            prefixa(arv);
        } else if (strcmp(entrada, "POSFIXA") == 0) {
            posfixa(arv);
        } else if (entrada[0] == 'P' && entrada[1] == ' ') {
            elem = entrada[2];
            BuscaArvore(arv, elem);
        } else {
            liberaArvore(arv);
            break;
        }
    }

    return 0;
}
