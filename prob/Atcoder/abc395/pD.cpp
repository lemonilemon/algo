/*
 * Created : 2025-03-01 20:08:13 lemonilemon
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
#define safe()                                                                 \
    cerr << "\e[1;32m" << __PRETTY_FUNCTION__ << " at line " << __LINE__       \
         << " is safe.\e[0m\n";
template <typename... T> void _debug(const char *s, T... args) {
    int cnt = sizeof...(T);
    ((cerr << "\033[1;32m(" << s << ") = ("), ...,
     (cerr << args << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void _expand(const char *s, int nl, int nr, T l, T r) {
    cerr << "\033[1;32mexpand " << s << " from " << s << '[' << nl << "] to "
         << s << '[' << nr << "].\n---\n[";
    for (T it = l; it != r + 1; ++it) {
        cerr << *it << (it != r ? ", " : "]\n---\033[0m\n");
    }
}
#else
#define debug(...) ((void)0)
#define safe() ((void)0)
#define expand(...) ((void)0)
#endif

// constants
const int MAXN = 1e6 + 5;

int pin_place[MAXN];
int nest_place[MAXN];
int place_nest[MAXN];
// solution
void solve() {
    int n, q;
    cin >> n >> q;
    iota(nest_place + 1, nest_place + n + 1, 1);
    iota(place_nest + 1, place_nest + n + 1, 1);
    iota(pin_place + 1, pin_place + n + 1, 1);
    while (q--) {
        int op;
        cin >> op;
        switch (op) {
        case 1: {
            int a, b;
            cin >> a >> b;
            int place = nest_place[b];
            pin_place[a] = place;
            break;
        }
        case 2: {
            int a, b;
            cin >> a >> b;
            int pa = nest_place[a], pb = nest_place[b];
            swap(nest_place[a], nest_place[b]);
            place_nest[nest_place[a]] = a;
            place_nest[nest_place[b]] = b;
            break;
        }
        case 3: {
            int a;
            cin >> a;
            int place = pin_place[a];
            cout << place_nest[pin_place[a]] << '\n';
            break;
        }
        }
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
