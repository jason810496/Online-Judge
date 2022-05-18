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
typedef pair<int,int> pii;
const int MAX_N = 55;
const int INF = 1e9;

/*
    DP LCS (back trading)
    AC
*/
int main(){
    OAO
    int dp[MAX_N][MAX_N]={},From[MAX_N][MAX_N]={};
    string s1,s2;
    int n,m;
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();

    // 3-> i-1,j-1
    // 2-> i-1,j
    // 1-> i  ,j-1
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                From[i][j]=3;
            }
            else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j]=dp[i-1][j];
                From[i][j]=2;
            }
            else{
                dp[i][j]=dp[i][j-1];
                From[i][j]=1;
            }
        }
    }

    if( !dp[n][m]) cout<<"E";
    else{
        int I=n,J=m;
        string ans;
        while(I!=0 && J!=0){
            if(From[I][J]==3){
                ans.push_back(s1[I-1]);
                I--,J--;
            }
            else if(From[I][J]==2){
                I--;
            }
            else J--;
        }

        for(auto it=ans.rbegin();it!=ans.rend();it++){
            cout<<(*it);
        }
    }
    return 0;
}