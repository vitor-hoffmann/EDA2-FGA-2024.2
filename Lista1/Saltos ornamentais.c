#include <stdio.h>

float MediaSalto(){
    float D; 
    float notas[7]; 
    float ma, me, total = 0, media, final;

    scanf("%f", &D);

    for (int i = 0; i < 7; i++) {
        scanf("%f", &notas[i]);
    }

    ma = me = notas[0];

    for (int i = 0; i < 7; i++) {
        if (notas[i] < me) {
            me = notas[i];
        }
        if (notas[i] > ma) {
            ma = notas[i];
        }
        total += notas[i]; 
    }

    total = total - ma - me;

    media = total / 5.0;

    return final = media * D;
}

int main() {
    printf("%.1f\n", MediaSalto());

    return 0;
}
