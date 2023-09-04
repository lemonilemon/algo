#include <stdio.h>
#include <stdlib.h>
long long int sqr(long long int a) {
    return a * a;
}
int main() {
    int w, a, b, c, d, e;
    scanf("%d%d%d%d%d%d", &w, &a, &b, &c, &d, &e);
    long long int length = a + b + c + d + e + 2;
    if(b) length += d + e;
    else length += abs(d - e);
    printf("%lld\n", sqr(w) + sqr(length));
}
