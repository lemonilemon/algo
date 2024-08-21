/* 
 * Created : 2024-08-20 23:40:20 lemonilemon
 * Time complexity : O()
 * Space complexity : O()
 * Description : 
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long int;


// #define LOCAL

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
const int MAXN = 3e5 + 5;
const int INF = 1e9 + 7;

int a[MAXN];
vector<int> pos[MAXN];
bool vis[MAXN];
pair<int, int> mxseg[MAXN << 2], mnseg[MAXN << 2];
void pull(int v) {
    mxseg[v] = max(mxseg[v << 1], mxseg[v << 1 | 1]);
    mnseg[v] = min(mnseg[v << 1], mnseg[v << 1 | 1]);
}
void build(int v, int l, int r) {
    if(l == r) {
        mxseg[v] = { a[l], -l };
        mnseg[v] = { a[l], l };
        return;
    }
    int mid = (l + r) >> 1;
    build(v << 1, l, mid);
    build(v << 1 | 1, mid + 1, r);
    pull(v);
}
void clean(int idx, int v, int l, int r) {
    if(l == r) {
        mxseg[v] = { -INF, -l }; 
        mnseg[v] = { INF, l };
        return;
    }
    int mid = (l + r) >> 1;
    if(idx <= mid) clean(idx, v << 1, l, mid);
    else clean(idx, v << 1 | 1, mid + 1, r);
    pull(v);
}
pair<int, int> mxquery(int ql, int qr, int v, int l, int r) {
    if(ql == l && qr == r) return mxseg[v];
    int mid = (l + r) >> 1;
    if(qr <= mid) return mxquery(ql, qr, v << 1, l, mid);
    if(ql > mid) return mxquery(ql, qr, v << 1 | 1, mid + 1, r);
    return max(mxquery(ql, mid, v << 1, l, mid), mxquery(mid + 1, qr, v << 1 | 1, mid + 1, r));
}

pair<int, int> mnquery(int ql, int qr, int v, int l, int r) {
    if(ql == l && qr == r) return mnseg[v];
    int mid = (l + r) >> 1;
    if(qr <= mid) return mnquery(ql, qr, v << 1, l, mid);
    if(ql > mid) return mnquery(ql, qr, v << 1 | 1, mid + 1, r);
    return min(mnquery(ql, mid, v << 1, l, mid), mnquery(mid + 1, qr, v << 1 | 1, mid + 1, r));
}


// solution
void solve() {
    int n; 
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        vis[i] = 0;
        pos[i].clear();
    }
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(pos[a[i]].empty()) ++cnt;
        pos[a[i]].push_back(i);
    }
    build(1, 1, n);
    vector<int> lasts;
    for(int i = 1; i <= n; ++i) {
        if(!pos[i].empty()) {
            lasts.push_back(pos[i].back());
            // debug(pos[i].back());
        }
    }
    vector<int> ans;
    int l = 1;
    sort(lasts.begin(), lasts.end());
    for(auto r : lasts) {
        if(vis[a[r]]) continue;
        while(l <= r) {
            auto [val, idx] = (ans.size() & 1) ? mnquery(l, r, 1, 1, n) : mxquery(l, r, 1, 1, n);
            idx = abs(idx);
            debug(val, idx, l, r);
            ans.push_back(val);
            vis[val] = 1;
            for(auto x : pos[val]) {
                clean(x, 1, 1, n);
            }
            l = idx + 1;
            if(val == a[r]) break;
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
            
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

