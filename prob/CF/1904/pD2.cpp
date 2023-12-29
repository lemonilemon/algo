/* 
 * Created : 2023-12-09 17:09:15 lemonilemon
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
int a[MAXN], b[MAXN];
struct DSU {
    int rt[MAXN], rk[MAXN], l[MAXN], mxa[MAXN], mnb[MAXN], r[MAXN];
    int sz;
    DSU(int _sz): sz(_sz) {
        for(int i = 1; i <= sz; ++i) {
            rt[i] = i;
            rk[i] = 1;
            mxa[i] = a[i];
            mnb[i] = b[i];
            l[i] = i;
            r[i] = i;
        }
    }
    int findroot(int k) {
        return k == rt[k]? k : rt[k] = findroot(rt[k]);
    }
    bool setunion(int k1, int k2) {
        int r1 = findroot(k1), r2 = findroot(k2);
        if(r1 == r2) return false; 
        if(rk[r1] > rk[r2]) {
            rt[r2] = r1;
            rk[r1] += rk[r2];
            l[r1] = min(l[r1], l[r2]);
            r[r1] = max(r[r1], r[r2]);
            mxa[r1] = max(mxa[r1], mxa[r2]);
            mnb[r1] = min(mnb[r1], mnb[r2]);
        } else {
            rt[r1] = r2;
            rk[r2] += rk[r1];
            l[r2] = min(l[r1], l[r2]);
            r[r2] = max(r[r1], r[r2]);
            mxa[r2] = max(mxa[r1], mxa[r2]);
            mnb[r2] = min(mnb[r1], mnb[r2]);
        }

        return true;
    }
};
vector<int> apos[MAXN], bpos[MAXN];
bool color[MAXN];
// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        apos[i].clear();
        bpos[i].clear();
        color[i] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        apos[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
        bpos[b[i]].push_back(i);
    }
    for(int i = 1; i <= n; ++i) {
        if(a[i] > b[i]) {
            cout << "NO\n";
            return;
        } else if(a[i] == b[i]) {
            color[i] = 1;
        }
    }
    DSU dsu(n);
    for(int i = 1; i <= n; ++i) {
        for(auto p : apos[i]) {
            int cur = dsu.findroot(p);
            while(dsu.l[cur] > 1) {
                int nxtl = dsu.findroot(dsu.l[cur] - 1);
                if(dsu.mxa[nxtl] <= i && dsu.mnb[nxtl] >= i) {
                    // debug(nxtl, cur, dsu.l[nxtl], dsu.l[cur]);
                    dsu.setunion(nxtl, cur);
                    cur = dsu.findroot(cur);
                } else break;
            }
            while(dsu.r[cur] < n) {
                int nxtr = dsu.findroot(dsu.r[cur] + 1);
                if(dsu.mxa[nxtr] <= i && dsu.mnb[nxtr] >= i) {
                    dsu.setunion(nxtr, cur);
                    cur = dsu.findroot(cur);
                } else break;
            }
        }
        for(auto p : bpos[i]) {
            int cur = dsu.findroot(p);
            if(dsu.mxa[cur] != i) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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

