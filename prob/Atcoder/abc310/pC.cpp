#include <bits/stdc++.h>
using namespace std;
set<string> ss;
void solve() {
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        string s, rs;
        cin >> s;
        rs = s;
        reverse(rs.begin(), rs.end());
        ss.insert(min(s, rs));
    }
    cout << ss.size() << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
