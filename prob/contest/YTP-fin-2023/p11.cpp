#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef DEBUG 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll v(char i) {
    if ('a' <= i && i <= 'z') return i - 'a';
    if ('A' <= i && i <= 'Z') return 26 + i - 'A';
    if ('0' <= i && i <= '9') return 52 + i - '0';
    if (i == '_') return 62;
    if (i == '?') return 63;
    return -1;
}

void solve() {
    string s; int n, k;
    cin >> s >> k;
    n = s.size();
    int ml = 1;
    string ss = s + s;
    vector<int> cnt(65);
    vector<int> good;
    for (int l = 0, r = 0; l < n; l++) {
        while (cnt[v(ss[r])] <= k) {
            cnt[v(ss[r])] ++;
            r++;
            if (r > l + n) break;
        
        }
        if (r - l > ml) {
            ml = r - l;
            good.clear();
        }
        if (r - l == ml) good.pb(l);
    }
    debug(ml);
    ll ms = 0;
    for (int i = 0; i < ml; ++i) {
        ms *= ml;
        ms += v(s[i]);
    }
    pair<int, 
}
signed main(){_
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
