#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if(n <= 2) {
        printf("0\n");
        return 0;
    }
    int x1, y1;
    scanf("%d%d", &x1, &y1);
    int ans = 0;
    int lastx = x1, lasty = y1;
    for(int i = 2; i <= n; ++i) {
        int xi, yi;
        scanf("%d%d", &xi, &yi);
        ans += lastx * yi - lasty * xi;
        lastx = xi;
        lasty = yi;
    }
    ans += lastx * y1 - lasty * x1;
    printf("%d\n", ans);
}
