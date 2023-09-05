#include <stdio.h>

int main() {
    long long int a, b, c, d, e;
    scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e);
    long long int area = (a * c + b * c + a * b) << 1;
    area += d * (2 * a + 2 * b + 2 * c - 12 * e) * 4;
    printf("%lld\n", area);
    long long int v = a * b * c;
    long long int t[3];
    t[0] = a - 2 * e;
    t[1] = b - 2 * e;
    t[2] = c - 2 * e;
    for(int i = 0; i < 3; ++i) {
        for(int j = i + 1; j < 3; ++j) {
            v -= t[i] * t[j] * d * 2; 
        }
    }
    printf("%lld\n", v);
}
