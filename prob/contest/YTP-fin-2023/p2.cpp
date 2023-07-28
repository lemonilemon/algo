
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifndef EVAL
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct s {
    int id;
    int sz;
    int fa;
};
signed main(){_
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<s> v(n);
        for (int i = 0; i < n; ++i) {
            v[i].id = i + 1;
            cin >> v[i].sz;
        }
        sort(AI(v), [](s& a, s& b) {
                return a.sz > b.sz;
                });
        vector <int> arr;
        arr.pb(0);
        for (auto &i : v) {
            for (int j = 0; j < i.sz; j++){
                arr.pb(i.id);
            }
        }
        for (int i = 0; i < n; ++i) {
            v[i].fa = arr[i];
        }
        int k = 1; 
        int c = v[n-1].id;
        sort(AI(v), [](s &a, s &b) {
                return a.id < b.id;});
        while (c != 0) {
            k++;
            debug(c);
            c = v[c-1].fa;
        }
        cout << k -2<< endl;
        for (auto &i : v) cout << i.fa << " \n"[&i == &v.back()];
        
    }

    return 0;
}
