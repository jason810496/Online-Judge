
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

struct Cmp {
    bool operator()(const pair<int, int>& value,const int& key){
        return (value.first < key);
    }
    bool operator()(const int& key,const pair<int, int>& value){
        return (key < value.first);
    }
};
signed main(){
    OAO

    int n ,q ; cin>>n>>q;

    vector<pii> Drink(n);
    
    for(auto &i:Drink){
        // Pos , Val
        cin>>i.S>>i.F;
    }
    // F:val  ,S:pos
    sort(range(Drink));

    while(q--){
        int Pos , Val; cin>>Pos>>Val ;

        auto it = lower_bound(range(Drink),Val,Cmp() );

        if(it==Drink.end()){
            cout<<"-1\n";
            continue;
        }

        int Dis = INF ,ans,cur;  

        for(;it!=Drink.end();it++){
            cur = abs(it->S-Pos);
            if( Dis <=  cur) break;
            Dis = cur;
            ans = it->S;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
