#include <stdio.h>
char *a[11]={"","one","two","three","four","five","six","seven","eight","nine"};
char *b[11]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
char *c[11]={"","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char *dec[8]={"","thousand","million","billion","trillion","quadrillion","quintillion"};
int f(unsigned long long n, int i) {
    (n / 1000) && f(n/1000, i + 1);
    int k = n % 1000;
    (k >= 100) && printf("%s hundred ", a[k / 100]);
    k %= 100;
    (k >= 20) && printf("%s-%s ", b[k / 10], a[k % 10]);
    ((k > 10) && (k < 20)) && printf("%s ", c[k % 10]);
    (k <= 10) && printf("%s ", a[k % 10]);
    printf("%s ", dec[i]);
    return 0;
}
int main() {
    unsigned long long int x;
    scanf("%llu", &x);
    f(x, 0);
    printf("\n");
}
