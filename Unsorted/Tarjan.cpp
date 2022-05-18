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

int Time=0,Dfn[MAX_N],Low[MAX_N];
vector<int> G[MAX_N] ;
vector<pii> edge;
vector<int> AP;
void DFS(int u,int pa){
    Dfn[u] = Low[u] = Time++;
    int child=0;

    bool isAP = false;

    for(int v:G[u]){
        if( v==pa) continue ;
        if( !Dfn[v] ){
            DFS(v,u);
            child++;

            if( Dfn[u]<=Low[v]) isAP=true;
            if( Dfn[u]< Low[v] ) edge.push_back({v,u});

            Low[u] = min(Low[u], Dfn[v]);
        }

        Low[u]=min(Low[u],Dfn[v]);
    }

    if( u==pa && child < 2 ) isAP = false;
    if( isAP ) AP.push_back( u );
}

int main(){
    OAO
    int n,u,v; 
    cin>>n;

    for(int i=1;i<n;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    DFS(1,1);

    cout<<"Edge : \n";
    for(const auto &i:edge){
        cout<<i.F<<" "<<i.S<<"\n";
    }

    cout<<"AP : \n";
    for(const int &i:AP){
        cout<<i<<'\n';
    }
    return 0;
}