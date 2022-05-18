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
const int MAX_N = 1e3+5;
const int INF = 1e9;

vector<int> G[MAX_N];
int indeg[MAX_N]={};
int main(){
    OAO 
    int n, m,u,v;
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        G[u].PB(v);
        indeg[v]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indeg[i]) q.push(i);
    }

    vector<int> order;
    while(q.size()){
        u=q.front();
        order.PB(u);
        q.pop();

        for(int v:G[u]){
            if(--indeg[v]==0 ) {
                q.push(v);
            }
        }
    }

    if(n==order.size()) {
        cout<<"YES\n";
        for(int i:order) cout<<i<<'\n';
    }
    else{
        cout<<"NO";
    }
    return 0;
}