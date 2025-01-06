#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int valor;
    struct celula *proximo;
} celula;

int remove_depois(celula *p) {
    if (p == NULL || p->proximo == NULL) {
        return 0;
    }

    celula *temp = p->proximo;
    p->proximo = temp->proximo;
    free(temp);
    return 1;
}

void remove_elemento(celula *le, int x) {
    celula *cursor = le;

    while (cursor->proximo != NULL) {
        if (cursor->proximo->valor == x) {
            remove_depois(cursor);
            return;
        }
        cursor = cursor->proximo;
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *cursor = le;

    while (cursor->proximo != NULL) {
        if (cursor->proximo->valor == x) {
            remove_depois(cursor);
        } else {
            cursor = cursor->proximo;
        }
    }
}
