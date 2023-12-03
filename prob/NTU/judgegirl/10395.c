#include <stdint.h>
#include <stdbool.h>
#define ARRAYSIZE 1000
 
typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;
 
int numBitChanges(GiantUnsignedInt *giantNum) {
    int ans = 0;
    bool last = giantNum->array[giantNum->n - 1] & 1;
    for(int i = 0; i < giantNum->n; ++i) {
        for(int j = 63; j >= 0; --j) { 
            ans += last != ((giantNum->array[i] >> j) & 1);
            // printf("%d %d\n", (int)last, ans);
            last = (giantNum->array[i] >> j) & 1;
        }
    }
    return ans;
}

#include <stdio.h>
// #include "numBitChanges.h"
 
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        GiantUnsignedInt giantNum;
        for (int i = 0; i<n; i++)
            scanf("%llu", &giantNum.array[i]);
        giantNum.n = n;
        printf("%d\n", numBitChanges(&giantNum));
    }
    return 0;
}
