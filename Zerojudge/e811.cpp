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
ll MOD = 10000;
typedef vector<vector<ll > > Mat;
/*
    TOI exe
    dp Matrix fast power
    AC
*/
ll p,q,r,A0,A1,N;
Mat mul(Mat a,Mat b){
    Mat ret(3,vector<ll>(3,0));

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                ret[i][j]=(ret[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
            }
        }
    }
    return ret;
}

inline void Print(ll num){
    char ans[5]={};
    for(int i=3;i>=0;i--){
        ans[i]=(num%10)+'0';
        num/=10;
    }
    cout<<ans;
}
int main(){
    OAO 
    cin>>p>>q>>r>>A0>>A1>>N;
    ll A2=p*A1+q*A0+r;
    Mat base={{p,q,r},{1,0,0},{0,0,1}},ret={{A1,0,0},{A0,0,0},{1,0,0}};
    ll K=N;
    if(N==1) Print(A1);
    else{
        N--;
        while(N){
            if(N&1){
                ret=mul(base,ret);
            }
            base=mul(base,base);
            N>>=1;
        }
        Print(ret[0][0]);
    }
    
    return 0;
}