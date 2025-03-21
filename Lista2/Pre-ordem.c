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
void empilhar(Pilha** topo, No* no) {
    Pilha* novoElemento = (Pilha*)malloc(sizeof(Pilha));
    if (novoElemento == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novoElemento->no = no;
    novoElemento->prox = *topo;
    *topo = novoElemento;
}

// Função para desempilhar um nó
No* desempilhar(Pilha** topo) {
    if (*topo == NULL) {
        return NULL;
    }
    Pilha* temp = *topo;
    No* no = temp->no;
    *topo = temp->prox;
    free(temp);
    return no;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha* topo) {
    return topo == NULL;
}

// Função de percurso pré-ordem não-recursivo
void pre_ordem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    Pilha* pilha = NULL; // Inicializa a pilha
    empilhar(&pilha, raiz);

    while (!pilhaVazia(pilha)) {
        // Remove o nó do topo da pilha e o processa
        No* atual = desempilhar(&pilha);
        printf("%d ", atual->dado);

        // Empilha o filho direito (primeiro a sair por ser pós-visitado)
        if (atual->direita != NULL) {
            empilhar(&pilha, atual->direita);
        }

        // Empilha o filho esquerdo (visitado primeiro)
        if (atual->esquerda != NULL) {
            empilhar(&pilha, atual->esquerda);
        }
    }
}