#include <stdio.h>
#include <stdlib.h>
#include "abp2.h"


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
        printf("%d", atual->info);
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
        printf("%d", atual->info);
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
        printf("%d", atual->info);
        espacoFinal = 0;
    }
    printf("\n");
}

void BuscaArvore(Arvore* raiz, int elem){
    Pilha* pilha = NULL;
    Arvore* atual = raiz;
    while (atual != NULL || pilha != NULL){
        while (atual != NULL) {
            empilha(&pilha, atual);
            if (atual->info == elem){
                printf("%d existe\n", elem);
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
                printf("%d existe\n", elem);
                return;
            }
            atual = atual->dir;
        }
    }
    printf("%d nao existe\n", elem);
}

Arvore* removeNo(Arvore* raiz, int valor) {
    Arvore* atual = raiz;
    Arvore* pai = NULL;

    while (atual != NULL && atual->info != valor) {
        pai = atual;
        if (valor < atual->info) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    if (atual == NULL) {
        return raiz;
    }
    //sem filho
    if (atual->esq == NULL && atual->dir == NULL) {
        atualizarPai(pai, atual, NULL);
        free(atual);
    }
    //filho único
    else if (atual->esq == NULL || atual->dir == NULL) {
        Arvore* filho = (atual->esq != NULL) ? atual->esq : atual->dir;
        if (pai == NULL) {
            free(atual);
            return filho;
        }
        atualizarPai(pai, atual, filho);
        free(atual);
    }
    //dois filhos
    else {
    Arvore* aux = atual->esq;
    Arvore* paiAux = atual;

    while (aux->dir != NULL) {
        paiAux = aux;
        aux = aux->dir;
    }
    atual->info = aux->info;
    atualizarPai(paiAux, aux, aux->esq);
    free(aux);
}

    return raiz;
}

void atualizarPai(Arvore* pai, Arvore* atual, Arvore* novo) {
    if (pai == NULL) {
        return;
    }
    if (pai->esq == atual) {
        pai->esq = novo;
    } else {
        pai->dir = novo;
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