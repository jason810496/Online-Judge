#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end(
#define MEM(x,i) memset(x,0,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
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
Recursion AC
*/
int n,m,MIN=1000;
int one,zero;
bool G[15][15];
void DFS(int U,int D,int L,int R,int cost){
    if(L==R||U==D){
        MIN=min(MIN,cost);
        return ;
    }
    // up
    one=0,zero=0;
    for(int j=L;j<=R;j++){
        if(G[U][j]) ++one;
        else ++zero;
    }
    DFS(U+1,D,L,R,cost+min(one,zero));
    // down
    one=0,zero=0;
    for(int j=L;j<=R;j++){
        if(G[D][j]) ++one;
        else ++zero;
    }
    DFS(U,D-1,L,R,cost+min(one,zero));
    // left
    one=0,zero=0;
    for(int i=U;i<=D;i++){
        if(G[i][L]) ++one;
        else ++zero;
    }
    DFS(U,D,L+1,R,cost+min(one,zero));
    //right
    one=0,zero=0;
    for(int i=U;i<=D;i++){
        if(G[i][R]) ++one;
        else ++zero;
    }
    DFS(U,D,L,R-1,cost+min(one,zero));

}
int main(){
    OAO
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>G[i][j];
        }
    }

    DFS(0,n-1,0,m-1,0);
    cout<<MIN;
    return 0;
}