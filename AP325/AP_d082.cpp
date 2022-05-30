#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define N 26
int Prefix[N][N],DP[N][N][N][N];
int n , m;

const int INF = 1e9 ;

int Sum(int i1,int j1,int i2,int j2){
    i1--;
    j1--;
    int One = (Prefix[i2][j2]-Prefix[i2][j1]-Prefix[i1][j2]+Prefix[i1][j1]);
    int Size = (i2-i1)*(j2-j1);
    return min( One , Size-One );
}

// 
int dp(int i1,int j1,int i2,int j2){
    if( DP[i1][j1][i2][j2]>=0 ) return DP[i1][j1][i2][j2];
    if( i1==i2 || j1==j2 ) return DP[i1][j1][i2][j2]=0 ;
    int Mn = INF ; 

    Mn = min( Mn , dp(i1+1 , j1  , i2  , j2  ) +Sum(i1 , j1 , i1 ,j2 ) );
    Mn = min( Mn , dp(i1   , j1+1, i2  , j2  ) +Sum(i1 , j1 , i2 ,j1 ) );
    Mn = min( Mn , dp(i1   , j1  , i2-1, j2  ) +Sum(i2 , j1 , i2 ,j2 ) );
    Mn = min( Mn , dp(i1   , j1  , i2  , j2-1) +Sum(i1 , j2 , i2 ,j2 ) );

    return DP[i1][j1][i2][j2] = Mn;
}

signed main(){
    OAO 

    memset(DP,-1,sizeof(DP) );

    cin>>n>>m;

    for(int i=0;i<=n;i++){
        for(int j=0 ,x ,sum=0;j<=m;j++){
            if( i==0 || j==0){
                Prefix[i][j]=0;
                continue;
            }

            cin>>x;
            sum+=x;
            Prefix[i][j] = sum + Prefix[i-1][j];
        }
    }

    cout<<dp(1,1,n,m);
    return 0;
}