#include <stdio.h>
// #include "dividePolynomial.h"
 
#define MAX 2000 + 1

void dividePolynomial(int f[], int g[]) {
    int n = f[0], m = g[0];
    int tmp[MAX];
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
    int q[MAX], r[MAX];   
    /* printf("> ");
    for(int i = 0; i <= n; ++i) {
        printf("%d ", f[i]);
    }
    printf("\n"); */
    while(n >= m) {
        int d = n - m;
        // printf("> %d\n", d);
        q[d] = f[n] / g[m];
        for(int i = 0; i <= m; ++i) {
            f[d + i] -= q[d] * g[i];
        }
        while(--n) {
            if(f[n]) break;
        }
        /* printf("> ");
        for(int i = 0; i <= n; ++i) {
            printf("%d ", f[i]);
        }
        printf("\n"); */
    }
    if(n < 0) n = 0;
    r[0] = n;
    for(int i = 0; i <= n; ++i) {
        r[i + 1] = f[n - i];
    } 
    for(int i = 0; i < MAX - 1; ++i) {
        f[i] = 0;
        if(q[i]) f[0] = i;
        g[i] = r[i];
    }
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
