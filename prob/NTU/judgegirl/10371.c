#include <stdio.h>
// #include "dividePolynomial.h"
 
#define MAX 2000 + 1

void dividePolynomial(int f[], int g[]) {
    int n = f[0], m = g[0];
    int tmp[MAX];
    f[0] = f[n + 1];
    for(int i = 0; i <= n; ++i) {
        tmp[i] = f[n - i + 1];
    }
    for(int i = 0; i <= n; ++i) {
        f[i] = tmp[i];
    }
    for(int i = 0; i <= m; ++i) {
        tmp[i] = g[m - i + 1];
    }
    for(int i = 0; i <= m; ++i) {
        g[i] = tmp[i];
    }
    int q[MAX] = {0}, r[MAX] = {0};
    int dis = n - m;
    while(n >= m) {
        int d = n - m;
        q[d] = f[n] / g[m];
        // printf("> %d %d\n", d, q[d]);
        for(int i = 0; i <= m; ++i) {
            f[d + i] -= q[d] * g[i];
        }
        while(n >= 0 && !(f[n])) --n;
    }
    g[0] = n;
    (g[0] < 0) && (g[0] = 0);
    for(int i = 0; i <= g[0]; ++i) {
        g[i + 1] = f[g[0] - i];
    }
    /* printf(">");
    for(int i = 0; i <= dis; ++i) {
        printf(" %d", q[i]);
    }
    printf("\n"); */
    f[0] = dis;
    (f[0] < 0) && (f[0] = 0);
    for(int i = 0; i <= f[0]; ++i) {
        f[i + 1] = q[f[0] - i];
    }
}
 
void readPolynomial(int p[]) {
    scanf("%d", &p[0]);
    for (int i = 1; i<=p[0]+1; i++)
        scanf("%d", &p[i]);
}
 
void printPolynomial(int p[]) {
    for (int i = 0; i<=p[0]; i++)
        printf("%d ", p[i]);
    printf("%d", p[p[0]+1]);
}
 
int main() {
    int n, f[MAX], g[MAX];
    scanf("%d", &n);
    while (n--) {
        readPolynomial(f);
        readPolynomial(g);
 
        dividePolynomial(f, g);
 
        printPolynomial(f);
        printf("\n");
        printPolynomial(g);
        if (n) printf("\n");
    }
    return 0;
}
