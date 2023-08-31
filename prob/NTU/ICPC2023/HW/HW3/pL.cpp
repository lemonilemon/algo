#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, int, int> piii;
const int MAXN = 1e6 + 5;
const int MOD = 998244353;
piii presum[3][MAXN];

piii operator + (const piii& a, const piii& b) {
    return make_tuple(get<0>(a) + get<0>(b), get<1>(a) + get<1>(b), get<2>(a) + get<2>(b));
}
piii operator - (const piii& a, const piii& b) {
    return make_tuple(get<0>(a) - get<0>(b), get<1>(a) - get<1>(b), get<2>(a) - get<2>(b));
}
int mabs(ll a) {
    return (a % MOD + MOD) % MOD;
}
int madd(int a, int b) {
    return mabs(a + b);
}
struct BIT {
    int sz;
    int* val;
    BIT(int _sz): sz(_sz) {
        val = new int[sz + 1];
        for(int i = 0; i <= sz; ++i) {
            val[i] = 0;
        }
    }
    int query(int k) {
        int ret = 0;
        for(; k > 0; k ^= k & -k) {
            ret = madd(ret, val[k]);
        }
        return ret;
    }
    void modify(int k, int v) {
        for(; k <= sz; k += k & -k) {
            val[k] = madd(val[k], v);
        }
    }
};
vector<BIT> bits[3];
int pos_to_bits[3][MAXN], pos_to_dis01[3][MAXN];
int dp[MAXN];
void solve(){
    string s;
    cin >> s;
    presum[0][0] = make_tuple(0, 0, 0);
    int n = s.size();
    for(int i = 1; i <= n; ++i) {
        char ch = s[i - 1];
        if(ch == 'C') presum[0][i] = presum[0][i - 1] + make_tuple(1, 0, 0);
        else if(ch == 'I') presum[0][i] = presum[0][i - 1] + make_tuple(0, 1, 0);
        else presum[0][i] = presum[0][i - 1] + make_tuple(0, 0, 1);
    }
    for(int i = 0; i <= n; ++i) {
        for(int t = 1; t < 3; ++t) {
            presum[t][i] = presum[0][i];    
            for(int j = 0; j < t; ++j) {
                swap(get<0>(presum[t][i]), get<1>(presum[t][i]));
                swap(get<0>(presum[t][i]), get<2>(presum[t][i]));
            }
        }
    }
    /* for(int t = 0; t < 3; ++t) {
        cerr << t << ":\n";
        for(int i = 0; i <= n; ++i) {
            auto [a, b, c] = presum[t][i];
            cerr << a << ' ' << b << ' ' << c << '\n';
        }
    }
    cerr << '\n'; */
    // discrete
    for(int t = 0; t < 3; ++t) {
        map<int, vector<int> > dis12_to_pos;
        for(int i = 0; i <= n; ++i) {
            int dis12 = get<1>(presum[t][i]) - get<2>(presum[t][i]);
            dis12_to_pos[dis12].push_back(i);
        }
        for(auto [dis12, poses] : dis12_to_pos) {
            vector<int> dis01_vals; 
            for(auto pos : poses) {
                pos_to_bits[t][pos] = bits[t].size();
                int dis01 = get<0>(presum[t][pos]) - get<1>(presum[t][pos]);
                dis01_vals.push_back(dis01);
            }
            sort(dis01_vals.begin(), dis01_vals.end());
            dis01_vals.erase(unique(dis01_vals.begin(), dis01_vals.end()), dis01_vals.end());
            // discrete
            for(auto pos : poses) {
                int dis01 = get<0>(presum[t][pos]) - get<1>(presum[t][pos]);
                pos_to_dis01[t][pos] = lower_bound(dis01_vals.begin(), dis01_vals.end(), dis01) - dis01_vals.begin() + 1;
            }
            bits[t].push_back(BIT(poses.size()));
        }
    }
    dp[0] = 1;
    for(int i = 0; i <= n; ++i) {
        if(i) dp[i] = 0;
        else dp[i] = 1;
        for(int t = 0; t < 3; ++t) {
            int curbit = pos_to_bits[t][i];
            int dis01 = pos_to_dis01[t][i];
            dp[i] = madd(dp[i], bits[t][curbit].query(dis01 - 1));
        }
        for(int t = 0; t < 3; ++t) { 
            int curbit = pos_to_bits[t][i];
            int dis01 = pos_to_dis01[t][i];
            bits[t][curbit].modify(dis01, dp[i]);
        }
    }
    cout << dp[n] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}
