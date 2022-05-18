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
const int MAX_N = 100005;
const int INF = 1e9;

int Dis[MAX_N]={},indeg[MAX_N]={};
vector<int> G[MAX_N]; 
signed main(){
    OAO
    int n,m,x,y,Mx=0;
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        G[x].PB(y);
        indeg[y]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indeg[i]){
            q.push(i);
            Dis[i]=0;
        }
    }

    while(!q.empty() ){
        int u=q.front();
        q.pop();

        for(int v:G[u]){
            Dis[v]=max(Dis[v],Dis[u]+1);
            Mx=max(Mx,Dis[v]);
            if(--indeg[v]==0){
                q.push(v);
            }
        }
    }
    cout<<Mx;
    return 0;
}