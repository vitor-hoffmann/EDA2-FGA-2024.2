#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 65536 // 2^16 tamanho maximo da tabela hash
#define VAZIO -1

typedef struct {
  char palavra[17];
  int votos;
  int ocupado;
} Entrada;

typedef struct {
  Entrada *tb;
  int M;
} TabelaHash;

int hash(const char *palavra, int tentativa, int M) {
  unsigned int h = 0;
  for (int i = 0; palavra[i] != '\0'; i++) {
    h = (h * 31 + palavra[i]) % M;
  }
  return (h + tentativa) % M;
}

void inicializaTabela(TabelaHash *tabela, int M) {
  tabela->tb = malloc(M * sizeof(Entrada));
  for (int i = 0; i < M; i++) {
    tabela->tb[i].ocupado = VAZIO;
  }
  tabela->M = M;
}

int busca(TabelaHash *tabela, const char *palavra) {
  int tentativa = 0;
  while (tentativa < tabela->M) {
    int idx = hash(palavra, tentativa, tabela->M);
    if (tabela->tb[idx].ocupado == VAZIO) {
      return -1; // Palavra nao encontrada
    }
    if (tabela->tb[idx].ocupado == 1 && strcmp(tabela->tb[idx].palavra, palavra) == 0) {
      return idx; // Palavra encontrada
    }
    tentativa++;
  }
  return -1; // Palavra nao encontrada
}

void insere(TabelaHash *tabela, const char *palavra) {
  int idx = busca(tabela, palavra);
  if (idx != -1) {
    tabela->tb[idx].votos++;
    return;
  }

  int tentativa = 0;
  while (tentativa < tabela->M) {
    int idx = hash(palavra, tentativa, tabela->M);
    if (tabela->tb[idx].ocupado == VAZIO) {
      strcpy(tabela->tb[idx].palavra, palavra);
      tabela->tb[idx].votos = 1;
      tabela->tb[idx].ocupado = 1;
      return;
    }
    tentativa++;
  }
}

void reseta(TabelaHash *tabela, const char *palavra) {
  int idx = busca(tabela, palavra);
  if (idx != -1) {
    tabela->tb[idx].votos = 0;
  }
}

void liberaTabela(TabelaHash *tabela) {
  free(tabela->tb);
}

int main() {
  TabelaHash tabela;
  inicializaTabela(&tabela, TAM_MAX);

  int comando;
  char palavra[17];

  while (scanf("%d %s", &comando, palavra) != EOF) {
    if (comando == 1) {
      insere(&tabela, palavra);
    } else if (comando == 2) {
      int idx = busca(&tabela, palavra);
      printf("%d\n", (idx != -1) ? tabela.tb[idx].votos : 0);
    } else if (comando == 3) {
      reseta(&tabela, palavra);
    }
  }

  liberaTabela(&tabela);
  return 0;
}
