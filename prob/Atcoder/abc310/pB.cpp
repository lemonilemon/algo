#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int P[MAXN];
set<int> F[MAXN];
void solve() {
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
       cin >> P[i]; 
       int c;
       cin >> c;
       for(int j = 0; j < c; ++j) {
           int f;
           cin >> f;
           F[i].insert(f);
       }
       for(int j = 0; j < i; ++j) {
            if(P[i] > P[j]) {
                bool flag = 1;
                for(auto f : F[i]) {
                    if(!F[j].count(f)) {
                        flag = 0;
                        break;
                    } 
                }
                if(flag) {
                    cout << "Yes\n";
                    return;
                }
            } else if(P[i] < P[j]) {
                bool flag = 1;
                for(auto f : F[j]) {
                    if(!F[i].count(f)) {
                        flag = 0;
                        break;
                    } 
                }
                if(flag) {
                    cout << "Yes\n";
                    return;
                }
            } else {
                bool flag = 1;
                for(auto f : F[j]) {
                    if(!F[i].count(f)) {
                        flag = 0;
                        break;
                    } 
                }
                if(flag && F[i].size() > F[j].size()) {
                    cout << "Yes\n";
                    return;
                }
                flag = 1;
                for(auto f : F[i]) {
                    if(!F[j].count(f)) {
                        flag = 0;
                        break;
                    } 
                }
                if(flag && F[j].size() > F[i].size()) {
                    cout << "Yes\n";
                    return;
                }
            }
       }
    }
    cout << "No\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
} 
