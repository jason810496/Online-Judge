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
const int MAX_N = 20005;
const int INF = 1e9;

/*
    DFS AC

*/
vector<int> G[MAX_N];
int n,MAX=1,node=1;
int DFS(int cur,int par){
    int child=0,ans=0,cur_size=0;
    for(const int v:G[cur]){
        if( v== par ) continue;
        cur_size=DFS(v,cur);
        ans+=child*cur_size;

        child+=cur_size;
    }
    ans+=child*(n-child-1);
    //MAX=max(MAX,ans);
    if(ans>MAX) MAX=ans,node=cur;
    else if(ans==MAX) node=min(node,cur);
    ++child; // itself
    //cout<<"node : "<<cur<<" , ans :"<<ans<<" Size :"<<child<<'\n';
    return child;
}
int main(){
    OAO
    int u,v; cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        G[u].PB(v);
        G[v].PB(u);
    }

    DFS(1,1);
    cout<<node<<" "<<MAX;
    return 0;
}