#include <stdio.h>

int main() {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    long long x1, x2, x3;

    for (x1 = 0; x1 <= a / 150; x1++) {
        for (x2 = 0; x2 <= (a - 150 * x1) / 50; x2++) {
            if ((a - (150 * x1 + 50 * x2)) % 50 == 0) {
                x3 = (a - (150 * x1 + 50 * x2)) / 50;

                if (x3 >= 0) {
                    if (750 * x1 + 750 * x2 + 500 * x3 == b && 600 * x1 + 700 * x2 + 950 * x3 == c) {
                        printf("%lld %lld %lld\n", x1, x2, x3);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
