#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

typedef struct {
  celula *tb; // tabela hash
  int M;      // tamanho da tabela hash
  int N;      // total de chaves presentes na tabela
} TH;

int hash(int chave, int M) {
  return chave % M;
}

void THinicializa(TH *h, int M) {
  h->tb = malloc(M * sizeof(celula));
  for (int i = 0; i < M; i++) {
    h->tb[i].prox = NULL;
  }
  h->M = M;
  h->N = 0;
}

void THinsere(TH *h, int ch) {
  int idx = hash(ch, h->M);
  celula *atual = h->tb[idx].prox;
  while (atual) {
    if (atual->dado == ch) return; // Chave já presente
    atual = atual->prox;
  }
  celula *nova = malloc(sizeof(celula));
  nova->dado = ch;
  nova->prox = h->tb[idx].prox;
  h->tb[idx].prox = nova;
  h->N++;
}

int THremove(TH *h, int ch) {
  int idx = hash(ch, h->M);
  celula *atual = &h->tb[idx];
  while (atual->prox) {
    if (atual->prox->dado == ch) {
      celula *remover = atual->prox;
      atual->prox = remover->prox;
      free(remover);
      h->N--;
      return 0;
    }
    atual = atual->prox;
  }
  return -1; // Chave não encontrada
}

int THbusca(TH *h, int ch) {
  int idx = hash(ch, h->M);
  celula *atual = h->tb[idx].prox;
  while (atual) {
    if (atual->dado == ch) return 1;
    atual = atual->prox;
  }
  return 0;
}

void THlibera(TH *h) {
  for (int i = 0; i < h->M; i++) {
    celula *atual = h->tb[i].prox;
    while (atual) {
      celula *remover = atual;
      atual = atual->prox;
      free(remover);
    }
  }
  free(h->tb);
}

void imprimeTabela(TH *h) {
  for (int i = 0; i < h->M; i++) {
    printf("%d: ", i);
    celula *atual = h->tb[i].prox;
    while (atual) {
      printf("%d -> ", atual->dado);
      atual = atual->prox;
    }
    printf("NULL\n");
  }
}
