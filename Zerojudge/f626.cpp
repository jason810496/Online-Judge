
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
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
const int MAX_N = 1e4+5;
const int INF = 1e9;

signed main(){
    OAO
    
    int  n , k , r , ans=0; 
    cin>>n>>k>>r;

    priority_queue< pii ,vector<pii> > MX;
    priority_queue< pii , vector<pii> , greater<pii> > MN;

    vector<int> arr(n);

    for(int &i:arr) cin>>i;
    
    for(int i=0;i<k;i++){
        MX.push( { arr[i] , i} );
        MN.push( { arr[i] , i} );
    }

    if( MX.top().F - MN.top().F <= r ) ans++;

    for(int i=k;i<n;i++){
        MX.push( {arr[i] , i} );
        MN.push( {arr[i] , i} );

        while( MX.size() && (i-MX.top().S)>=k ) MX.pop();
        while( MN.size() && (i-MN.top().S)>=k ) MN.pop();

        if( MX.top().F - MN.top().F <=r ){
            // cout<<MX.top().F<<' '<<MX.top().S<<'\n';
            // cout<<MN.top().F<<' '<<MN.top().S<<'\n';
            ans++;
        }
    }

    cout<<ans;
    return 0;
}