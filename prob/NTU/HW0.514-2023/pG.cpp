#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005; 
vector<int> seg[MAXN << 2];
bitset<MAXN> bt[MAXN << 2];
int n, q;
void modify(int val, int ql, int qr, int l = 1, int r = n, int v = 1) {
    if(ql == l && qr == r) {
        seg[v].push_back(val);
        return;
    }
    int mid = (l + r) >> 1;
    if(ql > mid) modify(val, ql, qr, mid + 1, r, v << 1 | 1);
    else if(qr <= mid) modify(val, ql, qr, l, mid, v << 1);
    else {
        modify(val, ql, mid, l, mid, v << 1);
        modify(val, mid + 1, qr, mid + 1, r, v << 1 | 1);
    }
}
bitset<MAXN> traversal(int l = 1, int r = n, int v = 1) {
    bitset<MAXN> ret;
    if(l == r) ret[0] = 1;
    else {
        int mid = (l + r) >> 1;
        ret = traversal(l, mid, v << 1);
        ret |= traversal(mid + 1, r, v << 1 | 1);
    }
    for(auto k : seg[v]) {
        ret |= (ret << k);
    }
    return ret;
}
void solve() {
    cin >> n >> q;
    for(int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        modify(x, l, r);
    }
    auto ans = traversal();
    vector<int> nums;
    for(int i = 1; i <= n; ++i) {
        if(ans[i]) nums.push_back(i);
    }
    cout << nums.size() << '\n';
    for(int i = 0; i < (int)nums.size(); ++i) {
        cout << nums[i] << " \n"[i == (int)nums.size() - 1];
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
