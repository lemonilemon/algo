#include <stdio.h>
int main() {
    int s, f, t;
    int a, b, c;
    scanf("%d%d%d", &s, &f, &t);
    c = s - t;
    b = (f >> 1) - t - (c << 2);
    a = s - b - c;
    printf("%d\n%d\n%d\n", a, b, c);
}
