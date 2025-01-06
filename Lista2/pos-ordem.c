#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore
typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

// Estrutura da pilha
typedef struct Pilha {
    No* no;
    int visitado; // Marcador para saber se o nó já foi processado
    struct Pilha* prox;
} Pilha;

// Função para criar um novo nó
No* criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para empilhar um nó
void empilhar(Pilha** topo, No* no, int visitado) {
    Pilha* novoElemento = (Pilha*)malloc(sizeof(Pilha));
    if (novoElemento == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novoElemento->no = no;
    novoElemento->visitado = visitado;
    novoElemento->prox = *topo;
    *topo = novoElemento;
}

// Função para desempilhar um nó
No* desempilhar(Pilha** topo, int* visitado) {
    if (*topo == NULL) {
        return NULL;
    }
    Pilha* temp = *topo;
    No* no = temp->no;
    *visitado = temp->visitado;
    *topo = temp->prox;
    free(temp);
    return no;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha* topo) {
    return topo == NULL;
}

// Função de percurso pós-ordem (não-recursivo)
void pos_ordem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    Pilha* pilha = NULL; // Inicializa a pilha
    empilhar(&pilha, raiz, 0);

    while (!pilhaVazia(pilha)) {
        int visitado;
        No* atual = desempilhar(&pilha, &visitado);

        if (atual == NULL) {
            continue;
        }

        if (visitado) {
            // Se o nó já foi visitado, processa (imprime)
            printf("%d ", atual->dado);
        } else {
            // Empilha o nó atual como "visitado"
            empilhar(&pilha, atual, 1);

            // Empilha os filhos direito e esquerdo
            if (atual->direita != NULL) {
                empilhar(&pilha, atual->direita, 0);
            }
            if (atual->esquerda != NULL) {
                empilhar(&pilha, atual->esquerda, 0);
            }
        }
    }
}
