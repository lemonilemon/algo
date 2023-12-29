/* 
 * Created : 2023-12-17 16:08:39 lemonilemon
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
multiset<ll> s1, s2;
ll sum1, sum2;
ll med;
void balance() {
    if(s1.size() > s2.size() + 1) {
        auto p = prev(s1.end());
        sum2 += *p;
        s2.insert(*p);
        sum1 -= *p;
        s1.erase(p);
    } else if(s2.size() > s1.size()) {
        auto p = s2.begin();
        sum1 += *p;
        s1.insert(*p);
        sum2 -= *p;
        s2.erase(p);
    }
    return;
}


// solution
void solve() {
    int Q;
    cin >> Q;
    for(int q = 0; q < Q; ++q) {
        string op;
        cin >> op;
        if(op == "kiwi") {
            int x;
            cin >> x;
            if(x <= med) {
                sum1 += x;  
                s1.insert(x);
            } else {
                sum2 += x;
                s2.insert(x);
            }
            balance();
        } else if(op == "wiki") {
            ll y;
            cin >> y;
            if(y <= med) {
                auto p = s1.lower_bound(y);
                sum1 -= *p;
                s1.erase(p);
            } else {
                auto p = s2.lower_bound(y);
                sum2 -= *p;
                s2.erase(p);
            }
            balance();
        } else if(op == "wiwi") {
            cout << (sum2 - s2.size() * med) + (s1.size() * med - sum1) << '\n';
        } else {
            int k;
            cin >> k;
            if(k <= s1.size()) {
                vector<ll> val(k, 0);
                int mod = 0;
                for(auto cur : s1) {
                    val[mod] += cur;
                    ++mod;
                    if(mod == k) mod = 0;
                }
                sum1 = 0;
                s1.clear();
                for(auto cur : s2) {
                    val[mod] += cur;
                    ++mod;
                    if(mod == k) mod = 0;
                }
                sum2 = 0;
                s2.clear();
                sort(val.begin(), val.end());
                for(int i = 0; i < ((k + 1) >> 1); ++i) {
                    sum1 += val[i];
                    s1.insert(val[i]);
                }
                for(int i = ((k + 1) >> 1); i < k; ++i) {
                    sum2 += val[i];
                    s2.insert(val[i]);
                }
            } else {
                int left = s1.size() + s2.size() - k;
                vector<ll> val(left, 0);
                for(int i = 0; i < left; ++i) {
                    auto p = s1.begin();
                    val[i] += *p;
                    sum1 -= *p;
                    s1.erase(p);
                }
                for(int i = 0; i < left; ++i) {
                    auto p = prev(s2.end());
                    val[left - i - 1] += *p;
                    sum2 -= *p;
                    s2.erase(p);
                }
                for(int i = 0; i < left; ++i) {
                    if(val[i] < *s2.begin()) {
                        sum1 += val[i];
                        s1.insert(val[i]);
                    } else {
                        sum2 += val[i];
                        s2.insert(val[i]);
                    }
                    balance();
                }
            }
        }
        if(s1.size()) med = *prev(s1.end());
        else med = 0;
        // debug(med);
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

