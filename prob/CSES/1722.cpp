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
const int MOD = 1e9 + 7;
int mabs(ll a) {
	return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
	return mabs(a + b);
}
int mmul(int a, int b) {
	return mabs(1ll * a * b);
}
struct Mat {
	int row, col;
	int** val;
	Mat() {}
	Mat(int r, int c): row(r), col(c) {
		val = new int*[r];
		for(int i = 0; i < r; ++i) {
			val[i] = new int[c];
		}
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				val[i][j] = 0;
			}
		}
	}
	Mat(int r, int c, vector<int> v): Mat(r, c) {
		assert((int)v.size() == r * c);
		int cur = 0;
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				val[i][j] = v[cur++];
			}
		}
	}	
	Mat(const Mat& that): Mat(that.row, that.col) {
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				val[i][j] = that.val[i][j];
			}
		}
	}
	~Mat() {
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				val[i][j] = 0;
			}
		}
		for(int i = 0; i < row; ++i) {
			delete[] val[i];
		}
		col = 0;
		delete[] val;
		row = 0;
	}
	Mat operator * (const Mat& that) const {
		assert(col == that.row);
		Mat ret(row, that.col);
		for(int i = 0; i < ret.row; ++i) {
			for(int j = 0; j < ret.col; ++j) {
				for(int k = 0; k < col; ++k) {
					ret.val[i][j] = madd(ret.val[i][j], mmul(val[i][k], that.val[k][j]));
				}
			}
		}
		return ret;
	}
	Mat& operator = (const Mat& that) {
		assert(row == that.row && col == that.col);
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				val[i][j] = that.val[i][j];
			}
		}
		return *this;
	}
	static const Mat eye(int n) {
		Mat ret(n, n);
		for(int i = 0; i < n; ++i) {
			ret.val[i][i] = 1;
		}
		return ret;
	}
};
Mat fastpow(Mat a, ll b) {
	assert(a.row == a.col);
	Mat ret(Mat::eye(a.row));
	while(b) {
		if(b & 1) ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}
ostream& operator << (ostream& os, const Mat& that) {
	os << '\n';
	for(int i = 0; i < that.row; ++i) {
		for(int j = 0; j < that.col; ++j) {
			os << that.val[i][j] << " \n"[j == that.col - 1];
		}
	}
	return os;
}
void solve() {
	vector<int> st{1, 0}, trans{1, 1, 1, 0};
	Mat f1(2, 1, st);
	Mat t(2, 2, trans);
	ll n;
	cin >> n;
	//debug(fastpow(t, n - 1));
	if(!n) cout << "0\n";
	else cout << (fastpow(t, n - 1) * f1).val[0][0] << '\n';
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

