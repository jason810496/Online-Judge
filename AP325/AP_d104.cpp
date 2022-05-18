#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N=1e5+5;
/*
Tree centroid ?
Hard

AC

*/
int n,u,w;
vector<pii > G[N];

int Mid=-1 ;
long long Sum=0 , Size[N];
void DFS(int u){
    for(auto i: G[u]){
        int v=i.F , w=i.S;
        DFS(v);
        Sum+=min(Size[v] ,n-Size[v]) * w;
        Size[u]+=Size[v];
    }
    Size[u]++;

    if(Mid<0 &&Size[u]>=n/2 ) Mid=u;

    return ;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>w;
        G[u].push_back({i,w});
    }

    DFS(0);
    cout<<Mid<<'\n'<<Sum;
    return 0;
}