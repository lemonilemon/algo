#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    double x[n];
    for(int i = 0; i < n; ++i) {
        scanf("%lf", &x[i]);
    }
    double sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += x[i];
    }
    double mean = sum / n;
    double dif2 = 0;
    for(int i = 0; i < n; ++i) {
        dif2 += (x[i] - mean) * (x[i] - mean);
    }
    double var = dif2 / n;
    printf("%lf\n%lf", mean, var);
}
