#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pii = pair<double, double>;
const int MAXN = 1005;
const double EPS = 1e-8;
pii p[MAXN];
pii operator + (const pii& a, const pii& b) {
    return make_pair(a.first + b.first, a.second + b.second);
}
pii operator - (const pii& a, const pii& b) {
    return make_pair(a.first - b.first, a.second - b.second);
}
double operator * (const pii& a, const pii& b) {
    return a.first * b.first + a.second * b.second;
}
pii operator * (const pii& a, const double& b) {
    return make_pair(b * a.first, b * a.second);
}
pii operator / (const pii& a, const double& b) {
    return make_pair(a.first / b, a.second / b);
}
double operator ^ (const pii& a, const pii& b) {
    return a.first * b.second - a.second * b.first;
}
int sign(double a) {
    return fabs(a) < EPS? 0 : a > 0? 1 : -1;
}
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    double l = -1, r = 1e6 + 7;
    p[n] = p[0];
    for(int i = 1; i < n; ++i) {
        auto v = p[i + 1] - p[i];
        if(sign(v.second) == 0) {
            if(sign((p[1] - p[0]) * v) > 0) {
                cout << "0\n";
                return;
            }
            continue;
        }
        double intersect_x = p[i].first + (p[0].second - p[i].second) / v.second * v.first;
        if(sign(v.second) > 0) l = max(intersect_x, l);
        else r = min(intersect_x, r);
    }
    int xl = ceil(l - EPS), xr = floor(r + EPS);
    cout << max(xr - xl + 1, 0) << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
