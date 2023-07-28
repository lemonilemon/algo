
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
#define int long long
signed main(){_
    
    int cnt=0;
    int n;cin>>n;
    vector<int> li(n+1, 1);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1) break;
            if(i*i*j>n) break;
            cnt+=li[i*i*j];

        }
    if(!li[i]) continue;
        int t=sqrt(n/i);
    //li[i*i]=0;
    //cnt+=i*((t*(t+1)*(2*t+1))/6);
    }cout<<cnt;
    //for(int i=0; i<n; i++) cout<<li[i]<<' ';
    return 0;
}
