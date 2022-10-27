#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define local
#ifdef local
using std::cerr;
#define debug(arg) deone(#arg, arg) 
#define orange(l, r) derange(#l ", " #r, l, r)
#define safe() std::cerr << "\033[1;32m" << __PRETTY_FUNCTION__ << " is safe\033[0m\n"
template <typename T> void deone(const char *s, T arg) {
	cerr << "\033[1;32m" << s << " = " << arg << "\033[0m\n"; 
}
template <typename T> void derange(const char *s, T L, T R) {
	cerr << "\033[1;32m[" << s << "] = [";
	for(int i = 0; L != R; ++L) cerr << (i++? ", " : "") << *L;
	cerr << "]\033[0m\n";
}
#else
#define safe() ((void)0)
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif // local
using namespace std;
using ll = long long int;
FILE* setIO(string file = "") {
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(file.empty()) return NULL;
	if(freopen((file + ".in").c_str(), "r", stdin) == NULL) return NULL; 
	return freopen((file + ".out").c_str(), "w", stdout);
}
const int MAXN = 2e5 + 5;
int r;
int mabs(ll a) {
	return (a % r + r) % r;
}
int madd(int a, int b) {
	return mabs(a + b);
}
int mmul(int a, int b) {
	return mabs(1ll * a * b);
}
struct Mat {
	ll val[2][2];
	Mat() {
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				val[i][j] = 0;
			}
		}
	}
	Mat(const Mat& that) {
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				val[i][j] = that.val[i][j];
			}
		}
	}
	Mat operator * (const Mat& that) const {
		Mat ret;
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				for(int k = 0; k < 2; ++k) {
					ret.val[i][j] = madd(ret.val[i][j], mmul(val[i][k], that.val[k][j]));
				}
			}
		}
		return ret;
	}
	Mat& operator = (const Mat& that) {
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				val[i][j] = that.val[i][j];
			}
		}
		return *this;
	}
} seg[MAXN << 2];
Mat A[MAXN + 5];
istream& operator >> (istream& is, Mat& that) {
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			is >> that.val[i][j];
		}
	}
	return is;
}
ostream& operator << (ostream& os, const Mat& that) {
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			os << that.val[i][j] << " \n"[j == 1];
		}
	}
	return os;
}
void pull(int v) {
	seg[v] = seg[v << 1] * seg[v << 1 | 1];
}
void build(int l = 1, int r = MAXN, int v = 1) {
	if(l == r) {
		seg[v] = A[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	pull(v);
}
Mat query(int ql, int qr, int l = 1, int r = MAXN, int v = 1) {
	if(ql == l && qr == r) return seg[v];
	int mid = (l + r) >> 1;
	if(qr <= mid) return query(ql, qr, l, mid, v << 1);
	if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
	return query(ql, mid, l, mid, v << 1) * query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}
void solve() {
	int n, m;
	cin >> r >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> A[i];	
	}
	build();
	for(int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << '\n';
	}	
}

int main() {
	setIO();
	int T = 1;
	//cin >> T;
	for(int t = 1; t <= T; ++t) {
		//cout << "Case " << t << ": ";
		solve();
	}
}

