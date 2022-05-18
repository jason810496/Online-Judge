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

int main(){
    OAO
    int t,n,m; cin>>t;
    ll dp[105][105];
    string str;
    while(t--){
        MEM(dp,0);
        cin>>n>>m;
        getchar();
        for(int i=1,x,r;i<=n;i++){
            getline(cin,str);
            stringstream ss(str);
            ss>>r;
            while(ss>>x){
                dp[r][x]=-1;
            }
        }
        getchar();

        if(dp[n][m]==-1 || dp[1][1]==-1){
            cout<<"0\n\n";
            continue;
        }
        dp[1][1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1,sum;j<=m;j++){
                if(dp[i][j]==-1) continue;
                sum=0;
                if(dp[i-1][j]!=-1) sum+=dp[i-1][j];
                if(dp[i][j-1]!=-1) sum+=dp[i][j-1];
                dp[i][j]+=sum;
            }
        }
        
        if(dp[n][m]>0){
            cout<<dp[n][m]<<"\n\n";
        }
        else cout<<"0\n\n";
    }
    return 0;
}