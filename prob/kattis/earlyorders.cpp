/* 
 * Created : 2023-10-20 10:39:29 lemonilemon
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
int x[MAXN];
int cnt[MAXN];
bool color[MAXN];
vector<int> ans;
struct Node {
    int mn, mnid;
    Node() {};
    Node(int k, int id): mn(k), mnid(id) {};
    Node(const Node& that): mn(that.mn), mnid(that.mnid) {};
    Node operator + (const Node& that) const {
        Node ret;
        if(mn < that.mn) {
            ret.mn = mn;
            ret.mnid = mnid;
        } else if(mn > that.mn) {
            ret.mn = that.mn;
            ret.mnid = that.mnid;
        } else {
            ret.mn = mn;
            ret.mnid = min(mnid, that.mnid);
        }
        return ret;
    }
} seg[MAXN << 2];
int n, k;
void pull(int v) {
    seg[v] = seg[v << 1] + seg[v << 1 | 1];
}
void build(int l = 1, int r = n, int v = 1) {
    if(l == r) {
        seg[v] = Node(x[l], l);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid);
    build(mid + 1, r);
    pull(v);
}
Node query(int ql, int qr, int l = 1, int r = n, int v = 1) {
    if(ql == l && qr == r) return seg[v];
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(ql, qr, l, mid, v << 1);
    if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
    return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, qr, v << 1 | 1); 
}
// solution
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
        ++cnt[x[i]];
    }
    deque<int> dq;
    for(int i = 1; i <= n; ++i) { 
        --cnt[x[i]];
        if(color[x[i]]) continue;
        while(!dq.empty() && x[i] < dq.back()) {
            int k = dq.back();
            if(!cnt[k]) {
                while(!dq.empty()) {
                    int cur = dq.front();
                    dq.pop_front();
                    ans.push_back(cur);
                }
                break;
            }
            color[k] = 0;
            dq.pop_back();
        }
        dq.push_back(x[i]);
        color[x[i]] = 1;
    }
    while(!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        ans.push_back(cur);
    }
    for(int i = 0; i < k; ++i) {
        cout << ans[i] << " \n"[i == k - 1];
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

