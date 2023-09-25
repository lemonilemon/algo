#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int ll;
//typedef unsigned long long int ull;
typedef pair<ll, ll> pii;
const int MAXN = 1e5 + 5;
const ll INF = 1e18 + 5;
pii operator - (pii a, pii b) {
	return make_pair(a.first - b.first, a.second - b.second);
}
ll dot(pii a, pii b) {
	return a.first * b.first + a.second * b.second;
}
ll dis(pii a, pii b) {
	return dot(a - b, a - b);
}
ll presum[MAXN];
pii points[MAXN], temp[MAXN];
ll dq(int l, int r) {
	int m = (l + r) >> 1;
	ll midpos = points[m].first;
	if(l >= r) return INF;
    ll d2 = min(dq(l, m), dq(m + 1, r));
    ll d = ceil(sqrt(d2));
	merge(points + l, points + m + 1, points + m + 1, points + r + 1, temp, [](auto a, auto b) {
		return a.second < b.second;
	});
	vector<pii> s;
	for(int i = l; i <= r; ++i) {
		points[i] = temp[i - l];
		if(abs(midpos - points[i].first) <= d) s.push_back(points[i]);
	}
	for(int i = 0; i < s.size(); ++i) {
		for(int j = 1; j <= 3 && i + j < s.size(); ++j) {
			d2 = min(d2, dis(s[i], s[i + j]));
		}
	}
	return d2;
}

void solve() {
    int n;
    cin >> n;
    points[0].first = 0, points[0].second = 0;
	for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        presum[i] = presum[i - 1] + a;
		points[i].first = i;
        points[i].second = presum[i];
	}
	sort(points, points + n + 1);
	cout << dq(0, n) << '\n';
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}

