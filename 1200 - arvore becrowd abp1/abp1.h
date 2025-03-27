typedef struct no{
    char info[7];
    struct no *esq;
    struct no *dir;
}Arvore;

typedef struct pilha{
    Arvore* no;
    struct pilha* prox;
} Pilha;

void empilha(Pilha** topo, Arvore* no);
Arvore* desempilha(Pilha** topo);

Arvore* criaArv(char elem);
void insereArv(Arvore** raiz, char elem);
void infixa(Arvore* raiz);
void prefixa(Arvore* raiz);
void posfixa(Arvore* raiz);
void BuscaArvore(Arvore* raiz, char elem);

void liberaArvore(Arvore* raiz);