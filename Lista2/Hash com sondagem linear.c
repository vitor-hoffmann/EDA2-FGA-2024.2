#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *tb; // tabela hash
  int M;   // tamanho da tabela hash
  int N;   // total de chaves presentes na tabela
} TH;

int hash(int chave, int M) {
  return chave % M;
}

int aumentaTamanho(int M) {
  int novoTamanho = M * 2 + 1;
  for (int i = 2; i * i <= novoTamanho; i++) {
    if (novoTamanho % i == 0) {
      novoTamanho++;
      i = 1;
    }
  }
  return novoTamanho;
}

void THinicializa(TH *h, int M) {
  h->tb = malloc(M * sizeof(int));
  for (int i = 0; i < M; i++) {
    h->tb[i] = -1;
  }
  h->M = M;
  h->N = 0;
}

void THredimensiona(TH *h) {
  int novoM = aumentaTamanho(h->M);
  int *novaTabela = malloc(novoM * sizeof(int));
  for (int i = 0; i < novoM; i++) {
    novaTabela[i] = -1;
  }

  for (int i = 0; i < h->M; i++) {
    if (h->tb[i] != -1) {
      int idx = hash(h->tb[i], novoM);
      while (novaTabela[idx] != -1) {
        idx = (idx + 1) % novoM;
      }
      novaTabela[idx] = h->tb[i];
    }
  }

  free(h->tb);
  h->tb = novaTabela;
  h->M = novoM;
}

void THinsere(TH *h, int ch) {
  if (h->N > h->M / 2) {
    THredimensiona(h);
  }

  int idx = hash(ch, h->M);
  while (h->tb[idx] != -1) {
    if (h->tb[idx] == ch) return;
    idx = (idx + 1) % h->M;
  }

  h->tb[idx] = ch;
  h->N++;
}

int THremove(TH *h, int ch) {
  int idx = hash(ch, h->M);
  while (h->tb[idx] != -1) {
    if (h->tb[idx] == ch) {
      h->tb[idx] = -1;
      h->N--;

      int proximoIdx = (idx + 1) % h->M;
      while (h->tb[proximoIdx] != -1) {
        int chaveReinserir = h->tb[proximoIdx];
        h->tb[proximoIdx] = -1;
        h->N--;
        THinsere(h, chaveReinserir);
        proximoIdx = (proximoIdx + 1) % h->M;
      }

      return 0;
    }
    idx = (idx + 1) % h->M;
  }
  return -1;
}

int THbusca(TH *h, int ch) {
  int idx = hash(ch, h->M);
  while (h->tb[idx] != -1) {
    if (h->tb[idx] == ch) return 1;
    idx = (idx + 1) % h->M;
  }
  return 0;
}
