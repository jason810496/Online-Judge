#include<iostream>
#define N 205
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    ll DP[N][N];
    int arr[N][N],n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>DP[i][j];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1) DP[i][j]+=DP[i][j-1];
            else if(j==1) DP[i][j]+=DP[i-1][j];
            else{
                DP[i][j]+=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<DP[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<DP[n][m];

    return 0;
}