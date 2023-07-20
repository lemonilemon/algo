#include <bits/stdc++.h>
using namespace std;
bool color[26];

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < 26; ++i) {
        color[i] = 0;
    }
    string s;
    cin >> s;
    char last = '\0';
    for(int i = 0; i < n; ++i) {
        char c = s[i];
        if(c == last) continue;
        if(color[c - 'A']) {
            cout << "NO\n";
            return;
        } else color[c - 'A'] = 1;
        last = c;
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        solve();
    }
}
