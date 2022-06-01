#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define ll long long 
#define all(x) x.begin(),x.end()
const int INF = 1e9;
const int N = 1e5+5;

/*
    Tree DP
*/

int n;
vector< vector<int> > G;
vector<int> Wt ,dp;

int DFS(int cur,int par){

    int self = Wt[ cur ] , child = INF ;

    for(int nxt : G[ cur ] ){
        if( nxt == par ) continue;
        child = min( child , DFS( nxt ,cur) );
    } 

    return dp[ cur ] = min( self , child );
}

signed main(){
    OAO 
    cin>>n;
    G.resize(n);
    Wt.resize(n);
    dp.resize(n);

    for(auto &i:Wt) cin>>i;
    for(int i=1 , u , v;i<n;i++){
        cin>>u>>v;
        --u , --v;
        G[ u ].push_back( v );
        G[ v ].push_back( u );
    }

    cout<<DFS(0,-1);

    return 0;
}