#include <stdio.h>
#include <stdlib.h>
void QuickSort(int num[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = num[fim];
        int i = inicio - 1;
        for (int j = inicio; j < fim; j++) {
            if (num[j] <= pivo) {
                i++;
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
        int temp = num[i + 1];
        num[i + 1] = num[fim];
        num[fim] = temp;

        int p = i + 1;
        QuickSort(num, inicio, p - 1);
        QuickSort(num, p + 1, fim);
    }
}
void buscaBinaria(int num[], int tam, int valor) {
    int inicio = 0, fim = tam - 1, pos = -1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (num[meio] == valor) {
            pos = meio;
            fim = meio - 1;
        } else if (num[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    if (pos != -1) {
        printf("%d found at %d\n", valor, pos + 1);
    } else {
        printf("%d not found\n", valor);
    }
}
int main() {
    int n, q, cont = 1;

    while (scanf("%d %d", &n, &q) == 2 && n && q) {
        int vet[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &vet[i]);
        }
        QuickSort(vet, 0, n - 1);
        printf("CASE# %d:\n", cont++);

        while (q--) {
            int x;
            scanf("%d", &x);
            buscaBinaria(vet, n, x);
        }
    }

    return 0;
}