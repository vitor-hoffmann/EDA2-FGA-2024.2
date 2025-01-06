#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 1048576 // 2^20 tamanho maximo da tabela hash
#define VAZIO -1

typedef struct {
  int colonia;
  char alimento[51];
  int ocupado;
} Entrada;

typedef struct {
  Entrada *tb;
  int M;
} TabelaHash;

int hash(int colonia, int tentativa, int M) {
  return (colonia + tentativa) % M;
}

void inicializaTabela(TabelaHash *tabela, int M) {
  tabela->tb = malloc(M * sizeof(Entrada));
  for (int i = 0; i < M; i++) {
    tabela->tb[i].ocupado = VAZIO;
  }
  tabela->M = M;
}

int insere(TabelaHash *tabela, int colonia, const char *alimento) {
  int tentativa = 0;
  while (tentativa < tabela->M) {
    int idx = hash(colonia, tentativa, tabela->M);
    if (tabela->tb[idx].ocupado == VAZIO) {
      tabela->tb[idx].colonia = colonia;
      strcpy(tabela->tb[idx].alimento, alimento);
      tabela->tb[idx].ocupado = 1;
      return 1; // Insercao bem-sucedida
    } else if (tabela->tb[idx].colonia == colonia && strcmp(tabela->tb[idx].alimento, alimento) == 0) {
      return 0; // Duplicata detectada
    }
    tentativa++;
  }
  return -1; // Falha ao inserir
}

void liberaTabela(TabelaHash *tabela) {
  free(tabela->tb);
}

int main() {
  TabelaHash tabela;
  inicializaTabela(&tabela, TAM_MAX);

  int colonia;
  char alimento[51];

  while (scanf("%d %s", &colonia, alimento) != EOF) {
    if (!insere(&tabela, colonia, alimento)) {
      printf("%d\n", colonia);
    }
  }

  liberaTabela(&tabela);
  return 0;
}
