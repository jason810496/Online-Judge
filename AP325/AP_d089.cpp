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

const int N = 17;

int n ,m ;
int Dis[N][N] , dp[1<<N][N];

int main(){
    OAO

    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>Dis[i][j];
    }

    for(int i=0;i<(1<<n); i++){
        fill( dp[i] , dp[i]+n , INF );
    }

    // bit: 1111111.....1111
    int Set = (1<<n)-1;

    // base: start point
    dp[Set][0] = 0;

    for( Set=(1<<n)-2 ; Set>=0 ; Set-- ){
        for(int v=0;v<n;v++){
            for(int u=0;u<n;u++){
                if( !(Set&(1<<u)) ){
                    dp[Set][v] = min( dp[Set][v] , dp[Set | (1<<u)][u] + Dis[u][v] );
                }
            }
        }
    }

    cout<<dp[0][0];
   
    return 0;
}