/* 
 * Created : 2023-10-07 18:16:53 lemonilemon
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


void setIO(string s = ""){
    if(s.size()) {
        freopen((s+"in.txt").c_str(),"r",stdin);
        freopen((s+"out.txt").c_str(),"w",stdout);
    }
}
const int MAXA = 1e6 + 5;
bool isprime[MAXA];
vector<int> primes;
void init() {
    for(int i = 2; i < MAXA; ++i) {
        isprime[i] = 1;
    }
    for(int i = 2; i < MAXA; ++i) {
        if(isprime[i]) primes.push_back(i);
        for(auto p : primes) {
            if(1ll * i * p >= MAXA) break;
            isprime[i * p] = 0;
            if(i % p == 0) break;
        }
    }
}
// solution
void solve() {
    int a;
    cin >> a;
    ll sum = 0;
    vector<int> ans;
    for(auto p : primes) {
        while(p <= a) {
            if(a % p) break;
            a /= p;
            ans.push_back(p);
            sum += p;
        }
    }
    if(a > 1 || sum > 41) {
        cout << "-1\n";
        return;
    }
    while(sum < 41) {
        ans.push_back(1);
        ++sum;
    }
    cout << ans.size();
    for(auto k : ans) {
        cout << ' ' << k;
    }
    cout << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    setIO("pB1");
    init();
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}

