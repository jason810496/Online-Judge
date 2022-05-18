#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end(
#define MEM(x,i) memset(x,0,sizeof(x))
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
    AC
    DFS ( queen problem)

*/
int n,G[15][15],MAX=0;
bool RC[30],pos[30],neg[30];
// row : i
// col : n+j
// (i,j) i*n+j
// / i+j : pos
// \ n+i-j : neg

void DFS(int i,int sum){
    if(i==n) return ;
    DFS(i+1,sum);
    for(int j=0,val;j<n;j++){
        if(RC[n+j]||pos[i+j]||neg[n+i-j]) continue;
        RC[n+j]=1;
        pos[i+j]=1;
        neg[n+i-j]=1;
        val = sum+G[i][j];
        MAX=max(MAX,val);
        DFS(i+1,val);
        RC[n+j]=0;
        pos[i+j]=0;
        neg[n+i-j]=0;
    }
}
int main(){
    OAO
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>G[i][j];
        }
    }
    DFS(0,0);

    cout<<MAX;
    return 0;
}