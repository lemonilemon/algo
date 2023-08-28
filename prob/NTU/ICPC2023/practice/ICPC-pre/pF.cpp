#include <bits/stdc++.h>
using namespace std;
bool check[30];
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > s;
    int mxlg = 0;
    bool nonzero = 0;
    for(int i = 0; i < 30; ++i) {
        check[i] = 0;
    }
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if(!a) {
            nonzero = 1;
            continue;
        }
        mxlg = max(mxlg, __lg(a));
        bool flag = 0; // last is zero
        int l = 0;
        for(int j = 0; j <= __lg(a); ++j) {
            if(a & (1 << j)) {
                check[j] = 1;
                if(flag) {
                    s.push_back(make_pair(l, j - 1)); 
                    flag = 0;
                }
            } else if(!flag) {
                l = j;
                flag = 1;
            }
        }
        if(flag) s.push_back(make_pair(l, __lg(a)));
    }
    sort(s.begin(), s.end());
    int curr = -1, mxr = -1, cnt = 0;
    auto ptr = s.begin();
    for(int i = 0; i <= mxlg; ++i) {
        if(curr >= i) continue;
        while(ptr != s.end() && ptr -> first <= i) {
            mxr = max(mxr, ptr -> second); 
            ++ptr;
        }
        if(!check[i]) {
            curr = mxr;     
            ++cnt;
        } 
    }
    cout << (1 << (mxlg + 1)) - 1 << ' ' << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        solve();
    }
}
