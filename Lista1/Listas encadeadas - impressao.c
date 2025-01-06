#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }
    
    celula *atual = le->prox;
    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }
    printf(" -> NULL\n");
}

void imprime_rec(celula *le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }
    helper(le->prox);
    printf(" -> NULL\n");
}

void helper(celula *no) {
    if (no == NULL) {
        return;
    }
    printf("%d", no->dado);
    if (no->prox != NULL) {
        printf(" -> ");
    }
    helper(no->prox);
}
