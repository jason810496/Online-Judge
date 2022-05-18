#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5+5;
/*
AC tree DFS ( similar to B-tree )
*/

int n , m ,n2;
vector<int> W;
vector<int> items; // before : Wt , After : box num
pair<int,int> G[N];
// init weight
void DFS(int cur,int par){
    if( n<= cur && cur < n2) return; // to base

    int L=0,R=0,l=G[cur].F,r=G[cur].S;

    if(l >0 ){
        DFS(l, cur);
        L=W[l];
    }

    if(r >0 ){
        DFS(r,cur);
        R=W[r];
    }

    W[cur]+=L+R;
}
// insert
int id;
void Insert(int cur,int wt){
    if( n<= cur && cur < n2){
        items[id]=cur;
        return ; 
    }

    int l=G[cur].F,r=G[cur].S;

    if(W[l]<=W[r]){
        W[l]+=wt;
        Insert(l,wt);   
    }
    else{
        W[r]+=wt;
        Insert(r,wt);
    }
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>m;
    n2=n*2;
    W.resize(n2);
    items.resize(m);
    for(int i=n;i<n2;i++) cin>>W[i];
    for(auto &i:items) cin>>i;
    for(int p,s,t,i=1;i<n;i++){
        cin>>p>>s>>t;
        G[p].first =s;
        G[p].second=t;
    }
    // init
    DFS(1,0);

    for(int i=0;i<m;i++){
        id=i;
        Insert(1,items[i]);
    }

    for(auto i:items) cout<<i<<' ';
    return 0;
}