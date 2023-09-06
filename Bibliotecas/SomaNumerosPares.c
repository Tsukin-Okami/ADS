#include <stdio.h>
#include <stdlib.h>

int main() {
    char st[100];
    fgets(st, sizeof(st), stdin);
    int max_n = atoi(st);

    int tab[max_n];
    for (int n = 0; n < max_n; n++) {
        tab[n] = (n + 1) * 2;
    }

    int sum = 0;
    for (int n = 0; n < max_n; n++) {
        sum += tab[n];
    }

    printf("%d\n", sum);

    return 0;
}
