typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}Arvore;

typedef struct fila {
    Arvore* no;
    struct fila* prox;
} Fila;

void entraFila(Fila** frente, Fila** tras, Arvore* no);
Arvore* saiFila(Fila** frente);
Arvore* criaArv(int elem);
void insereArv(Arvore** raiz, int elem);

void liberaArvore(Arvore* raiz);