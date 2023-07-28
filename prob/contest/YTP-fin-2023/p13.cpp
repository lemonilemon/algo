#include <bits/stdc++.h>
using namespace std;
const int MAXA = 2e5 + 5, INF = 1e9 + 7;
struct Node2 {
    int val;
    Node2 *lc, *rc;
    Node2() {
        val = 0;
        lc = rc = NULL;
    }
};
struct Node1 {
    Node1 *lc, *rc;
    Node2 *c;
    Node1() {
        c = NULL;
        lc = rc = NULL;
    }
};
int Val2(Node2 *node) { return node? node->val : 0; }
void pull2(Node2 *node) { node->val = Val2(node->lc) + Val2(node->rc); }
void modify2(Node2 * node, int Y1, int Y2, int qy, int d) {
    if(Y1 == Y2) {
        assert(Y1 == qy);
        node->val += d;
        return;
    }
    int mid = (Y1 + Y2) >> 1;
    if(qy <= mid) {
        if(!node -> lc)
            node->lc = new Node2();
        modify2(node->lc, Y1, mid, qy, d);
    } else {
        if(!node -> rc) 
            node -> rc = new Node2();
        modify2(node->rc, mid + 1, Y2, qy, d);
    }
    pull2(node);
}
void modify1(Node1 *node, int X1, int X2, int qx, int qy, int d) {
    if(!node->c)
        node->c = new Node2();
    modify2(node->c, 1, INF, qy, d);
    if(X1 == X2) {
        assert(X1 == qx);
        return;
    }
    int mid = (X1 + X2) >> 1;
    if(qx <= mid) {
        if(!node->lc)
            node->lc = new Node1();
        modify1(node->lc, X1, mid, qx, qy, d);
    } else {
        if(!node->rc)
            node->rc = new Node1();
        modify1(node->rc, mid + 1, X2, qx, qy, d);
    }
}
int query2(Node2 *node, int Y1, int Y2, int qy1, int qy2) {
    if(qy1 > Y2 || qy2 < Y1)
        return 0;
    if(!node)
        return 0;
    if(qy1 <= Y1 && Y2 <= qy2) 
        return node->val;
    int mid = (Y1 + Y2) >> 1;
    return query2(node->lc, Y1, mid, qy1, qy2) + query2(node->rc, mid + 1, Y2, qy1, qy2);
}
int query1(Node1 *node, int X1, int X2, int qx1, int qx2, int qy1, int qy2) {
    if(qx1 > X2 || qx2 < X1)
        return 0;
    if(!node)
        return 0;
    if(qx1 <= X1 && X2 <= qx2)
        return query2(node->c, 1, INF, qy1, qy2);
    int mid = (X1 + X2) >> 1;
    return query1(node->lc, X1, mid, qx1, qx2, qy1, qy2) + query1(node->rc, mid + 1, X2, qx1, qx2, qy1, qy2);
}
Node1 *root;
bool check(int x, int y, int k) {
    int lx = x - k, ly = y - k;
    int rx = x + k, ry = y + k;
    if(query1(root, 1, INF, lx, rx, ly, ry)) return 1;
    else return 0;
}
void solve() {
    root = new Node1();
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        modify1(root, 1, INF, x - y + MAXA, x + y + MAXA, 1);
    }
    for(int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if(op == 1) {
            int l = -1, r = MAXA << 2;
            int x, y;
            cin >> x >> y;
            while(r - l > 1) {
                int mid = (l + r) >> 1;
                if(check(x - y + MAXA, x + y + MAXA, mid)) r = mid;   
                else l = mid;
            }
            cout << r << '\n';
        } else {
            int x, y;
            cin >> x >> y;
            modify1(root, 1, INF, x - y + MAXA, x + y + MAXA, 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
