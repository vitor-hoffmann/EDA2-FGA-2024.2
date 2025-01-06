#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    celula *novo = malloc(sizeof(celula)); 
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        return;
    }
    novo->dado = x;
    novo->prox = le->prox; 
    le->prox = novo;     
}

void insere_antes(celula *le, int x, int y) {
    celula *atual = le;
    while (atual->prox != NULL && atual->prox->dado != y) {
        atual = atual->prox;
    }
    
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        return;
    }
    novo->dado = x;
    novo->prox = atual->prox; 
    atual->prox = novo;       
}
