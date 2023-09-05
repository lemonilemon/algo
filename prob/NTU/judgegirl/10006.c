#include <stdio.h>
int main() {
    long long int sum = 0;
    int x;
    while(scanf("%d", &x) != EOF) {
        sum += x;
    }
    printf("%lld\n", sum);
}
