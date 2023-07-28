
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef DEBUG 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){_
    int n, m, k;cin>>n>>m>>k;
    vector<int> power(n+1);
    vector<vector<int>> adj(k+1);
    vector<int> money(k+1);
    vector<int> visited(k+1, 0);
    for(int i=1; i<=n; i++) cin>>power[i];
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        adj[power[a]].push_back(power[b]);
        adj[power[b]].push_back(power[a]);
    }for(int i=1; i<=k; i++) cin>>money[i];
    int cnt=0;
    for(int i=1; i<=k; i++){
        if(visited[i])continue;
        visited[i]=1;
        int tp1=0, tp2=0;
        queue<pii> dfs;
        dfs.push({i, 1});
        while(!dfs.empty()){
            pii tmp=dfs.front();dfs.pop();
            for(int x:adj[tmp.ff]){
                if(visited[x]) continue;
                visited[x]=tmp.ss^3;
                if(visited[x]==1) tp1+=money[x];
                else tp2+=money[x];
                dfs.push({x, visited[x]});
            }
        }cnt+=max(tp1, tp2);

    }cout<<cnt;

    return 0;
}
