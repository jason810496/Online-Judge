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

/*
    sprout OJ topological sort
    (with min dic)
*/
int n,m,u,v,indeg[MAX_N]={};
vector<int> G[MAX_N];
int main(){
    OAO
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++) G[i].clear();
        MEM(indeg,0);
        while(m--){
            cin>>u>>v;
            G[u].PB(v);
            indeg[v]++;
        }

        priority_queue<int,vector<int>,greater<int> > pq;

        for(int i=0;i<n;i++){
            if(!indeg[i]){
                pq.push(i);
            }
        }

        vector<int> order;
        while(pq.size() ){
            order.PB(pq.top());
            pq.pop();
            int u=order.back();

            for(const int v:G[u]){
                if(--indeg[v]==0){
                    pq.push(v);
                }
            }
        }

        if(order.size() == n){
            for(int i=0,N=order.size();i<N-1;i++){
                cout<<order[i]<<' ';
            }
            cout<<order.back()<<'\n';
        }
        else{
            cout<<"QAQ\n";
            
        }
    }
    
    return 0;
}