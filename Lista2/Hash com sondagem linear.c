#include <stdlib.h>

// Estrutura da tabela hash
typedef struct {
  int *tb; // tabela hash
  int M;   // tamanho da tabela hash
  int N;   // total de chaves presentes na tabela
} TH;

// Declaração da função aumentaTamanho (supondo já implementada externamente)
int aumentaTamanho(int M);

// Função hash modular
int hash(int chave, int M) {
  return chave % M;
}

// Redimensiona a tabela hash
void THredimensiona(TH *h) {
  int novoM = aumentaTamanho(h->M);
  int *novaTabela = malloc(novoM * sizeof(int));
  for (int i = 0; i < novoM; i++) {
    novaTabela[i] = -1; // Inicializa a nova tabela
  }

  // Reinsere as chaves da tabela antiga na nova tabela
  for (int i = 0; i < h->M; i++) {
    if (h->tb[i] != -1) {
      int idx = hash(h->tb[i], novoM);
      while (novaTabela[idx] != -1) {
        idx = (idx + 1) % novoM;
      }
      novaTabela[idx] = h->tb[i];
    }
  }

  free(h->tb); // Libera a tabela antiga
  h->tb = novaTabela;
  h->M = novoM;
}

// Insere uma chave na tabela hash
void THinsere(TH *h, int ch) {
  // Redimensiona a tabela se a ocupação for maior que 50%
  if (h->N > h->M / 2) {
    THredimensiona(h);
  }

  // Calcula o índice inicial com a função hash
  int idx = hash(ch, h->M);

  // Realiza a sondagem linear para encontrar uma posição disponível
  while (h->tb[idx] != -1) {
    if (h->tb[idx] == ch) {
      return; // Chave já presente na tabela
    }
    idx = (idx + 1) % h->M;
  }

  // Insere a chave na posição encontrada
  h->tb[idx] = ch;
  h->N++; // Incrementa o total de chaves
}

// Remove uma chave da tabela hash
int THremove(TH *h, int ch) {
  // Calcula o índice inicial com a função hash
  int idx = hash(ch, h->M);

  // Realiza a sondagem linear para localizar a chave
  while (h->tb[idx] != -1) {
    if (h->tb[idx] == ch) {
      h->tb[idx] = -1; // Marca a posição como vazia
      h->N--;          // Decrementa o total de chaves

      // Reinsere todas as chaves subsequentes na tabela
      int proximoIdx = (idx + 1) % h->M;
      while (h->tb[proximoIdx] != -1) {
        int chaveReinserir = h->tb[proximoIdx];
        h->tb[proximoIdx] = -1;
        h->N--;
        THinsere(h, chaveReinserir);
        proximoIdx = (proximoIdx + 1) % h->M;
      }

      return 0; // Chave encontrada e removida
    }
    idx = (idx + 1) % h->M;
  }

  return -1; // Chave não encontrada
}

// Busca uma chave na tabela hash
int THbusca(TH *h, int ch) {
  // Calcula o índice inicial com a função hash
  int idx = hash(ch, h->M);

  // Realiza a sondagem linear para procurar a chave
  while (h->tb[idx] != -1) {
    if (h->tb[idx] == ch) {
      return 1; // Chave encontrada
    }
    idx = (idx + 1) % h->M;
  }

  return 0; // Chave não encontrada
}
