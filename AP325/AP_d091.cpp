#include<bits/stdc++.h>
#define ll long long 
using namespace std;

/*
DFS AC
*/
bool visited[50005];
vector<int> Graph[50005];
vector<int> val;
ll DFS(int u){
    ll ret=val[u];
    for(auto v:Graph[u]){
        if(visited[v]) continue;
        visited[v]=true;
        ret+=DFS(v);
    }
    return ret;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    val.resize(n);
    for(auto &i:val) cin>>i;
    for(int u,v,i=0;i<m;i++){
        cin>>u>>v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    ll MAX=0;
    for(int u=0;u<n;u++){
        if(visited[u]) continue;
        visited[u]=true;

        MAX=max(MAX,DFS(u));
    }
    cout<<MAX;
    return 0;
}