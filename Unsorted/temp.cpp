 /*██████╗ ██████╗ ██████╗ ███████╗     ██████╗ ██╗   ██╗████████╗
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

int t,P[55],Size[55],Mx,dp[55][55];
vector<string> vec;
void Init(int n){
    Mx=1;
    for(int i=0;i<=n;i++){
        P[i]=i, Size[i]=1;
    }
}
int Find(int x){
    return (x==P[x] ? x:P[x]=Find(P[x]));
}
void Union(int a,int b){
    a=Find(a) , b=Find(b);
    if(a== b) return ;
    if(Size[b]>Size[a]) swap(a,b);
    P[b]=a;
    Size[a]+=Size[b];
    Mx=max(Mx,Size[a]);
}
int LCS(int a,int b){
    string A=vec[a]  ,B=vec[b];
    int n=A.size()  ,m=B.size();
    MEM(dp,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
void solve(){
    int n ; cin>>n;
    vec.resize(n);
    Init(n);
    for(string &i:vec) cin>>i;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(LCS(i,j)*2>=min(vec[i].size(),vec[j].size())){
                Union(i,j);
            }
        }
    }
    cout<<Mx<<'\n';
    for(int i=0;i<n;i++){
        cout<<Size[i]<<' ';
    }
}
signed main(){
    OAO
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
5
abcedfgse
aedfgsad
asfgovaww
asdasbwa
aasdbvd

*/
