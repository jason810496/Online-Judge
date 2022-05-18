
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #include<utility>
// #include<vector>
// #include<set>
// #include<map>
// #include<vector>
// #include<queue>
// #include<stack>
// #include<string>
// #include<sstream>
// #include<limits>
// #include<math.h>
// #include<unordered_map>
// #include <iomanip>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INF = 1e9;

signed main(){
    OAO

    int n ;cin>>n;
    ll MX=-INF;
    vector<ll> vec(n);
    for(auto &i:vec) cin>>i;

    if(n<2){
        cout<<0;
        return 0;
    }
    sort(range(vec));

    for(int i=1;i<n;i++){
        MX = max(MX , vec[i]-vec[i-1]);
    }

    cout<<MX;
    return 0;
}
