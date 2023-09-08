#include <stdio.h>
int gcd(int a, int b) {
    if(b > a) return gcd(b, a);
    if(!b) return a;
    return gcd(b, a % b);
}
int max(int a, int b) {
    return a > b? a : b;
}
int main() {
    int x;
    while(scanf("%d", &x) != EOF) {
        int mx = x;
        long long int lcm = x;
        for(int i = 1; i < 4; ++i) {
            scanf("%d", &x);
            lcm *= x / gcd(lcm, x);
            mx = max(mx, x);
        } 
        printf("%lld\n", lcm / mx);
    }
}
