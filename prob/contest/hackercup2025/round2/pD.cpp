/*
 * Created : 2025-11-16 03:19:25 lemonilemon
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
const int MOD = 998244353;
map<tuple<int, int, int>, int> dp; // dp[(currrent_pos, remainder, mask)][mask]
int sufsum[2025];
int ppow10[2025];
int k;

int mabs(ll x) { return (x % MOD + MOD) % MOD; }
int madd(int a, int b) { return mabs(a + b); }
int mmul(int a, int b) { return mabs(1ll * a * b); }

void init() {
    ppow10[0] = 1;
    for (int i = 1; i < 2025; ++i) {
        ppow10[i] = mmul(ppow10[i - 1], 10);
    }
}

int compute_number(const string &s, int cur, int remainder, int mask,
                   bool uplim, bool l0) {
    // debug(s, cur, remainder, mask, uplim, l0);
    if (cur >= s.size()) {
        return mask == -1;
    }
    if (mask == -1) { // already k-weak
        if (uplim)
            return sufsum[cur];
        return ppow10[s.size() - cur];
    }
    tuple<int, int, int> state(cur, remainder, mask);
    if (!uplim && !l0 && dp.count(state)) {
        return dp[state];
    }
    int ret = 0;
    int current_digit = s[cur] - '0';
    for (int i = 0; i <= 9; ++i) {
        if (uplim && i > current_digit) {
            break;
        }
        int new_remainder = (remainder + i) % k;
        int new_mask = mask;
        if (!l0 || i != 0) {
            if ((1 << new_remainder) & mask) {
                new_mask = -1;
            }
            new_mask |= (1 << new_remainder);
        }
        int val = compute_number(s, cur + 1, new_remainder, new_mask,
                                 uplim && (i == current_digit), l0 && (i == 0));
        ret = madd(ret, val);
    }
    if (!uplim && !l0) {
        dp[state] = ret;
    }
    return ret;
}

int compute(const string &s) {
    dp.clear();
    for (int i = s.size() - 1; i >= 0; --i) {
        if (i == s.size() - 1)
            sufsum[i] = (s[i] - '0');
        else
            sufsum[i] =
                madd(sufsum[i + 1], mmul(s[i] - '0', ppow10[s.size() - 1 - i]));
    }
    int ret = 0;
    if (s.size() > k) {
        ret = compute_number(s.substr(s.size() - k, k), 0, 0, 1, true, true);
        ret = madd(ret, madd(sufsum[0], MOD - sufsum[s.size() - k]));
    } else
        ret = compute_number(s, 0, 0, 1, true, true);
    // debug(s, ret);
    return ret;
}

// solution
void solve() {
    string l, r;
    cin >> l >> r;
    cin >> k;
    cout << compute(r) - compute(l) << '\n';
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
