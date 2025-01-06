#include <stdio.h>

// Estruturas que relacionam os valores decimais com seus equivalentes romanos
typedef struct {
    int value;
    const char *roman;
} RomanNumeral;

RomanNumeral romanNumerals[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

// Função que converte um número inteiro para algarismos romanos
void toRoman(int number) {
    for (int i = 0; i < sizeof(romanNumerals) / sizeof(romanNumerals[0]); i++) {
        while (number >= romanNumerals[i].value) {
            printf("%s", romanNumerals[i].roman);
            number -= romanNumerals[i].value;
        }
    }
    printf("\n");
}

int main() {
    int n;
    
    // Leitura do número de inteiros a serem convertidos
    scanf("%d", &n);

    // Array para armazenar os números a serem convertidos
    int values[n];

    // Leitura dos valores a serem convertidos
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Converte cada valor para romano e imprime o resultado
    for (int i = 0; i < n; i++) {
        toRoman(values[i]);
    }

    return 0;
}
