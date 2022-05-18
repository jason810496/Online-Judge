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
const int MAX_N = 100005;
const int INF = 1e9;

short From[3005][3005]={};
/*
same 1
i-1  2
j-1  3
*/
int dp[3005][3005]={};
signed main(){
    OAO
    int n ,m;
    string A,B;
    cin>>A>>B;
    n=A.size() , m=B.size();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                From[i][j]=1;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                dp[i][j]=dp[i-1][j];
                From[i][j]=2;
            }
            else{
                dp[i][j]=dp[i][j-1];
                From[i][j]=3;
            }
        }
    }

    int I=n,J=m;
    string ans;
    while(I && J){
        if(From[I][J]==1){
            ans.push_back(A[I-1]);
            I--,J--;
        }
        else if(From[I][J]==2) I--;
        else J--;
    }
    for(auto i=ans.rbegin();i!=ans.rend();i++){
        cout<<*i;
    }
    return 0;
}