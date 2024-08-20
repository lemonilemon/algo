/* 
 * Created : 2024-08-18 15:48:48 lemonilemon
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
const int maxn = 2e5 + 5;
int sa[maxn], tmp[2][maxn], c[maxn];
void get_sa(const string &s) { // m: char set
    int *x = tmp[0], *y = tmp[1], m = 256, n = s.size();
    for(int i = 0; i < m; ++i) c[i] = 0;
    for(int i = 0; i < n; ++i) c[x[i] = s[i]]++;
    for(int i = 1; i < m; ++i) c[i] += c[i - 1];
    for(int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
    for(int k = 1; k < n; k <<= 1) {
        for(int i = 0; i < m; ++i) c[i] = 0;
        for(int i = 0; i < n; ++i) c[x[i]]++;
        for(int i = 1; i < m; ++i) c[i] += c[i - 1];
        int p = 0;
        for(int i = n - k; i < n; ++i) y[p++] = i;
        for(int i = 0; i < n; ++i) 
            if(sa[i] >= k) y[p++] = sa[i] - k;
        for(int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
        y[sa[0]] = p = 0;
        for(int i = 1; i < n; ++i) {
            int a = sa[i], b = sa[i - 1];
            if(x[a] == x[b] && a + k < n && b + k < n && x[a + k] == x[b + k]) { }
            else p++;
            y[sa[i]] = p;
        }
        if(n == p + 1) 
            break;
        swap(x, y);
        m = p + 1;
    }
} // sa[i]: index which ranks i
int rk[maxn], lcp[maxn]; // lcp[i] : lcp with i - 1
void get_lcp(const string& s) {
    int n = s.size(), val = 0;
    for(int i = 0; i < n; ++i) rk[sa[i]] = i;
    for(int i = 0; i < n; ++i) {
        if(rk[i] == 0) continue;
        if(val) val--;
        int p = sa[rk[i] - 1];
        while(i + val < n && p + val < n && s[i + val] == s[p + val]) val++;
        lcp[rk[i]] = val;
    }
}

const int INF = 1e9 + 7;
int a[maxn];
int mnl[maxn], mnr[maxn];
int dp[maxn];
int seg[maxn << 2];
void pull(int v) {
    seg[v] = max(seg[v << 1], seg[v << 1 | 1]);
}
void build(int v, int l, int r) {
    if(l == r) {
        seg[v] = -INF;
        return;
    }
    int mid = (l + r) >> 1;
    build(v << 1, l , mid);
    build(v << 1 | 1, mid + 1, r);
    pull(v);
}
void modify(int val, int idx, int v, int l, int r) {
    if(l == r) {
        seg[v] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(idx <= mid) modify(val, idx, v << 1, l, mid);
    else modify(val, idx, v << 1 | 1, mid + 1, r);
    pull(v);
}
int query(int ql, int qr, int v, int l, int r) {
    if(ql == l && qr == r) {
        return seg[v];
    }
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(ql, qr, v << 1, l, mid);
    if(ql > mid) return query(ql, qr, v << 1 | 1, mid + 1, r);
    return max(query(ql, mid, v << 1, l, mid), query(mid + 1, qr, v << 1 | 1, mid + 1, r));  
}

int n;
void dq(int l, int r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    dq(l, mid);
    // cerr << l << ' ' << r << ":\n";
    for(int i = r; i >= l; --i) {
        if(i > mid) mnr[i] = INF;
        else mnr[i] = min(mnr[i + 1], lcp[i]);
    }
    for(int i = l; i <= r; ++i) {
        if(i <= mid) mnl[i] = INF;
        else mnl[i] = min(mnl[i - 1], lcp[i]);
    }
    /*
    for(int i = l; i <= r; ++i) {
        cerr << mnl[i] << ' ';
    }
    cerr << '\n';
    for(int i = l; i <= r; ++i) {
        cerr << mnr[i] << ' ';
    }
    cerr << '\n';
    */
    /*for(int i = r; i >= l; --i) {
        if(rk[a[i]] > mid) mnr[rk[a[i]]] = INF;
        else mnr[rk[a[i]]] = min(mnr[rk[a[i]] + 1], lcp[rk[a[i]]]);
    }
    for(int i = l; i <= r; ++i) {
        if(rk[a[i]] <= mid) mnl[rk[a[i]]] = INF;
        else mnl[rk[a[i]]] = min(mnl[rk[a[i]] - 1], lcp[rk[a[i]]]);
    }*/

    // compute dp
    sort(a + l, a + mid + 1, [&](int x, int y) {
        return mnr[rk[x] + 1] < mnr[rk[y] + 1];
    });
    sort(a + mid + 1, a + r + 1, [&](int x, int y) {
        return mnl[rk[x]] < mnl[rk[y]];
    });
    vector<int> mods;
    for(int curr = mid + 1, curl = l; curr <= r; ++curr) {
        while(curl <= mid && mnr[rk[a[curl]] + 1] <= mnl[rk[a[curr]]]) {
            int i = a[curl], j = a[curr];
            int idx = i + mnr[rk[i] + 1] + 1;
            if(idx <= n) {
                modify(dp[i], idx, 1, 1, n);
                mods.push_back(idx);
            }
            ++curl;
        }
        int j = a[curr];
        int search = a[curr];
        if(search > 0) dp[j] = max(dp[j], query(1, search, 1, 1, n) + 1), debug(dp[j]);
    }
    // rollback
    for(auto x : mods) {
        modify(-INF, x, 1, 1, n);
    }
    mods.clear();

    for(int curr = r, curl = mid; curr > mid; --curr) {
        while(curl >= l && mnr[rk[a[curl]] + 1] >= mnl[rk[a[curr]]]) {
            int i = a[curl], j = a[curr];
            int idx = i + 1;
            if(idx <= n) {
                modify(dp[i], idx, 1, 1, n);
                mods.push_back(idx);
            }
            --curl;
        }
        int j = a[curr];
        int search = j - mnl[rk[j]];
        if(search > 0) dp[j] = max(dp[j], query(1, search, 1, 1, n) + 1), debug(dp[j]);
    }
    // rollback
    for(auto x : mods) {
        modify(-INF, x, 1, 1, n);
    }
    mods.clear();


    // re-sort
    sort(a + l, a + r + 1, [&](int x, int y) {
        return rk[x] < rk[y];
    });
    dq(mid + 1, r);
}

// solution
void solve() {
    string s;
    cin >> s;
    n = s.size(); 
    build(1, 1, n);
    get_sa(s);
    get_lcp(s);
    for(int i = 0; i < n; ++i) {
        dp[i] = -INF;
        a[i] = i;
    }
    dp[0] = 1;
    sort(a, a + n, [&](int x, int y) {
        return rk[x] < rk[y];
    });
    dq(0, n - 1);
    int mx = 1;
    for(int i = 0; i < n; ++i) {
        // cerr << dp[i] << ' ';
        mx = max(dp[i], mx);
    }
    // cerr << '\n';
    cout << mx << '\n';
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
