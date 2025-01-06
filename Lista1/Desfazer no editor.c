#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

// Estrutura da pilha
typedef struct Node {
    char data[MAX_STR];
    struct Node *next;
} Node;

Node *top = NULL; // Ponteiro para o topo da pilha

// Função para inserir uma nova alteração na pilha
void inserir(char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }
    strcpy(newNode->data, str);
    newNode->next = top;
    top = newNode;
}

// Função para desfazer a última alteração
void desfazer() {
    if (top == NULL) {
        printf("NULL\n");
        return;
    }
    Node *temp = top;
    printf("%s\n", top->data);
    top = top->next;
    free(temp);
}

// Função principal
int main() {
    char comando[MAX_STR];
    char str[MAX_STR];

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "inserir") == 0) {
            // Lê a string a ser inserida e chama a função
            scanf(" %[^\n]s", str); // Lê a string até o fim da linha
            inserir(str);
        } else if (strcmp(comando, "desfazer") == 0) {
            desfazer();
        }
    }

    return 0;
}
