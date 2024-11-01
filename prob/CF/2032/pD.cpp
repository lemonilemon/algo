/*
 * Created : 2024-11-01 23:10:57 lemonilemon
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

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int res;
    cin >> res;
    if(res == -1) exit(0);
    return res;
}
void guess(vector<int> p)  {
    cout << "!";
    for(auto x : p) {
        cout << " " << x;
    }
    cout << endl;
    cout.flush();
}

// solution
void solve() {
    int n;
    cin >> n;
    vector<int> ans(n - 1);
    priority_queue<int, vector<int>, greater<> > pathend;
    pathend.push(1);
    ans[0] = 0;
    int cur = 2;
    while(cur < n) {
        if(ask(1, cur) == 1) {
            ans[cur - 1] = 0;
            pathend.push(cur++);
        } else {
            ans[cur - 1] = pathend.top();
            pathend.pop();
            pathend.push(cur++);
            break;
        }
    }
    while(cur < n) {
        int last = pathend.top();
        pathend.pop();
        if(ask(last, cur) == 0) {
            ans[cur - 1] = last;
            pathend.push(cur++);
        }
    }
    guess(ans);
}

// main
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
