#include <stdio.h>

int main() {
    int D, A, N;
    scanf("%d %d %d", &D, &A, &N);

    int valor = D + (N - 1) * A;

    int diarias = 32 - N;

    int total = diarias * valor;

    printf("%d\n", total);

    return 0;
}
