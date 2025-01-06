#include <stdio.h>

// Definição da estrutura do nó da árvore binária
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para calcular a altura da árvore binária de busca
int altura(no *r) {
    if (r == NULL) {
        return 0; // Árvore vazia tem altura -1
    }

    // Calcula a altura das subárvores esquerda e direita
    int alturaEsq = altura(r->esq);
    int alturaDir = altura(r->dir);

    // Retorna a altura máxima entre as duas subárvores + 1
    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}
