#include <bits/stdc++.h>
using namespace std;
const int C = 30;
void solve() {
    int v;
    for(int i = 1; i <= 95; ++i) {
        while(true) {
            cout << "# " << i << ' ' << 100 << endl;
            cout.flush();
            cin >> v;
            if(v) return;
            bool flag = 1;
            for(int j = 0; j < C; ++j) {
                cout << "# " << i + 1 << ' ' << 100 << endl;
                cout.flush();
                cin >> v;
                if(v) return;
                cout << "? " << i << endl;
                cout.flush();
                cin >> v; 
                if(v == -1) return;
                if(v > 0) {
                    flag = 0;
                    break;
                }
            }
            if(flag) break;
        }
    }
    while(true) {
        cout << "# 96 100" << endl;
        cout.flush();
        cin >> v;
        if(v) return;
        cout << "? 100" << endl;
        cout.flush();
        cin >> v;
        if(v == -1) return;
        if(v == 0) break;
    }
    cout << '!' << endl;
    cout.flush();
}
int main() {
    solve(); 
}
