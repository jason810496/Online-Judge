/*
 ██████╗ ██████╗ ██████╗ ███████╗     ██████╗ ██╗   ██╗████████╗
██╔════╝██╔═══██╗██╔══██╗██╔════╝    ██╔═══██╗██║   ██║╚══██╔══╝
██║     ██║   ██║██║  ██║█████╗      ██║   ██║██║   ██║   ██║   
██║     ██║   ██║██║  ██║██╔══╝      ██║   ██║██║   ██║   ██║   
╚██████╗╚██████╔╝██████╔╝███████╗    ╚██████╔╝╚██████╔╝   ██║   
 ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝     ╚═════╝  ╚═════╝    ╚═╝   
                                                                
 █████╗  ██████╗    ██╗███╗   ██╗                               
██╔══██╗██╔════╝    ██║████╗  ██║                               
███████║██║         ██║██╔██╗ ██║                               
██╔══██║██║         ██║██║╚██╗██║                               
██║  ██║╚██████╗    ██║██║ ╚████║                               
╚═╝  ╚═╝ ╚═════╝    ╚═╝╚═╝  ╚═══╝                                                                                                                                                                            
*/
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
const int MAX_N = 1e6+5;
const int INF = 1e9;

/*
    DP NAN
    unfinished

*/
int n,m,arr[55][55],dp[55][55]={},dp2[55][55]={};;
bool From[55][55]={};
int main(){
    OAO
    cin>>n>>m;
    bool vis[55][55]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>arr[i][j];
    }

    const int I=1,J=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i-1][j]>=dp[i][j-1]){
                From[i][j]=I;
                dp[i][j]=dp[i-1][j]+arr[i][j];
            }
            else{
                From[i][j]=J;
                dp[i][j]=dp[i][j-1]+arr[i][j];
            }
        }
    }

    int II=n,JJ=m;
    ans+=dp[n][m];
    while(II&&JJ){
        vis[II][JJ]=1;
        if(From[II][JJ]) II--;
        else JJ--;
    }
    vis[1][1]=vis[n][m]=0;

    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(vis[i][j]) continue;
            if(dp2[i+1][j]>=dp2[i][j+1]){
                dp2[i][j]=dp2[i+1][j]+arr[i][j];
            }
            else{
                dp2[i][j]=dp2[i][j+1]+arr[i][j];
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dp2[i][j]<<' ';
        }
        cout<<'\n';
    }

    cout<<ans+dp2[1][1];

    return 0;
}