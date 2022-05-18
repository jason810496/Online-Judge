/*
 ██████╗ ██████╗ ██████╗ ███████╗     ██████╗ ██╗   ██╗████████╗
██╔════╝██╔═══██╗██╔══██╗██╔════╝    ██╔═══██╗██║   ██║╚══██╔══╝
██║     ██║   ██║██║  ██║█████╗      ██║   ██║██║   ██║   ██║   
██║     ██║   ██║██║  ██║██╔══╝      ██║   ██║██║   ██║   ██║   
╚██████╗╚██████╔╝██████╔╝███████╗    ╚██████╔╝╚██████╔╝   ██║   
 ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝     ╚═════╝  ╚═════╝    ╚═╝   
                                                                
 █████╗  ██████╗    ██╗███╗   ██╗                               
██╔══██╗██╔════╝    ██║████╗  ██║                               
███████║██║         ██║██╔██╗ ██║                               
██╔══██║██║         ██║██║╚██╗██║                               
██║  ██║╚██████╗    ██║██║ ╚████║                               
╚═╝  ╚═╝ ╚═════╝    ╚═╝╚═╝  ╚═══╝                                                                                                                                                                            
*/
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
const int MAX_N = 1e6+5;
const int INF = 1e9;
/*
    TOI exe
    Topological sort
    AC
*/
vector<int> G[MAX_N];
int indeg[MAX_N]={},outdeg[MAX_N]={},Dis[MAX_N]={},n,m;
int main(){
    OAO 
    cin>>n>>m;
    int u,v;
    while(m--){
        cin>>u>>v;
        G[u].PB(v);
        indeg[v]++;
        outdeg[u]++;
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(!indeg[i]) q.push(i);
    }

    while( q.size() ){
        u=q.front();
        q.pop();

        for(const int &v:G[u]){
            Dis[v]+=(Dis[u]==0 ? 1:Dis[u]);
            if(--indeg[v]==0){
                q.push(v);
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        if(!outdeg[i]) ans+=Dis[i];
    }
    cout<<ans;
    return 0;
}