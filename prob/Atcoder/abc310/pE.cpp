#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long int sum = 0;
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '0') {
            sum += cnt0 + cnt1;
            cnt1 += cnt0;
            cnt0 = 1;
        } else {
            sum += cnt0 + 1;
            swap(cnt1, cnt0);
            ++cnt1;
        }
    }
    cout << sum << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
