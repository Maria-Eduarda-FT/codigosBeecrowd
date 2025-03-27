#include <stdio.h>
#include <stdlib.h>
#include "arvNivel.h"

Arvore* criaArv(int elem){
    Arvore* arve;
    arve = (Arvore*)malloc(sizeof(Arvore));
    arve->info = elem;
    arve->dir = NULL;
    arve->esq = NULL;
    return arve;
}
void insereArv(Arvore** raiz, int elem){ //otimizado sem no
    if (*raiz == NULL) {
        *raiz = criaArv(elem);
        return;
    }
    if (elem < (*raiz)->info) {
        insereArv(&((*raiz)->esq), elem);
    } else {
        insereArv(&((*raiz)->dir), elem);
    }
}

void entraFila(Fila** frente, Fila** tras, Arvore* no){
    Fila* novo = (Fila*)malloc(sizeof(Fila));
    novo->no = no;
    novo->prox = NULL;
    if (*tras == NULL){
        *frente = *tras = novo;
    } else {
        (*tras)->prox = novo;
        *tras = novo;
    }
}

Arvore* saiFila(Fila** frente){
    if (*frente == NULL) return NULL;
    Fila* temp = *frente;
    Arvore* no = temp->no;
    *frente = (*frente)->prox;
    free(temp);
    return no;
}

void listaPorNv(Arvore* raiz) {
    Fila* frente = NULL;
    Fila* tras = NULL;
    entraFila(&frente, &tras, raiz);
    int espacoFinal = 1;
    while (frente != NULL) {
        Arvore* atual = saiFila(&frente);
        if (!espacoFinal) {
            printf(" ");
        }
        printf("%d", atual->info);
        espacoFinal = 0;
        if (atual->esq != NULL) {
            entraFila(&frente, &tras, atual->esq);
        }
        if (atual->dir != NULL) {
            entraFila(&frente, &tras, atual->dir);
        }
    }
}

void liberaArvore(Arvore* raiz){
    if (raiz == NULL) {
        return;
    }
    liberaArvore(raiz->esq);
    liberaArvore(raiz->dir);
    free(raiz);
}