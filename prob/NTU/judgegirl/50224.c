#include <stdio.h>
int maxcmp(int a, int b) {
    int sum_a = 0, sum_b = 0;
    int cnt_a = 0, cnt_b = 0;
    int tmp = a;
    while(tmp) {
        sum_a += tmp % 10;
        ++cnt_a;
        tmp /= 10;
    }
    tmp = b;
    while(tmp) {
        sum_b += tmp % 10;
        ++cnt_b;
        tmp /= 10;
    }
    if(sum_a != sum_b) return sum_a > sum_b? a : b;
    if(cnt_a != cnt_b) return cnt_a > cnt_b? b : a;
    return a > b? a : b;
}
int main() {
    int mx = 0;
    int x;
    while(scanf("%d", &x) != EOF) {
        mx = maxcmp(mx, x); 
    }
    printf("%d", mx);
}
