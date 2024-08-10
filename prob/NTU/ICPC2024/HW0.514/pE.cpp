/* 
 * Created : 2024-07-28 23:57:59 lemonilemon
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
const int MAXN = 5e5 + 5;
int a[MAXN];
int b[MAXN];
vector<int> wrong;
int n;
int sign(int x) {
    if(x == 0) return 0;
    return x > 0? 1 : -1;
}
bool geo3(int x, int y, int z) {
    return a[x] * a[z] == a[y] * a[y] && b[x] == b[z];
}
bool check(int x) {
    for(int i = 2; i <= n - 1; ++i) {
        if(i == x) continue;
        if(i + 1 == x) {
            if(i == n - 1) continue;
            if(!geo3(i - 1, i, i + 2)) {
                return false;
            }
        } else if(i - 1 == x) {
            if(i == 2) continue;
            if(!geo3(i - 2, i, i + 1)) {
                return false;
            }
        } else {
            if(!geo3(i - 1, i, i + 1)) {
                return false;
            }
        }
    }
    return true;
}

// solution
void solve() {
    cin >> n;
    int cnt0 = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = sign(a[i]);
        a[i] = abs(a[i]);
        cnt0 += b[i] == 0;
    }
    if(cnt0 > 0) {
        if(cnt0 == n) {
            cout << "0\n";
            return;
        }
        if(cnt0 == n - 1) {
            cout << (b[1] == 0) << '\n';
            return;
        }
        if(cnt0 == n - 2) {
            cout << 1 + (b[1] == 0) << '\n';
            return;
        }
        if(cnt0 > 1) {
            cout << "2\n";
            return;
        }
        if(cnt0 == 1) {
            for(int i = 1; i <= n - 1; ++i) {
                if(b[i] == 0) {
                    if(check(i)) {
                        cout << "1\n";
                        return;
                    } else {
                        cout << "2\n";
                        return;
                    }
                }
            }
        }
    }


    for(int i = 2; i <= n - 1; ++i) {
        if(!geo3(i - 1, i, i + 1)) {
            wrong.push_back(i);
        }
    }
    
    if(wrong.size() == 0) {
        cout << "0\n";
        return;
    }

    if(check(1) || check(n)) {
        cout << "1\n";
        return;
    }

    if(wrong.size() > 3) {
        cout << "2\n";
        return;
    }
    for(auto x : wrong) {
        if(check(x) || check(x + 1) || check(x - 1)) {
            cout << "1\n";
            return;
        }
    }
    cout << "2\n";
    return;
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

