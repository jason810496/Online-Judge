#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end(
#define MEM(x,i) memset(x,0,sizeof(x))
typedef pair<int,int> pii;
const int MAX_N = 1e9+5;
const int INF = 1e9;
/*
inline bool comp(int a,int b){
    return a>b;
}

struct comparator{
    bool operator() (const int &a,const int &b){
        return a>b;
    }
};

*/

/*
    AC but kind if brute force ? ?

*/

int G[55][55],u,v,w;
bool edge[55][55];
int main(){
    OAO
    int n,Wt,Time,q,Total=0;
    MEM(G,0);
    cin>>n>>Wt>>Time>>q;
    while(q--){
        cin>>u>>v>>w;
        Total+=w;
        edge[u][v]=1;
        edge[v][u]=1;
        G[u][v]=w;
        G[v][u]=w;
    }

    int cur=1,nxt,cur_wt=0,sum=0;
    while(Time-- ){
        cur_wt=0;
        
        for(int i=1;i<=n;i++){
            if(i==cur) continue;
            if(G[cur][i]>cur_wt){
                cur_wt=G[cur][i];
                nxt=i;
            }
        }

        if(cur_wt==0){
            vector<bool > visited(n+5);
            vector<int> Time_dis(n+5);
            visited[cur]=1;
            Time_dis[cur]=0;
            queue<int> q;
            q.push(cur);
            int node=-1;
            while(q.size() && node==-1 ){
                u=q.front();
                q.pop();
                
                for(int v=1;v<=n;v++){
                    if(visited[v]) continue;
                    if(edge[u][v]){
                        if(G[u][v]>0){
                            node=u;
                            break;
                        }
                        Time_dis[v]=Time_dis[u]+1;
                        visited[v]=1;
                        q.push(v);
                    }
                }
            }
            
            if(node>0){
                cur=node;
                Time++;
                Time-=Time_dis[node];
                continue;
            }
            else{
                break;
            }
        }
        if(cur_wt>Wt){
            sum+=Wt;
            G[cur][nxt]-=Wt;
            G[nxt][cur]-=Wt;
        }
        else{
            sum+=cur_wt;
            G[cur][nxt]=0;
            G[nxt][cur]=0;
        }

        cur=nxt;
    }   

    cout<<sum<<'\n';

    return 0;
}