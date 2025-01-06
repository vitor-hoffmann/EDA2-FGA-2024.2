#include <stdio.h>
#include <string.h>

// Função para calcular o percurso pós-fixo
void calcularPosfixo(const char* prefixo, const char* infixo, int n, char* posfixo, int* posIndex) {
    if (n <= 0) {
        return;
    }

    // Raiz é o primeiro caractere do prefixo
    char raiz = prefixo[0];

    // Encontra a posição da raiz no infixo
    int raizIndex = strchr(infixo, raiz) - infixo;

    // Calcula o percurso para a subárvore esquerda
    calcularPosfixo(prefixo + 1, infixo, raizIndex, posfixo, posIndex);

    // Calcula o percurso para a subárvore direita
    calcularPosfixo(prefixo + 1 + raizIndex, infixo + raizIndex + 1, n - raizIndex - 1, posfixo, posIndex);

    // Adiciona a raiz ao percurso pós-fixo
    posfixo[(*posIndex)++] = raiz;
}

// Função principal
int main() {
    int casos;
    char buffer[256];

    // Lê o número de casos de teste
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 1; // Se não conseguir ler a entrada, encerra o programa
    }
    sscanf(buffer, "%d", &casos);

    while (casos--) {
        int n;
        char prefixo[53], infixo[53], posfixo[53];

        // Lê os valores de n, prefixo e infixo
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return 1; // Se não conseguir ler, encerra
        }
        sscanf(buffer, "%d %s %s", &n, prefixo, infixo);

        int posIndex = 0; // Índice para preencher o percurso pós-fixo
        calcularPosfixo(prefixo, infixo, n, posfixo, &posIndex);

        posfixo[posIndex] = '\0'; // Adiciona o terminador de string
        printf("%s\n", posfixo); // Imprime o percurso pós-fixo
    }

    return 0;
}
