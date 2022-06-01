#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define ll long long 
#define all(x) x.begin(),x.end()
const int INF = 1e9;
const int N = 1e5+5;

int n;
vector< vector<int> > G;
bitset<N> vis=0;
signed main(){
    OAO 
    cin>>n;
    G.resize(n);
    for(int i=1 , u , v;i<n;i++){
        cin>>u>>v;
        G[u].push_back( v) ;
        G[v].push_back( u );
    }

    int last=0;
    queue<int> q;
    q.push(0);

    while( q.size() ){
        int cur = q.front();
        q.pop();

        vis[cur]=1;
        last = cur;

        for(int nxt : G[cur] ){
            if( !vis[nxt] ){
                q.push( nxt );
            }
        }
    }

    vis=0;
    vector<int> dis(n,0);

    dis[last]=1;
    q.push( last );

    while( q.size() ){
        int cur = q.front();
        q.pop();

        vis[cur]=1;
        last = cur;

        for(int nxt : G[cur] ){
            if(!vis[nxt]){
                q.push(nxt);
                dis[nxt] = dis[cur]+1;
            }
        }
    }
    
    cout<<dis[last]-1;
    return 0;
}