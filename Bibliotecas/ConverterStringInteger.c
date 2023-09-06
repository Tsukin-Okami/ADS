#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    int n1 = atoi(input); // atoi converte input em int
    char n2[100];
    sprintf(n2, "%s", input); // converte input em string
    printf("%d %s\n", n1, n2);
    return 0;
}
