#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,0,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
typedef pair<int,int> pii;
const int MAX_N = 20005;
const int INF = 1e9;
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

int Time=0,n,Dfn[MAX_N],Low[MAX_N],Size[MAX_N],MAX_Size=0;
vector<int> G[MAX_N] ;
vector<pii> edge;
void DFS(int u,int pa){
    Dfn[u] = Low[u] = Time++;
    Size[u]=1;
    int child=0;

    bool isAP = false;

    for(int v:G[u]){
        if( v==pa) continue ;
        if( !Dfn[v] ){
            DFS(v,u);
            Size[u]+=Size[v];
            child++;
            Low[u] = min(Low[u], Dfn[v]);
        }
        else Low[u]=min(Low[u],Dfn[v]);
        if( Dfn[u]< Low[v] ){
            edge.push_back({u,v});
        }

    }
}

int main(){
    OAO
    int u,v,m; 
    cin>>n>>m;

    while(m--){
        cin>>u>>v;
        u++;
        v++;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    DFS(1,1);

    for(const auto &e:edge){
        MAX_Size=max( MAX_Size , Size[e.F]*(n-Size[e.F]));
    }
    cout<<MAX_Size;
    return 0;
}