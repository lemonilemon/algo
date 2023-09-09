#include <stdio.h>
int main() {
    int cur, last, cnt = 1;
    scanf("%d", &last);
    while(scanf("%d", &cur) != EOF) {
        if((cur < 0 && last < 0) || (cur > 0 && last > 0)) ++cnt;
        else {
            if(last < 0) printf("-");
            printf("%d ", cnt);
            cnt = 1;
        }
        last = cur;
    }
    if(last < 0) printf("-");
    printf("%d\n", cnt);
}
