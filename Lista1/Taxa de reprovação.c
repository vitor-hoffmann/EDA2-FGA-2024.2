#include <stdio.h>

#define MAX_DISCIPLINAS 1000

int main() {
    int D;
    scanf("%d", &D);
    
    while (1) {
        int ano, semestre, m;
        if (scanf("%d %d %d", &ano, &semestre, &m) != 3) break;

        int codigo[MAX_DISCIPLINAS];
        int matriculados[MAX_DISCIPLINAS];
        int aprovados[MAX_DISCIPLINAS];
        int reprovados[MAX_DISCIPLINAS];
        
        int max_reprovados = 0;
        
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &codigo[i], &matriculados[i], &aprovados[i]);
            reprovados[i] = matriculados[i] - aprovados[i];
            if (reprovados[i] > max_reprovados) {
                max_reprovados = reprovados[i];
            }
        }
        
        printf("%d/%d\n", ano, semestre);
        
        int disciplinas_max[MAX_DISCIPLINAS];
        int count = 0;

        for (int i = 0; i < m; i++) {
            if (reprovados[i] == max_reprovados) {
                disciplinas_max[count++] = codigo[i];
            }
        }

        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (disciplinas_max[i] > disciplinas_max[j]) {
                    int temp = disciplinas_max[i];
                    disciplinas_max[i] = disciplinas_max[j];
                    disciplinas_max[j] = temp;
                }
            }
        }

        for (int i = 0; i < count; i++) {
            printf("%d ", disciplinas_max[i]);
        }
        printf("\n\n");
    }

    return 0;
}
