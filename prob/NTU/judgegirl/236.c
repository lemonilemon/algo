#include <stdio.h>
int gcd(int a, int b) {
    if(b > a) return gcd(b, a);
    if(!b) return a;
    return gcd(b, a % b);
}
int main() {
    long long int lcm = 1;
    long long int n;
    while(scanf("%lld", &n) != EOF) {
        lcm = lcm * n / gcd(n, lcm);
    }
    printf("%lld", lcm);
}
