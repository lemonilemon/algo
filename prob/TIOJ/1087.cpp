#include <bits/stdc++.h>
#include "lib1087.h"
using namespace std;
int cnt[4];
bool win[11][16][21];
pair<int, int> from[11][16][21];
int main() {
    for(int i = 0; i <= 10; ++i) {
        for(int j = 0; j <= 15; ++j) {
            for(int k = 0; k <= 20; ++k) {
                if(i || j || k) {
                   bool flag = 0;
                   for(int l = 1; l <= i; ++l) {
                       if(!win[i - l][j][k]) {
                           win[i][j][k] = 1;
                           from[i][j][k] = make_pair(1, l);
                       }
                   }
                   for(int l = 1; l <= j; ++l) {
                       if(!win[i][j - l][k]) {
                           win[i][j][k] = 1;
                           from[i][j][k] = make_pair(2, l);
                       }
                   }
                   for(int l = 1; l <= k; ++l) {
                       if(!win[i][j][k - l]) {
                           win[i][j][k] = 1;
                           from[i][j][k] = make_pair(3, l);
                       }
                       win[i][j][k] |= !win[i][j][k - l];
                   }
                } else win[i][j][k] = 1;
            }
        }
    }
    cnt[1] = 10, cnt[2] = 15, cnt[3] = 20;
    Initialize();
    while(cnt[1] || cnt[2] || cnt[3]) {
        int cp, ct;
        auto [pile, take] = from[cnt[1]][cnt[2]][cnt[3]]; 
        Take_Stone(pile, take, &cp, &ct);
        cnt[pile] -= take;
        cnt[cp] -= ct;
    }
    return 0;
}
