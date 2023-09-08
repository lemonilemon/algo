#include <stdio.h>
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int r = 1, c = 1;
    while(k) {
        if(k > (n - r + 1) + (m - c + 1) - 1) {
            k -= n + m - r - c + 1;
            ++r, ++c;
            continue;
        }
        if(k <= m - c + 1) {
            printf("%d %d", r, c + k - 1);
            break;
        }
        k -= m - c + 1;
        printf("%d %d", r + k, c);
        break;
    }
}
