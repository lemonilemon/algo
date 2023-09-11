#include <stdio.h>
int sqr(int x) {
    return x * x;
}
int main() {
    int xa, ya, ra, xb, yb, rb;
    scanf("%d%d%d%d%d%d", &xa, &ya, &ra, &xb, &yb, &rb);
    int x, y;
    while(scanf("%d%d", &x, &y) != EOF) {
        int adis2 = sqr(xa - x) + sqr(ya - y), bdis2 = sqr(xb - x) + sqr(yb - y);
        if(adis2 > sqr(ra) && bdis2 > sqr(rb)) {
            puts("Out");
            continue;
        }
        if(adis2 < sqr(ra) || bdis2 < sqr(rb)) {
            puts("In");
            continue;
        }
        puts("On");
    }
}
