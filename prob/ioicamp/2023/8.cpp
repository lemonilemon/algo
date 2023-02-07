#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAXN = 2e5 + 5;
struct Line {
	ll m, k;
	Line(): m(0), k(0) {}
	Line(ll _m, ll _k): m(_m), k(_k) {}
	ll operator() (ll x) {
		return m * x + k;
	}
};
ll h[MAXN];
ll dp[MAXN];
bool check(Line l, Line l1, Line l2) {
	auto [m, k] = l;
	auto [m1, k1] = l1;
	auto [m2, k2] = l2;
	return (m - m1) * (k2 - k1) >= (k1 - k) * (m1 - m2);
}
void solve() {
	ll N, C;
	cin >> N >> C;
	for(int	i = 1; i <= N; ++i) {
		cin >> h[i];	
	}
	dp[1] = 0;
	deque<Line> dq;
	dq.push_back({-2 * h[1], h[1] * h[1] + dp[1]});
	for(int i = 2; i <= N; ++i) {
		while((int)dq.size() >= 2 && dq[1](h[i]) <= dq.front()(h[i])) dq.pop_front();	
		dp[i] = dq.front()(h[i]) + C + h[i] * h[i];
		Line line(-2 * h[i], h[i] * h[i] + dp[i]);
		while((int)dq.size() >= 2 && check(line, dq.back(), dq[(int)dq.size() - 2])) dq.pop_back();	
		dq.push_back(line);
	}
	cout << dp[N] << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
