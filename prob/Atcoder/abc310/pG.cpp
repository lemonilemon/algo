#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 998244353;
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
    int** val;
    int row, col;
    Mat(int row, int col): row(row), col(col) {
        val = new int*[row];
        for(int i = 0; i < row; ++i) {
            val[i] = new int[col];
        }
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                val[i][j] = 0;
            }
        }
    }
    Mat(const vector<vector<int> >& mat): Mat(mat.size(), mat[0].size()) {
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                val[i][j] = mat[i][j];
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
    int* operator[] (const int& idx) const {
        return val[idx];
    }
    Mat& operator = (const Mat& that) {
        assert(row == that.row && col == that.col);
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                val[i][j] = that[i][j];
            }
        }
        return *this;
    }
    Mat operator * (const Mat& that) const {
        assert(col == that.row);
        Mat ret(row, that.col);
        for(int i = 0; i < ret.row; ++i) {
            for(int j = 0; j < ret.col; ++j) {
                for(int k = 0; k < col; ++k) {
                    ret[i][j] = madd(ret[i][j], mmul(val[i][k], that[k][j]));
                }
            }
        }
        return ret;
    }
    static const Mat eye(int n) {
        Mat ret(n, n);
        for(int i = 0; i < n; ++i) {
            ret[i][i] = 1;
        }
        return ret;
    }
};
Mat pow(Mat t, ll b) {
    Mat ret = Mat::eye(t.row);
    while(b) {
        if(b & 1) ret = t * ret;
        b >>= 1;
        t = t * t;
    }
    return ret;
}
void solve() {
    int n, k;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
