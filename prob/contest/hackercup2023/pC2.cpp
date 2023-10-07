/* 
 * Created : 2023-10-07 18:34:13 lemonilemon
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
const int MAXN = 4e6 + 5;
bool s[MAXN];

void setIO(string s = ""){
    if(s.size()) {
        freopen((s+"in.txt").c_str(),"r",stdin);
        freopen((s+"out.txt").c_str(),"w",stdout);
    }
}
// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        char ch;
        cin >> ch;
        s[i] = ch == '1';
    }
    set<int> op;
    for(int i = 1; i <= n; ++i) {
        if(s[i]) {
            op.insert(i);
            for(int j = i; j <= n; j += i) {
                s[j] = !s[j];
            }
        }
    }
    // safe();
    int q;
    cin >> q;
    ll ans = 0;
    for(int i = 0; i < q; ++i) {
        int l;
        cin >> l;
        if(op.count(l)) op.erase(l);
        else op.insert(l);
        ans += op.size();
    }
    cout << ans << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    setIO("pC2");
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}

