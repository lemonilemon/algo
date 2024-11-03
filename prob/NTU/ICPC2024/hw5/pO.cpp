/*
 * Created : 2024-11-03 20:57:25 lemonilemon
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
const int MAXN = 1005;
const int MAXA = 1e6 + 5;
ll f1[MAXN][MAXN], f2[MAXN][MAXN];
int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
vector<int> primes;
bool isprime[MAXA];
int mnp[MAXA];
ll p1[MAXA], p2[MAXA];
void init() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 2; i < MAXA; ++i) {
        isprime[i] = 1;
    }
    for(int i = 2; i < MAXA; ++i) {
        if(isprime[i]) {
            mnp[i] = i;
            p1[i] = rng();
            p2[i] = rng();
            primes.push_back(i);
        }
        for(auto p : primes) {
            if(1ll * i * p >= MAXA) break;
            isprime[i * p] = 0;
            mnp[i * p] = p;
        }
    }
}
bool check(int x, int y, int z) {
    set<int> s;
    while(x > 1) {
        if(!s.count(mnp[x])) s.insert(mnp[x]);
        else s.erase(mnp[x]);
        x /= mnp[x];
    }
    while(y > 1) {
        if(!s.count(mnp[y])) s.insert(mnp[y]);
        else s.erase(mnp[y]);
        y /= mnp[y];
    }
    while(z > 1) {
        if(!s.count(mnp[z])) s.insert(mnp[z]);
        else s.erase(mnp[z]);
        z /= mnp[z];
    }
    return s.empty();
}
int n;
bool vis[MAXN][MAXN];
void dfs(int x, int y) {
    vis[x][y] = 1;
    if(x < n) {
        if(!vis[x + 1][y]) {
            int tmp = a[x][y];
            f1[x + 1][y] = f1[x][y];
            f2[x + 1][y] = f2[x][y];
            while(tmp > 1) {
                f1[x + 1][y] ^= p1[mnp[tmp]];
                f2[x + 1][y] ^= p2[mnp[tmp]];
                tmp /= mnp[tmp];
            }
            dfs(x + 1, y);
        }
        if(!vis[x + 1][y + 1]) {
            int tmp = b[x][y];
            f1[x + 1][y + 1] = f1[x][y];
            f2[x + 1][y + 1] = f2[x][y];
            while(tmp > 1) {
                f1[x + 1][y + 1] ^= p1[mnp[tmp]];
                f2[x + 1][y + 1] ^= p2[mnp[tmp]];
                tmp /= mnp[tmp];
            }
            dfs(x + 1, y + 1);
        }
    }
    if(y < x) {
        if(!vis[x][y + 1]) {
            int tmp = c[x][y];
            f1[x][y + 1] = f1[x][y];
            f2[x][y + 1] = f2[x][y];
            while(tmp > 1) {
                f1[x][y + 1] ^= p1[mnp[tmp]];
                f2[x][y + 1] ^= p2[mnp[tmp]];
                tmp /= mnp[tmp];
            }
            dfs(x, y + 1);
        }
    }
}

// solution
void solve() {
    cin >> n;
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= i; ++j) {
            cin >> b[i][j];
        }
    }
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            cin >> c[i][j];
        }
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= i; ++j) {
            if(!check(a[i][j], b[i][j], c[i + 1][j])) {
                cout << 0 << '\n';
                return;
            }
        }
    }
    for(int i = 2; i < n; ++i) {
        for(int j = 1; j < i; ++j) {
            if(!check(c[i][j], b[i][j], a[i][j + 1])) {
                cout << 0 << '\n';
                return;
            }
        }
    }
    dfs(1, 1);
    map<pair<ll, ll>, int> mp;
    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            ans += mp[make_pair(f1[i][j], f2[i][j])]++;
        }
    }
    cout << ans << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    // cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
