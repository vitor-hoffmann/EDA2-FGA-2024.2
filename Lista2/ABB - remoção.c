#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para encontrar o maior valor na subárvore esquerda (antecessor)
no* encontrarAntecessor(no* r) {
    no* atual = r;
    while (atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual;
}

// Função para remover um valor da árvore binária de busca
no* remover(no* r, int x) {
    if (r == NULL) {
        return NULL; // Árvore vazia ou valor não encontrado
    }

    if (x < r->chave) {
        // O valor a ser removido está na subárvore esquerda
        r->esq = remover(r->esq, x);
    } else if (x > r->chave) {
        // O valor a ser removido está na subárvore direita
        r->dir = remover(r->dir, x);
    } else {
        // Encontrou o nó a ser removido
        if (r->esq == NULL && r->dir == NULL) {
            // Caso 1: Nó folha
            free(r);
            return NULL;
        } else if (r->esq == NULL) {
            // Caso 2: Nó com apenas filho direito
            no* temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            // Caso 2: Nó com apenas filho esquerdo
            no* temp = r->esq;
            free(r);
            return temp;
        } else {
            // Caso 3: Nó com dois filhos
            no* antecessor = encontrarAntecessor(r->esq);
            r->chave = antecessor->chave; // Substitui o valor do nó pela chave do antecessor
            r->esq = remover(r->esq, antecessor->chave); // Remove o antecessor
        }
    }

    return r; // Retorna a raiz atualizada
}
