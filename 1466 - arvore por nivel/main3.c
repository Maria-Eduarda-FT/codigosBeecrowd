#include <stdio.h>
#include <stdlib.h>
#include "arvNivel.h"

int main() {
    int cont = 0, caso = 0, numTotal = 0, nElem = 1, elem;
    char entrada[150];
    Arvore* arv = NULL;

    while (fgets(entrada, sizeof(entrada), stdin) != NULL){
        int len = strlen(entrada);
        if (len > 1 && entrada[len - 1] == '\n') {
            entrada[len - 1] = '\0';
        }
        if (cont == 0) {
            numTotal = entrada[0] - '0';
        }
        else if(cont!= 0 && cont%2 != 0){
            nElem = entrada[0] - '0';
        }
        else if(cont!= 0 && cont%2 == 0){
            char* token = strtok(entrada, " ");
            while(nElem != 0 && token != NULL){
                elem = atoi(token);
                insereArv(&arv, elem);  
                nElem--;
                token = strtok(NULL, " ");
            }
            caso++;
            printf("Case %d\n",caso);
            listaPorNv(arv);
            if(caso!=numTotal)
                printf("\n");
            liberaArvore(arv);
        }
        cont++;
    }
    return 0;
}