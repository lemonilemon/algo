#include <stdio.h>
#include <assert.h>
long long int sqr(int x) {
    return 1ll * x * x;
}
int main() {
    int ax, ay, bx, by, cx, cy, dx, dy;
    while(scanf("%d%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy) != EOF) {
        long long int adis = sqr(ax - dx) + sqr(ay - dy);
        long long int bdis = sqr(bx - dx) + sqr(by - dy); 
        long long int cdis = sqr(cx - dx) + sqr(cy - dy);
        assert(adis <= 2147483647  && bdis <= 2147483647 && cdis <= 2147483647);
        if(adis == bdis && adis == cdis) {
            printf("0 ");
            continue;
        }
        if(adis < bdis && adis < cdis) {
            printf("1 ");
            continue;
        }
        if(bdis < adis && bdis < cdis) {
            printf("2 ");
            continue;
        }
        if(cdis < adis && cdis < bdis) {
            printf("3 ");
            continue;
        }
        if(adis == bdis && adis < cdis) {
            printf("4 ");
            continue;
        }
        if(adis == cdis && adis < bdis) {
            printf("5 ");
            continue;
        }
        if(bdis == cdis && bdis < adis) {
            printf("6 ");
            continue;
        }
    }
    printf("\n");
}
