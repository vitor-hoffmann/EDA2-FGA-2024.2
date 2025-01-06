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
void em_ordem(No* raiz) {
    Pilha* pilha = NULL; // Inicializa a pilha
    No* atual = raiz;

    while (!pilhaVazia(pilha) || atual != NULL) {
        // Vai até o nó mais à esquerda
        while (atual != NULL) {
            empilhar(&pilha, atual);
            atual = atual->esquerda;
        }

        // Processa o nó no topo da pilha
        atual = desempilhar(&pilha);
        printf("%d ", atual->dado);

        // Move para a subárvore direita
        atual = atual->direita;
    }
}

int main() {
    // Criando a árvore binária
    No* raiz = criarNo(2);
    raiz->esquerda = criarNo(5);
    raiz->direita = criarNo(7);
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita = criarNo(8);
    raiz->esquerda->direita->esquerda = criarNo(4);
    raiz->direita->esquerda = criarNo(1);
    raiz->direita->esquerda->direita = criarNo(9);
    raiz->direita->direita = criarNo(6);

    // Percurso em pré-ordem não recursivo
    printf("Percurso em pré-ordem (não recursivo): ");
    em_ordem(raiz);
    printf("\n");

    return 0;
}
