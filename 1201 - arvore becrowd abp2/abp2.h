typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}Arvore;

typedef struct pilha{
    Arvore* no;
    struct pilha* prox;
} Pilha;

void empilha(Pilha** topo, Arvore* no);
Arvore* desempilha(Pilha** topo);

Arvore* criaArv(int elem);
void insereArv(Arvore** raiz, int elem);
void infixa(Arvore* raiz);
void prefixa(Arvore* raiz);
void posfixa(Arvore* raiz);
void BuscaArvore(Arvore* raiz, int elem);

void liberaArvore(Arvore* raiz);