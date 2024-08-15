/* 
 * Created : 2024-08-15 22:59:11 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description : 
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;


#define LOCAL

// debug template
#ifdef LOCAL
#define debug(args...) _debug(#args, args)
#define expand(arr, l, r) _expand(#arr, l, r, begin(arr) + l, begin(arr) + r)
#define safe()  cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__ << " is safe.\e[0m\n";
template <typename ...T> void _debug(const char *s, T ...args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
        (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to " << s << '[' << nr << "].\n---\n[";
    for(T it = l; it != r + 1; ++it) {
       cerr << *it << (it != r? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0) 
#define safe() ((void)0) 
#define expand(...) ((void)0)
#endif

// constants
const int MAXN = 2e5 + 5;
int a[MAXN];
bool B[MAXN], Y[MAXN], G[MAXN], R[MAXN];

// solution
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> idx[6]; // BG, BR, BY, GR, GY, RY
    for(int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        B[i] = Y[i] = G[i] = R[i] = 0;
        for(auto c : s) {
            if(c == 'B') B[i] = 1;
            else if(c == 'Y') Y[i] = 1;
            else if(c == 'G') G[i] = 1;
            else if(c == 'R') R[i] = 1;
        }
        if(s == "BG") a[i] = 0;
        else if(s == "BR") a[i] = 1;
        else if(s == "BY") a[i] = 2;
        else if(s == "GR") a[i] = 3;
        else if(s == "GY") a[i] = 4;
        else if(s == "RY") a[i] = 5;
        idx[a[i]].push_back(i);
    }

    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        if(l == r) {
            cout << "0\n";
            continue;
        }
        if(l > r) swap(l, r);
        if((B[l] && B[r]) || (Y[l] && Y[r]) || (G[l] && G[r]) || (R[l] && R[r])) {
            cout << r - l << '\n';
            continue;
        }
        bool flag = false;
        for(int j = 0; j < 6; ++j) {
            if(a[l] == j || a[r] == j) continue;
            auto p = upper_bound(idx[j].begin(), idx[j].end(), l);
            if(p != idx[j].end() && *p < r) {
                cout << r - l << '\n';
                flag = true;
                break;
            }
        }
        if(flag) continue;
        int mn = 1e9;
        for(int j = 0; j < 6; ++j) {
            if(a[l] == j || a[r] == j) continue;
            auto p1 = lower_bound(idx[j].begin(), idx[j].end(), l);
            if(p1 != idx[j].begin()) mn = min(mn, l - *prev(p1));
            auto p2 = upper_bound(idx[j].begin(), idx[j].end(), r);
            if(p2 != idx[j].end()) mn = min(mn, *p2 - r);
        }
        if(mn == 1e9) {
            cout << "-1\n";
            continue;
        }
        cout << r - l + mn * 2 << '\n';
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

