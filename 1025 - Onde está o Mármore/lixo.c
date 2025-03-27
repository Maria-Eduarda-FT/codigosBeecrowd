int main(){
    int aux, aux2, procurar, ajudantePedreiro, cont = 0;

    while (scanf("%d", &aux) && scanf("%d", &aux2) && aux !=0 && aux2 !=0){
        //printf("%d e %d", aux, aux2);
        ajudantePedreiro = aux;
        int i = 0, vetor[aux];
        while (aux--){
           scanf("%d", &vetor[i]);
           i++;
        }
        if (aux <= 0){
            cont++;
            printf("CASE# %d:\n", cont);
        }
        while(aux2--){
            scanf("%d", &procurar);
            BubbleSort(&vetor, ajudantePedreiro);
            buscaBinaria(&vetor, ajudantePedreiro, procurar);
        }
    }
}