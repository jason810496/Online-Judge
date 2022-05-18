#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first //node
#define S second // weight
// Tree DFS AC

const int N=1e5+5;
int n,v,w;
vector<pii> G[N];

pii DFS(int u){
                             // node, weight
    if(!G[u].size()) return {1 , 0};

    pii ret={0,0};
    for(auto v: G[u]){
        pii temp= DFS(v.F);
        ret.F=max(ret.F,temp.F);
        ret.S=max(ret.S,temp.S+v.S);
    }
    ret.F+=1;

    return ret ;
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n;

    for(int i=1;i<n;i++){
        cin>>v>>w;
        G[v].push_back({i,w});
    }
    
    pii temp =DFS(0);

    cout<<temp.S<<'\n'<<temp.F-1;

    return 0;
}