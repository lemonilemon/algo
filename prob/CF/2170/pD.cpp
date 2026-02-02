/*
 * Created : 2025-11-28 23:20:45 lemonilemon
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

// solution
void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> color(n, 0);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'I') {
            if (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                --sum;
            else
                ++sum;
        } else if (s[i] == 'V') {
            sum += 5;
        } else if (s[i] == 'X') {
            sum += 10;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != '?')
            continue;
        color[i] = 1;
        if (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X'))
            color[i] = 2; // available for -1
    }

    for (int i = 1; i < n; ++i) {
        if (s[i] != '?')
            continue;
        if (s[i - 1] == 'I') {
            if (color[i] == 1)
                color[i] = 3; // available for val-2 using V or X
            else if (color[i] == 2)
                color[i] = 5; // still available for -1
            debug(i, color[i]);
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] != '?')
            continue;
        if (color[i] == 1 && color[i + 1] == 1) {
            color[i] = 4; // a pair of ??
        }
    }
    int ori_total_cnt = 0;
    vector<int> ori_cnt(6, 0);
    for (int i = 0; i < n; ++i) {
        ++ori_cnt[color[i]];
        if (color[i] != 0)
            ++ori_total_cnt;
    }
    debug(ori_cnt[0], ori_cnt[1], ori_cnt[2], ori_cnt[3], ori_cnt[4],
          ori_cnt[5], ori_total_cnt);
    for (int i = 0; i < q; ++i) {
        int cx, cv, ci;
        cin >> cx >> cv >> ci;
        int total_cnt = ori_total_cnt;
        vector<int> cnt = ori_cnt;
        ll ans = sum;
        if (ci >= total_cnt) {
            ci -= total_cnt;
            ans += total_cnt - 1ll * 2 * (cnt[2] + cnt[5]);
            cout << ans << '\n';
            continue;
        }
        // used -1 from single ?
        {
            int used = min(ci, cnt[2]);
            ci -= used;
            ans -= used;
            cnt[2] -= used;
            total_cnt -= used;
        }
        // used -1 from I?V or I?X
        debug("Stage 1", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], total_cnt, ci,
              ans);
        {
            // place I in ??
            int used = min(ci, cnt[4]);
            ci -= used;
            ans += used;
            cnt[4] -= used;
            cnt[1] -= used;
            cnt[3] += used;
            total_cnt -= used;
        }
        debug("Stage 2", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], total_cnt, ci,
              ans);
        {
            // place I in ? for nothing
            int used = min(ci, cnt[1]);
            ci -= used;
            ans += used;
            cnt[1] -= used;
            total_cnt -= used;
        }
        {
            int used = min(ci, cnt[5]);
            ci -= used;
            ans -= used;
            cnt[5] -= used;
            total_cnt -= used;
        }
        {
            // place I in ? after I
            int used = min(ci, cnt[3]);
            ci -= used;
            ans += used;
            cnt[3] -= used;
            total_cnt -= used;
        }
        debug("Stage 3", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], total_cnt, ci,
              ans);
        cnt[3] += cnt[5];
        cnt[5] = 0;
        // ci must be 0 now
        int need_X = max(total_cnt - cv, 0);
        int need_V = min(cv, total_cnt);
        debug(ans, need_X, need_V, total_cnt, cnt[3], cv);
        ans += 1ll * need_X * 10;
        ans += 1ll * need_V * 5;
        debug(ans);
        ans -= 1ll * cnt[3] * 2;
        cout << ans << '\n';
    }
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
