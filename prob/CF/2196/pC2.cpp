/*
 * Created : 2026-02-12 00:15:23 lemonilemon
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
vector<int> ask(int k) {
    cout << "? " << k << endl;
    cout.flush();
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        cin >> res[i];
    }
    return res;
}
void guess(vector<pair<int, int>> edges) {
    cout << "! " << edges.size() << endl;
    cout.flush();
    for (auto [u, v] : edges) {
        cout << u << ' ' << v << endl;
        cout.flush();
    }
    return;
}
// solution
void solve() {
    int n;
    cin >> n;
    vector<int> st(n + 1, 0), ed(n + 1, 0);
    vector<int> color(n + 1, 0);
    int finish_cnt = 0;
    vector<pair<int, int>> edges;
    color[1] = 1;
    st[1] = 1;
    int curk = 2;
    vector<int> last_path = {1};
    vector<int> cur_path;
    while (finish_cnt < n) {
        cur_path = ask(curk);
        if (!cur_path.empty() && !color[cur_path.back()]) {
            color[cur_path.back()] = 1;
            st[cur_path.back()] = curk;
        }
        if (cur_path.size() > last_path.size()) { // new edge
            debug("new edge", last_path.back(), cur_path.back());
            edges.push_back({last_path.back(), cur_path.back()});
        } else { // replace
            vector<int> tmp1 = last_path, tmp2 = cur_path;
            if (!tmp2.empty())
                tmp2.pop_back();
            while (!tmp1.empty() &&
                   (tmp2.empty() || tmp1.back() != tmp2.back())) {
                if (color[tmp1.back()] == 1) {
                    color[tmp1.back()] = 2;
                    ed[tmp1.back()] = curk;
                    debug("finish", tmp1.back(), st[tmp1.back()],
                          ed[tmp1.back()]);
                    ++finish_cnt;
                }
                tmp1.pop_back();
            }
            if (!tmp2.empty()) {
                debug("new edge", tmp2.back(), cur_path.back());
                edges.push_back({tmp2.back(), cur_path.back()});
            }
        }
        if (!cur_path.empty() && color[cur_path.back()] == 2) {
            curk += ed[cur_path.back()] - st[cur_path.back()];
            debug(curk);
            last_path = cur_path;
            continue;
        }
        ++curk;
        debug(curk);
        last_path = cur_path;
    }
    guess(edges);
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
