#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    int r = 0, b = 0, other = 0;
    for(auto c :s) {
        if(c == 'r') r++;
        else if(c == 'b') b++;
        else other++;
    }
    if(r == b) {
        cout << "Ian\n";
        return;
    }
    if(abs(r - b) == 1) {
        if(r + b == 1) cout << "Ian\n";
        else if(other & 1) cout << "Jay\n";
        else cout << "Ian\n";
        return;
    }
    cout << "Jay\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
