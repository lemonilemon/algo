#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int DOM = 1e6;

vector<int> f(DOM + 1);
vector<int> p;

void init() {
    f[1] = 1e9 + 225;
    for (int i = 2; i <= DOM; i++) {
        if (!f[i]) {
            p.push_back(i);
            f[i] = i;
        }

        for (auto& n: p) {
            if (n * i > DOM) break;
            f[n * i] = n;
            if (i % n == 0) break;
        }
    }
}

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;

    vector<int> a(N), b(M);
    for (auto& n: a) cin >> n;
    for (auto& n: b) cin >> n;

    auto cmp1 = [](int a, int b) {
        while (a > 1 || b > 1) {
            if (f[a] != f[b]) return f[a] > f[b];

            int pa = 0, pb = 0, x = f[a];
            for (; a % x == 0; a /= x) pa++;
            for (; b % x == 0; b /= x) pb++;
            if (pa != pb) return pa < pb;
        }

        return false;
    };

    sort(a.begin(), a.end(), cmp1);
    sort(b.begin(), b.end(), cmp1);

    vector<int> lb(N, 0), rb(N, M);
    ll possible = N * M;

    mt19937 rng(325);

    int na = 0, nb = 0;
    while (1) {
        ll cur = rng() % possible;
        int i = 0;
        while (cur >= rb[i] - lb[i]) {
            cur -= rb[i] - lb[i];
            i++;
        }
        na = a[i], nb = b[lb[i] + cur];


        auto cmp2 = [&](int la, int lb, int ra, int rb) {
            while (la > 1 || lb > 1 || ra > 1 || rb > 1) {
                int fl = min(f[la], f[lb]);
                int fr = min(f[ra], f[rb]);
                if (fl != fr) return (fl < fr ? 1 : -1);

                int pl = 0, pr = 0;

                for (; la % fl == 0; la /= fl) pl++;
                for (; lb % fl == 0; lb /= fl) pl++;
                for (; ra % fr == 0; ra /= fr) pr++;
                for (; rb % fr == 0; rb /= fr) pr++;

                if (pl != pr) return (pl < pr ? -1 : 1);
            }
            return 0;
        };

        ll uppercnt = 0;
        {
            int bi = M - 1;
            for (int ai = 0; ai < N; ai++) {
                while (bi >= 0 && cmp2(na, nb, a[ai], b[bi]) <= 0) bi--;
                uppercnt += bi + 1;
            }
        }
        ll lowercnt = 0;
        {
            int bi = M - 1;
            for(int ai = 0; ai < N; ai++) {
                while (bi >= 0 && cmp2(na, nb, a[ai], b[bi]) < 0) bi--;
                lowercnt += bi + 1;
            }
        }
        if(uppercnt < K && K <= lowercnt) break;

        /*if (uppercnt == K) {
            cout << na * nb << '\n';
            return;
        }*/
        possible = 0;
        if (uppercnt > K) {
            for (int i = 0; i < N; i++) {
                if (i > 0) rb[i] = min(rb[i], rb[i - 1]);
                while (lb[i] < rb[i] && cmp2(na, nb, a[i], b[rb[i] - 1]) <= 0) rb[i]--;
            }
        }

        if (uppercnt < K) {
            for (int i = N - 1; i >= 0; i--) {
                if (i < N - 1) lb[i] = max(lb[i + 1], lb[i]);
                while (lb[i] < rb[i] && cmp2(na, nb, a[i], b[lb[i]]) >= 0) lb[i]++;
            }
        }

        for (int i = 0; i < N; i++) possible += rb[i] - lb[i];
    }
    cout << 1ll * na * nb << '\n';
}

signed main() {
    init();

    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) solve();
}

