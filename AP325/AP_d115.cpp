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
const int MAX_N = 50005;
const int INF = 1e9;

int Size[MAX_N] ,Wt[MAX_N], n ;
vector<pii> G[MAX_N]; // F:node , S:wt
int Center=-1;

void Get_Center(int cur,int par){
    Size[cur]=1;
    Wt[cur]=0;

    for(pii i:G[cur]){
        if(i.F == par ) continue;
        Get_Center(i.F,cur);
        Size[cur]+=Size[i.F];
        Wt[cur]=max(Wt[cur],Size[i.F]);
    }
    Wt[cur]=max(Wt[cur] , n-Size[cur]);

    if( Wt[cur]<=n/2 ) Center=cur;
}

int DFS(int cur,int par){
    int res=0,edge=0;
    Size[cur]=1;
    for(pii nxt:G[cur]){
        if(nxt.F==par) continue;
		DFS(nxt.F,cur);
        edge+=nxt.S*Size[nxt.F];
        Size[cur]+=Size[nxt.F];
    }
    return edge*Size[cur];
}
signed main(){
    OAO
    cin>>n;
    int a,b,w;
    for(int i=1;i<n;i++){
        cin>>a>>b>>w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }
    Get_Center(0,0);
    //cout<<Center;
    cout<<DFS(Center,-1);
    return 0;
}
