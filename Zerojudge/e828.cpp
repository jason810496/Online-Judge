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
const int MAX_N = 1e4+5;
const int INF = 1e9;

int dp[MAX_N][MAX_N]={};
int main(){
    OAO
    string target,arr[4];
    cin>>target;
    int Dis=INF,n=target.size(),m,ans=1;
    for(int k=1;k<=3;k++){
        cin>>arr[k];
    }

    for(int k=1;k<=3;k++){
        m=arr[k].size();

        // for(int i=0;(i<=n || i<=m);i++){
        //     dp[i][0]=dp[0][i]=i*2;
        // }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0) dp[i][j]=j*2;
                else if(j==0) dp[i][j]=i*2;
                else if(target[i-1]==arr[k][j-1]){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j]+2 ,dp[i][j-1]+2));
                }
                else {
                    dp[i][j]=min(dp[i-1][j-1]+3, min(dp[i-1][j]+2,dp[i][j-1]+2 ));
                }
            }
        }

        if(dp[n][m]<=Dis){
            Dis=dp[n][m];
            ans=k;
        }
    }
    cout<<ans<<' '<<Dis;
    return 0;
}