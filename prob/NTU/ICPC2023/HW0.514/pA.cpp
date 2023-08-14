#include <bits/stdc++.h>
using namespace std;
const int MAXN = 35;
vector<vector<string> > answers;
char mat[MAXN][MAXN];
void solve() {
    string s[6];
    for(int i = 0; i < 6; ++i) {
        cin >> s[i];
    }
    sort(s, s + 6);
    bool flag = 0;
    do {
        if((int)s[0].size() + (int)s[5].size() - 1 != (int)s[3].size()) continue;
        if((int)s[1].size() + (int)s[4].size() - 1 != (int)s[2].size()) continue;
        if(s[0].front() != s[1].front() || s[0].back() != s[2].front()) continue;
        if(s[3].front() != s[1].back() || s[3].back() != s[4].front()) continue;
        if(s[3][s[0].size() - 1] != s[2][s[1].size() - 1]) continue;
        if(s[5].front() != s[2].back() || s[5].back() != s[4].back()) continue;
        flag = 1; 
        int n = s[2].size(), m = s[3].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                mat[i][j] = '.';
            }
        }
        for(int i = 0; i < (int)s[0].size(); ++i) {
            mat[0][i] = s[0][i];
        }
        for(int i = 0; i < (int)s[1].size(); ++i) {
            mat[i][0] = s[1][i];
        }
        for(int i = 0; i < (int)s[2].size(); ++i) {
            mat[i][s[0].size() - 1] = s[2][i];
        }
        for(int i = 0; i < (int)s[3].size(); ++i) {
            mat[s[1].size() - 1][i] = s[3][i];
        }
        for(int i = 0; i < (int)s[4].size(); ++i) {
            mat[s[1].size() - 1 + i][s[3].size() - 1] = s[4][i];
        }
        for(int i = 0; i < (int)s[5].size(); ++i) {
            mat[s[2].size() - 1][s[0].size() - 1 + i] = s[5][i];
        }
        vector<string> ans;
        for(int i = 0; i < n; ++i) {
            string t;
            for(int j = 0; j < m; ++j) {
                t += mat[i][j];
            }
            ans.push_back(t); 
        }
        answers.push_back(ans);
    } while(next_permutation(s, s + 6));
    if(!flag) {
        cout << "Impossible\n";
        return;
    }
    auto mnans = answers.front();
    for(auto ans : answers) {
        mnans = min(ans, mnans);
    }
    for(auto t : mnans) {
        cout << t << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
