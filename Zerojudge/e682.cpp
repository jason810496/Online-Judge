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
    DP LCS AC
    Back trading
*/

int main(){
    OAO
    string str;
    vector<string > S1,S2;
    while(cin>>str){
        S1.clear();
        S2.clear();
        S1.PB(str);
        while(cin>>str && str!="#"){
            S1.PB(str);
        }
        while(cin>>str && str!="#"){
            S2.PB(str);
        }
        int n=S1.size()  , m=S2.size(),dp[105][105]={},From[105][105]={};
        // 1 : i-1,j-1
        // 2 : i  ,j-1
        // 3 : i-1,j
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    From[i][j]=1;
                }
                else if(dp[i][j-1]>=dp[i-1][j]){
                    dp[i][j]=dp[i][j-1];
                    From[i][j]=2;
                }
                else {
                    dp[i][j]=dp[i-1][j];
                    From[i][j]=3;
                }
            }
        }

        int I=n,J=m;
        vector<string> ans;
        while(I && J){
            if(From[I][J]==1){
                ans.PB(S1[I-1]);
                I--,J--;
            }
            else if(From[I][J]==2){
                J--;
            }
            else I--;
        }
        for(auto it=ans.rbegin();it!=ans.rend() ;it++){
            cout<<(*it)<<' ';
        }
        cout<<'\n';
    }
    return 0;
}