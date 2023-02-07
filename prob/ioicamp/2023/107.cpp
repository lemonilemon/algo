#include <bits/stdc++.h>
using namespace std;
void solve() {
	int sz = 4095;
	int num = 4099;
	cout << sz << "\n";
	for(int i = 0; i < sz; ++i) {
		cout << num << " \n"[i == sz - 1];
	}
}

int main() {
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

