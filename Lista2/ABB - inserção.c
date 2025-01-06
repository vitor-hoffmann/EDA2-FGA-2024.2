#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para criar um novo nó
no* criarNo(int chave) {
    no* novo = (no*)malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função para inserir um valor na árvore binária de busca
no* inserir(no *r, int x) {
    // Caso base: insere na posição correta se a raiz for nula
    if (r == NULL) {
        return criarNo(x);
    }

    // Chaves repetidas não são permitidas
    if (x == r->chave) {
        return r; // Nenhuma modificação é feita
    }

    // Insere na subárvore esquerda se o valor for menor
    if (x < r->chave) {
        r->esq = inserir(r->esq, x);
    } 
    // Insere na subárvore direita se o valor for maior
    else if (x > r->chave) {
        r->dir = inserir(r->dir, x);
    }

    return r; // Retorna a raiz atualizada
}
