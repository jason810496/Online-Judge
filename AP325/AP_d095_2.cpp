#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int n, m ,S,T;
vector<vector<pair<int,int> > > G;
vector<int > Min,Max;

int Min_dis(int u){
    if(Min[u]<=INF ) return Min[u];
    Min[u]=INF;

    for(auto v:G[u]){
        Min[u]=min(Min[u], Min_dis(v.first) + v.second);
    }

    return Min[u];
}

int Max_dis(int u){
    if(Max[u]>= -INF) return Max[u];
    Max[u]= -INF;

    for(auto v:G[u]){
        Max[u]=max(Max[u], Max_dis(v.first)+v.second);
    }

    return Max[u];
    
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>m>>S>>T;
    G.resize(n);
    Min.resize(n,INF+1);
    Max.resize(n,-INF-1);

    for(int u,v,w,i=0;i<m;i++){
        cin>>u>>v>>w;
        G[u].push_back({v,w});
    }
    Min[S]=Max[S]=0;
    Min[T]=Min_dis(T);
    Max[T]=Max_dis(T);

    if(Min[T]==INF ) cout<<"No path\nNo path\n";
    else cout<<Min[T]<<'\n'<<Max[T];

    return 0;
}