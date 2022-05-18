#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 2e5+5;
map<int,int> Col;
vector<int> W; // color of each vertex
vector<int> G[N];
int MAX=1;
/*
DFS -> segmentation fault ? ?

change DFS detail -> AC ??
*/
void DFS(int cur){
    Col[ W[cur] ]++;
    MAX=max(MAX,Col[ W[cur] ] );

    for(int v: G[cur]){
        DFS(v);
       
    }

    Col[ W[cur] ]--;
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n;
    W.resize(n);

    for(auto &i:W){
        cin>>i;
        if(Col.find(i)==Col.end() ){
            Col[i]=0;
        }
    }

    for(int i=1,s,t;i<n;i++){
        cin>>s>>t;
        G[s].push_back(t);
    }

    DFS(0);

    cout<<MAX;

    return 0;
}