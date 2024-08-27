/* 
 * Created : 2024-08-28 00:37:41 lemonilemon
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
const int MAXW = 1e5;
int seg[MAXW << 3];
void insert(int x, int l, int r, int v) {
    if(x == seg[v]) return;
    if(l == r) {
        cout << "? " << x << ' ' << seg[v]  << ' ' << l << endl;
        string s;
        cin >> s;
        if(s == "FIRST") seg[v] = x;
        return;
    }
    int mid = (l + r) >> 1;
    cout << "? " << x << ' ' << seg[v] << ' ' << mid << endl;
    string s;
    cin >> s;
    if(s == "FIRST") swap(x, seg[v]);
    cout << "? " << x << ' ' << seg[v] << ' ' << l << endl;
    cin >> s;
    if(s == "FIRST") insert(x, l, mid, v << 1);
    else insert(x, mid + 1, r, v << 1 | 1);
}
int query(int w, int l, int r, int v) {
    if(l == r) return seg[v];
    int mx = seg[v];
    int mid = (l + r) >> 1;
    int res;
    if(w <= mid) res = query(w, l, mid, v << 1);
    else res = query(w, mid + 1, r, v << 1 | 1);
    if(res == seg[v]) return res;
    cout << "? " << res << ' ' << seg[v] << ' ' << w << endl;
    string s;
    cin >> s;
    if(s == "FIRST") return res;
    return seg[v];
}


// solution
void solve() {
    int n; 
    cin >> n;
    for(int i = 1; i < n; ++i) {
        insert(i, 1, MAXW, 1);
    }
    cout << '!' << endl;
    string q;
    int w;
    while(cin >> q) {
        if(q == "FINISH") break;
        cin >> w;
        int ans = query(w, 1, MAXW, 1);
        cout << "! " << ans << endl;
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

