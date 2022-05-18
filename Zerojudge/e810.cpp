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
const int MAX_N = 505;
const int INF = 1e9;


/*
    TOI exe
    kind of shortest path ?
    similar to Dijkstra's
    AC
    (DFS : WA)
*/
// F :wt , S:node
vector<pii> G[MAX_N];
vector<int> Dis(MAX_N,INF);
int n, m ,u,v,w , st, ed;

int main(){
    OAO 
    cin>>n>>m;

    while(m--){
        cin>>u>>v>>w;
        G[u].PB(make_pair(w,v));
        G[v].PB(make_pair(w,u));
    }
    cin>>st>>ed;

    queue<int> q;
    q.push(st);
    Dis[st]=0;
    while( !q.empty() ){
        int cur=q.front();
        q.pop();

        for(auto nxt:G[cur]){
            int Mx=max(nxt.F,Dis[cur]);

            if(Dis[nxt.S] > Mx){
                Dis[nxt.S]=Mx;
                q.push(nxt.S);
            }
        }
    }

    cout<<(Dis[ed]==INF ? -1:Dis[ed]);
    return 0;
}