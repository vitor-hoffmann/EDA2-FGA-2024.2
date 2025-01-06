#include <stdio.h>
#include <string.h>

int verificaSigla(const char* nome, const char* sigla) {
    int i = 0, j = 0;
    int lenNome = strlen(nome);
    int lenSigla = strlen(sigla);

    if (sigla[2] == 'X') {
        lenSigla = 2;  
    }

    while (i < lenNome && j < lenSigla) {
        if (nome[i] == sigla[j] || nome[i] == sigla[j] + 32) {
            j++; 
        }
        i++; 
    }

    return j == lenSigla;
}

int main() {
    char nome[100005];  
    char sigla[4];      

    scanf("%s", nome); 
    scanf("%s", sigla); 

    if (verificaSigla(nome, sigla)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}
