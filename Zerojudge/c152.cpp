#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<float,int> pfi;
#define INF 0x7f7f7f7f
#define MAX_N 100005
#define F first
#define S second
vector<pii> graph_dis[MAX_N];
vector<pfi> graph_time[MAX_N];
vector<int> Dis;
vector<int> Last_visit;
vector<float> Time;
bitset<MAX_N> visited;
int Start,To,N,M,ans2,Mat[MAX_N][MAX_N];
void init(int N){
    for(int i=1;i<=N;i++){
        graph_dis[i].clear();
        graph_time[i].clear();
    }
    visited=0;
    Dis.resize(N+1,INF);
    Last_visit.resize(N+1,-1);
    Time.resize(N+1,FLT_MAX);
}
int DFS(int u){
    cout<<"t"<<Last_visit[u]<<' '<<u<<' '<<Mat[u][Last_visit[u]]<<'\n';
    if(u==Last_visit[u]) return 0;
    return (DFS(Last_visit[u])+Mat[u][Last_visit[u]]);
}
void slove(){
    float t;
    cin>>N>>M>>Start>>To;
    init(N);
    for(int i=0,u,v,dis,V;i<M;i++){
        cin>>u>>v>>dis>>V;
        t=float(dis)/float(V);
        Mat[u][v]=Mat[v][u]=dis;
        graph_time[u].push_back({t,v});
        graph_time[v].push_back({t,u});
        graph_dis[u].push_back({dis,v});
        graph_dis[v].push_back({dis,u});
        //cout<<u<<' '<<v<<':'<<graph_dis[u][v].F<<graph_dis[v][u].F<<'\n';
    }
 

    //Time
    priority_queue<pfi,vector<pfi>,greater<pfi> > pq2;
    pq2.push({0,Start});
    Time[Start]=0;
    Last_visit[Start]=Start;
    while(pq2.size()){
        int u=pq2.top().S,v;
        float weight,d=pq2.top().F;
        pq2.pop();
        if(Time[u]<d) continue; 
        for(auto &i:graph_time[u]){
            weight=i.F,v=i.S;
            if(Time[v] > Time[u] + weight){
                Time[v]=Time[u]+weight;
                Last_visit[v]=u;
                if(v==To) continue;
                pq2.push({Time[v],v});
            }
        }
    }
    ans2=DFS(To);
    for(int i=1;i<=N;i++){
        cout<<Last_visit[i]<<' ';
    }
    cout<<'\n';
     //Dis
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,Start});
    Dis[Start]=0;
    while(pq.size()){
        int u=pq.top().S,d=pq.top().F,weight,v;
        pq.pop();
        if(Dis[u]<d) continue;
        for(auto &i:graph_dis[u]){
            weight=i.F,v=i.S;
            if(Dis[v] > Dis[u] + weight){
                Dis[v]= Dis[u]+weight;
                Last_visit[v]=u;
                pq.push({Dis[v],v});
            }
        }
    }
    for(int i=1;i<=N;i++){
        cout<<Last_visit[i]<<' ';
    }
    cout<<'\n';
    cout<<Dis[To]<<' '<<ans2<<'\n';
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        slove();
    }
    return 0;
}
/*
1
5 5
1 5
1 2 1 1
2 3 1 1
3 4 1 1
4 5 1 1
5 1 10 1
*/
/*
5 5
1 5
1 2 1 1
2 3 1 1
3 4 1 1
4 5 1 1
1 5 10 1000
*/