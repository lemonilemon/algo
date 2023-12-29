/* 
 * Created : 2023-12-10 12:12:15 lemonilemon
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
vector<vector<int> > a, b;

// solution
void solve() {
    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; ++i) {
        a.push_back(vector<int>());
        for(int j = 0; j < w; ++j) {
            int temp;
            cin >> temp;
            a[i].push_back(temp);
        }
    }
    for(int i = 0; i < h; ++i) {
        b.push_back(vector<int>());
        for(int j = 0; j < w; ++j) {
            int temp;
            cin >> temp;
            b[i].push_back(temp);
        }
    }
    vector<int> ph, pw;
    for(int i = 0; i < h; ++i) {
        ph.push_back(i);
    }
    for(int i = 0; i < w; ++i) {
        pw.push_back(i);
    }
    map<vector<int>, int> permh, permw;
    permh[ph] = 0;
    permw[pw] = 0;
    queue<vector<int> > que;
    que.push(ph);
    while(!que.empty()) {
        auto u = que.front();
        que.pop();
        for(int i = 0; i < h - 1; ++i) {
            auto v = u;
            swap(v[i], v[i + 1]);
            if(permh.count(v)) continue;
            permh[v] = permh[u] + 1;
            que.push(v);
        }
    }
    que.push(pw);
    while(!que.empty()) {
        auto u = que.front();
        que.pop();
        for(int i = 0; i < w - 1; ++i) {
            auto v = u;
            swap(v[i], v[i + 1]);
            if(permw.count(v)) continue;
            permw[v] = permw[u] + 1;
            que.push(v);
        }
    }
    int ans = 1e9 + 7;
    do {
        sort(ph.begin(), ph.end());
        do {
            int cnt = permh[ph] + permw[pw];
            bool flag = 1;
            for(int i = 0; i < h; ++i) {
                for(int j = 0; j < w; ++j) {
                    if(a[i][j] != b[ph[i]][pw[j]]) {
                        flag = 0;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) ans = min(cnt, ans);
        } while(next_permutation(ph.begin(), ph.end()));
    } while(next_permutation(pw.begin(), pw.end()));
    if(ans == (int)(1e9 + 7)) cout << "-1\n";
    else cout << ans << '\n';
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

