#include<bits/stdc++.h>
using namespace std;
#define S second
#define F first
/*
shortest path dijkstra AC

*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int> > > G(n);
    vector<int> Dis(n,INT_MAX);
    int MAX=0,cnt=n;

    for(int i=0,u,v,w;i<m;i++){
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
        // first next , second weight
    }

    priority_queue< int, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    // first dis , second node
    Dis[0]=0; 
    pq.push({0,0});

    while(pq.size() ){
        int D=pq.top().first;
        int U=pq.top().second;
        pq.pop();

        if( Dis[U] < D ) continue;
        for(auto I:G[U]){
            int V=I.F , W=I.S;
            if(Dis[V] > Dis[U] + W ){
                Dis[V]= Dis[U] + W;
                pq.push({Dis[V],V});
            }
        }
    }

    for(int i=0;i<n;i++){
        if(Dis[i]!=INT_MAX){
            cnt--;
            MAX=max(MAX,Dis[i]);
        }
    }

    // for(int i=0;i<n;i++){
    //     cout<<Dis[i]<<' ';
    // }
    // cout<<'\n';
    cout<<MAX<<'\n'<<cnt;
    return 0;
}