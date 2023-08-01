#include <bits/stdc++.h>
#include "lib1088.h"
using namespace std;
int cnt[4];
int main() {
    Initialize(&cnt[1], &cnt[2], &cnt[3]);
    int sg = cnt[1] ^ cnt[2] ^ cnt[3];
    while(cnt[1] || cnt[2] || cnt[3]) {
        int cp, cn;
        bool flag = 0;
        for(int i = 1; i <= 3; ++i) {
            if(cnt[i] >= (sg ^ cnt[i])) {
                int dis = cnt[i] - (sg ^ cnt[i]);
                Take_Stone(i, dis, &cp, &cn);
                cnt[i] -= dis;
                cnt[cp] -= cn;
                flag = 1;
                break;
            }
        }
        sg = cnt[1] ^ cnt[2] ^ cnt[3]; 
    }
    return 0;
}
