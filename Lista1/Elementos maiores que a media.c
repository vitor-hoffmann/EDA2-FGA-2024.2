#include <stdio.h>

int main() {
    int A;
    scanf("%d", &A);

    int v[A];
    long long total = 0;

    for (int i = 0; i < A; i++) {
        scanf("%d", &v[i]);
        total += v[i];
    }

    int media = total / A;

    int achou = 0;  
    for (int i = 0; i < A; i++) {
        if (v[i] > media) {
            if (achou) {
                printf(" ");
            }
            printf("%d", v[i]);
            achou = 1;
        }
    }

    if (!achou) {
        printf("0");
    }

    printf("\n");
    return 0;
}
