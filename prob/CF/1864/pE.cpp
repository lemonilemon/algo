/* 
 * Created : 2023-08-28 18:57:13 lemonilemon
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
#endif

// constants
const int MAXN = 2e5 + 5;
// variables
int s[MAXN];
int cntlg[32]; // count lg(s) + 1
int highbit(int k) {
    return k? __lg(k) : -1;
}
struct Trie {
    struct Node {
        int dec, cnt;
        Node* nxt[2];
        Node(int _dec): dec(_dec), cnt(0) {
            nxt[0] = nxt[1] = nullptr;
        }
        void insert(int k) {
            if(!dec) return;
            bool bit = k & (1 << (dec - 1)); 
            if(!nxt[bit]) nxt[bit] = new Node(dec - 1);
            ++nxt[bit]->cnt;
            nxt[bit] -> insert(k);
        }
        ll query(int k) { // (sum of first same bit * cnt, sum of cnt)
            bool bit = k & (1 << dec);
            
        }
    } *root = new Node(30);
    void insert(int k) {
        root -> insert(k);
    }
    void query(int k) { // sum of first same bit
        Node* cur = root;
        for(int i = 29; i > 0; --i) {
            bool bit = k & (1 << i);  
            
        }
    }
} trie;
// solution
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
        int lg = s[i]? __lg(s[i]) : -1;
        ++cntlg[__lg(s[i]) + 1];
    }
        
}

// main
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        // cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}

