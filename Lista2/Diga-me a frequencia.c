#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char caractere;
    int frequencia;
} Frequencia;

int compara(const void *a, const void *b) {
    Frequencia *fa = (Frequencia *)a;
    Frequencia *fb = (Frequencia *)b;

    if (fa->frequencia != fb->frequencia) {
        return fa->frequencia - fb->frequencia; // Ordem crescente por frequencia
    }
    return fa->caractere - fb->caractere; // Ordem crescente por valor ASCII
}

void processaLinha(const char *linha) {
    int frequencias[256] = {0}; // Frequencias de caracteres (0-255 ASCII)
    int tamanho = strlen(linha);

    for (int i = 0; i < tamanho; i++) {
        frequencias[(unsigned char)linha[i]]++;
    }

    Frequencia lista[256];
    int count = 0;

    for (int i = 0; i < 256; i++) {
        if (frequencias[i] > 0) {
            lista[count].caractere = i;
            lista[count].frequencia = frequencias[i];
            count++;
        }
    }

    qsort(lista, count, sizeof(Frequencia), compara);

    for (int i = 0; i < count; i++) {
        printf("%d %d\n", (int)lista[i].caractere, lista[i].frequencia);
    }
}

int main() {
    char linha[1001];
    int primeiraLinha = 1;

    while (fgets(linha, sizeof(linha), stdin)) {
        linha[strcspn(linha, "\n")] = '\0'; // Remove o caractere de nova linha

        if (!primeiraLinha) {
            printf("\n");
        }
        primeiraLinha = 0;

        processaLinha(linha);
    }

    printf("\n");
    return 0;
}
