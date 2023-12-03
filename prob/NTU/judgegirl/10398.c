#include <stdio.h>
#include <stdbool.h>
int cnt;
long long k;
int ccnt[26];
char c[10];
char ans[10];
int freq[10];
bool color[10];
bool permute(int u, long long cursum) {
    // printf("%lld %d\n", cursum, u);
    if(u == 10) {
        if(cursum != k) return 0;
        for(int i = 1; i < 10; ++i) {
            (i != 1) && printf(" ");
            printf("%c", ans[i]);
        }
        printf("\n");
        return 1;
    }
    for(int i = 0; i < 9; ++i) {
        if(color[i]) continue;
        long long sum = cursum + u * freq[i];
        ans[u] = c[i];
        color[i] = 1;
        if(permute(u + 1, sum)) return 1;
        color[i] = 0;
    }
    return 0;
}
int main() {
    scanf("%lld", &k);
    char ch;
    while(ch = getchar(), ch != EOF) {
        if(ch <= 'z' && ch >= 'a') {
            ++ccnt[ch - 'a'];
        }
    }
    for(int i = 0; i < 26; ++i) {
        if(ccnt[i]) {
            c[cnt] = 'a' + i;
            freq[cnt] = ccnt[i];
            ++cnt;
        }
    }
    permute(1, 0);
}
