#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
// adj matrix -> bad alloc
// adj list AC
int ans=0,n;
vector<int> pos;
vector<pii> G[50005];

bitset<50005> visited;

void DFS(int u){
    // cout<<u<<' ';
    pos.push_back(u);

    for(auto v:G[u]){
        if(visited[v.F]) continue;
        visited[v.F]=1;
        ans+=v.S;
        DFS(v.F);
        pos.push_back(u);
        ans+=v.S;
    }
    
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int u,v,w; cin>>n;
    // G.resize(n,vector<int>(n,-1));
    
    for(int i=1;i<n;i++){
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    
    for(int i=0;i<n;i++) sort(G[i].begin(),G[i].end());

    visited[0]=1;
    DFS(0);
    cout<<ans<<'\n';
    for(auto i:pos) cout<<i<<' ';
    return 0;
}