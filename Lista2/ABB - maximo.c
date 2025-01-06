#include <stdio.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no* maximo(no* r) {
    if (r == NULL) {
        return NULL; // Árvore vazia
    }

    // Percorre os nós à direita até encontrar o último
    while (r->dir != NULL) {
        r = r->dir;
    }

    return r; // Retorna o nó com o maior valor
}
