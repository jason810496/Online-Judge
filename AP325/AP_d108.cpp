#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
#define ll long long 
/*
Tree hard

*/

int n,W[N],Child[N];
vector<int> G[N];
ll ans=0;

void DFS(int cur){
    
    for(int v: G[cur]){
        DFS(v);
        Child[cur]+=Child[v];
    }
    Child[cur]++;
}
void Dis(int cur){

    for(int v:G[cur]){
        ans+= (ll)2* (ll)Child[v]* (ll)(n-Child[v])* (ll)W[v];
        // cout<<v<<' '<<W[v]<<'\n';
        Dis(v);
    }
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=2,p;i<=n;i++){
        cin>>p;
        G[p].push_back(i);
    }
    for(int i=2;i<=n;i++) cin>>W[i];

    DFS(1);
    Dis(1);
    cout<<ans;

    return 0;
}