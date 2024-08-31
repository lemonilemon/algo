
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define int ll
const int MAXN = 1e5 + 5;
int cnt[MAXN << 5]; 
ll sum[MAXN << 5];
int lnum[MAXN << 5], rnum[MAXN << 5];
int rt[MAXN];
int a[MAXN], b[MAXN], ord[MAXN];
int curid;

void pull(int k) {
	sum[k] = sum[lnum[k]] + sum[rnum[k]];
	cnt[k] = cnt[lnum[k]] + cnt[rnum[k]];
}

int modify(int k, int val, int l, int r, int old) {
	int dir = ++curid;
	lnum[dir] = lnum[old], rnum[dir] = rnum[old];
	if(l == r) {
		cnt[dir] = 1;
		sum[dir] = val;
		return dir;
	}	
	int mid = (l + r) >> 1;
	if(k <= mid) lnum[dir] = modify(k, val, l, mid, lnum[old]);
	else rnum[dir] = modify(k, val, mid + 1, r, rnum[old]);
	pull(dir);
	return dir;
}
int querycnt(int ql, int qr, int l, int r, int v) {
	if(ql == l && qr == r) return cnt[v];
	int mid = (l + r) >> 1;
	if(qr <= mid) return querycnt(ql, qr, l, mid, lnum[v]);
	if(ql > mid) return querycnt(ql, qr, mid + 1, r, rnum[v]);
	return querycnt(ql, mid, l, mid, lnum[v]) + querycnt(mid + 1, qr, mid + 1, qr, rnum[v]);
}
ll querysum(int ql, int qr, int l, int r, int v) {
	if(ql == l && qr == r) return sum[v];
	int mid = (l + r) >> 1;
	if(qr <= mid) return querysum(ql, qr, l, mid, lnum[v]);
	if(ql > mid) return querysum(ql, qr, mid + 1, r, rnum[v]);
	return querysum(ql, mid, l, mid, lnum[v]) + querysum(mid + 1, qr, mid + 1, qr, rnum[v]);
}

ll searchbycnt(int k, int l, int r, int lv, int rv) {
    if(k == 0) return 0;
    if(l == r) return sum[rv] - sum[lv];
    int mid = (l + r) >> 1;
    if(cnt[rnum[rv]] - cnt[rnum[lv]] < k) return sum[rnum[rv]] - sum[rnum[lv]] + searchbycnt(k - cnt[rnum[rv]] + cnt[rnum[lv]], l, mid, lnum[lv], lnum[rv]);
    return searchbycnt(k, mid + 1, r, rnum[lv], rnum[rv]);
}
ll pre[MAXN];
void init() {
	pre[0] = 0;
	for(int i = 1; i < MAXN; ++i) {
		pre[i] = pre[i - 1] + 1ll * i * i;
	}
}
void solve() {
	int n;
	cin >> n;
	curid = 1;
	rt[0] = 1;
	vector<int> vals;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		vals.push_back(a[i]);
        b[i] = i;
	}
    sort(b + 1, b + n + 1, [&](int x, int y) {
        return a[x] < a[y];
    });
	for(int i = 1; i <= n; ++i) {
        ord[b[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		rt[i] = modify(ord[i], a[i], 1, n, rt[i - 1]);
	}
	int m;
	cin >> m;
	for(int q = 0; q < m; ++q) {
		int L, R, k;
		cin >> L >> R >> k;
		cout << pre[R - L + 1] + searchbycnt(k, 1, n, rt[L - 1], rt[R]) << '\n';
	}
		
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	int T;
	cin >> T;
	while(T--)
		solve();
}

