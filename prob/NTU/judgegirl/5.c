#include <stdio.h>
int main() {
    int h, w, d;
    scanf("%d%d%d", &h, &w, &d);
    printf("%d\n%d", (h * w + w * d + h * d) << 1, h * w * d);
}
