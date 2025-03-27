#include <stdio.h>
#include <stdlib.h>
#include "abp1.h"

void empilha(Pilha** topo, Arvore* no){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->no = no;
    novo->prox = *topo;
    *topo = novo;
}
Arvore* desempilha(Pilha** topo){
    if (*topo == NULL) return NULL;
    Pilha* temp = *topo;
    Arvore* no = temp->no;
    *topo = temp->prox;
    free(temp);
    return no;
}

Arvore* criaArv(char elem){
    Arvore* arve;
    arve = (Arvore*)malloc(sizeof(Arvore));
    arve->info = elem;
    arve->dir = NULL;
    arve->esq = NULL;
    return arve;
}
void insereArv(Arvore** raiz, char elem){
    Arvore* no = criaArv(elem);
    if (no == NULL) return;

    if (*raiz == NULL){
        *raiz = no;
        return;
    }

    Arvore* atual = *raiz;
    Arvore* pai = NULL;
    while (atual != NULL){
        pai = atual;
        if (no->info < atual->info)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    if (no->info < pai->info)
        pai->esq = no;
    else
        pai->dir = no;
    return;
}

void infixa(Arvore* raiz){
    Pilha* pilha = NULL;
    Arvore* atual = raiz;
    int espacoFinal = 1;
    while (atual != NULL || pilha != NULL){
        while (atual != NULL) {
            empilha(&pilha, atual);
            atual = atual->esq;
        }
        atual = desempilha(&pilha);
        if (!espacoFinal) {
            printf(" ");
        }
        printf("%c", atual->info);
        espacoFinal = 0;
        atual = atual->dir;
    }
    printf("\n");
}
void prefixa(Arvore* raiz) {
    Pilha* pilha = NULL;
    empilha(&pilha, raiz);
    int espacoFinal = 1;

    while (pilha != NULL) {
        Arvore* atual = desempilha(&pilha);

        if (!espacoFinal) {
            printf(" ");
        }
        printf("%c", atual->info);
        espacoFinal = 0;

        if (atual->dir != NULL) {
            empilha(&pilha, atual->dir);
        }
        if (atual->esq != NULL) {
            empilha(&pilha, atual->esq);
        }
    }
    printf("\n");
}
void posfixa(Arvore* raiz) {
    Pilha* pilha1 = NULL;
    Pilha* pilha2 = NULL;
    empilha(&pilha1, raiz);
    while (pilha1 != NULL) {
        Arvore* atual = desempilha(&pilha1);
        empilha(&pilha2, atual);
        if (atual->esq != NULL) {
            empilha(&pilha1, atual->esq);
        }
        if (atual->dir != NULL) {
            empilha(&pilha1, atual->dir);
        }
    }
    int espacoFinal = 1;
    while (pilha2 != NULL) {
        Arvore* atual = desempilha(&pilha2);
        if (!espacoFinal) {
            printf(" ");
        }
        printf("%c", atual->info);
        espacoFinal = 0;
    }
    printf("\n");
}

void BuscaArvore(Arvore* raiz, char elem){
    Pilha* pilha = NULL;
    Arvore* atual = raiz;
    while (atual != NULL || pilha != NULL){
        while (atual != NULL) {
            empilha(&pilha, atual);
            if (atual->info == elem){
                printf("%c existe\n", elem);
                return;
            }
            if (elem < atual->info)
                atual = atual->esq;
            else
                atual = atual->dir;
        }
        atual = desempilha(&pilha);
        if (atual != NULL) {
            if (atual->info == elem){
                printf("%c existe\n", elem);
                return;
            }
            atual = atual->dir;
        }
    }
    printf("%c nao existe\n", elem);
}

void liberaArvore(Arvore* raiz){
    if (raiz == NULL) {
        return;
    }
    liberaArvore(raiz->esq);
    liberaArvore(raiz->dir);
    free(raiz);
}