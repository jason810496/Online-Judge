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
int n,m,wt[MAX_N],indeg[MAX_N]={},dis[MAX_N]={};
vector<int> G[MAX_N];
vector<int> From[MAX_N];
/*
    topological sort + Max path
    AC
*/

int main(){
    OAO

    while(cin>>n>>m){
        // init
        MEM(dis,0);
        MEM(indeg,0);
        for(int i=1;i<=n;i++){
            G[i].clear();
            From[i].clear();
        }

        for(int i=1;i<=n;i++) cin>>wt[i];
        int u,v;
        while(m--){
            cin>>u>>v;
            G[u].PB(v);
            ++indeg[v];
        }

        queue<int> q;

        for(int i=1;i<=n;i++){
            if(indeg[i]==0){ 
                q.push(i);
                dis[i]=wt[i];
            }
        }

        vector<int> End;
        int Mx=1;
        while(q.size() ){
            u=q.front();
            q.pop();
            //order.PB(u);

            for(int v:G[u]){
                
                if(--indeg[v]==0) q.push(v);
                if(dis[v] < dis[u]+wt[v] ){
                    dis[v]= dis[u]+wt[v];
                    //cout<<"upd: "<<v<<' '<<dis[v]<<"\n";
                    From[v].PB(u);

                    if(dis[v]>Mx){
                        End.clear();
                        End.PB(v);
                        Mx=dis[v];
                    }
                    else if(dis[v]==Mx) End.PB(v);
                }
                    
            }
        }
       

        set<int> Set;
        for(const int node : End){
            queue<int> q;
            q.push(node);
            Set.insert(node);
            while(q.size() ){
                u=q.front();
                q.pop();

                for(int v:From[u]){
                    if(dis[u]==(dis[v]+wt[u])){
                        q.push(v);
                        Set.insert(v);
                    }
                }
            }
        }

        // for(auto i:Set){
        //     cout<<i<<' ';
        // }
        cout<<Set.size()<<'\n';
    }
    //cin>>n>>m;
    
    return 0;
}