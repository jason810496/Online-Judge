
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 1e4+5;
const int INF = 1e9;

signed main(){
    // OAO
    
    int n , m , x1 ,y1 ,x2 ,y2;
    cin>>n>>m>>x1>>y1>>x2>>y2;

    vector< vector< char> > G(n, vector<char>(m) );

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>G[i][j];
        }
    }
    x1--;
    y1--;
    x2--;
    y2--;
    

    int dx1 = x2-x1  , dy1 =y2-y1;
    int dx2 = abs(x2-x1) , dy2 = abs(y2-y1);
    int vx = ( (dx1==0 || dx2==0) ? 0: dx1/dx2) ;
    int vy = ( (dy1==0 || dy2==0) ? 0: dy1/dy2) ;

    while( x1!=x2 || y1!=y2 ){

        // cout<<x1<<' '<<y1<<'\n';
        cout<<G[x1][y1];

        
        if(x1!=x2) x1+=vx;
        if(y1!=y2) y1+=vy;
    }
    cout<<G[x2][y2];
    return 0;
}