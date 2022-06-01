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
int val[N] , dp[N] = {};
vector< vector<int> > G;

int DFS(int cur){
    int self = val[cur] , child=0;

    for(int ch : G[cur] ){
        DFS( ch );
        child+=dp[ ch ];
    }

    for(int ch :G[cur] ){
        for(int grand : G[ ch ] ){
            self+=dp[ grand ];
        }
    }

    return dp[cur] = max( self ,child );
}
signed main(){
    OAO 
    cin>>n>>val[1];
    G.resize(n+1);

    for(int i=2;i<=n;i++){
        int p,v;
        cin>>p>>v;
        G[p].push_back( i );
        val[i]=v;
    }

    cout<<DFS(1);
    return 0;
}