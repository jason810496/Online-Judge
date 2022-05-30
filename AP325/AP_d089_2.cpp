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

int TSP(int Set ,int cur ){
    if( dp[Set][cur] >=0 ) return dp[Set][cur];

    dp[Set][cur] = INF;

    for(int i=0 ; i<n ; i++ ){
        if( i!=cur && (Set&(1<<i) ) ){
            dp[Set][cur] = min( dp[Set][cur] , TSP( Set^(1<<cur) , i ) + Dis[i][cur] );
        }
    }

    return dp[Set][cur];
}

int main(){
    OAO

    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>Dis[i][j];
    }

    memset( dp , -1 , sizeof( dp ) );

    for(int i=0;i<n;i++){
        dp[ 1<<i ][ i ] = Dis[i][m];
    }

    cout<<TSP( (1<<n)-1 , m );
   
    return 0;
}