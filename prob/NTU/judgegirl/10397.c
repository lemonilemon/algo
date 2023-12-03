#include <stdint.h>
#include <stdbool.h>
#define ARRAYSIZE 1000
 
typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;

int numZeroBits(GiantUnsignedInt *giantNum) {
    int ans = 0;
    bool last = 1;
    int cnt = 0;
    for(int i = 0; i < giantNum->n; ++i) {
        for(int j = 63; j >= 0; --j) {
            bool cur = (giantNum->array[i] >> j) & 1;
            if(!cur) {
                ++cnt;
                ans = cnt > ans? cnt : ans;
            } else cnt = 0;
            last = cur;
        }
    }
    return ans;
}

#include <stdio.h>
// #include "numZeroBits.h"
 
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        GiantUnsignedInt giantNum;
        for (int i = 0; i<n; i++)
            scanf("%llu", &giantNum.array[i]);
        giantNum.n = n;
        printf("%d\n", numZeroBits(&giantNum));
    }
    return 0;
}
