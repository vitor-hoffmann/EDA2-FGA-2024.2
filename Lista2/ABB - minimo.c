#include <stdio.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no* minimo(no* r) {
    if (r == NULL) {
        return NULL; // Árvore vazia
    }

    // Percorre os nós à direita até encontrar o último
    while (r->esq != NULL) {
        r = r->esq;
    }

    return r; // Retorna o nó com o maior valor
}
