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
ll MOD = 100000007;
/*
    Matrix fast power AC

*/
typedef vector<vector<long long> > M;
M multi(M &a,M &b){
    int B=b[0].size();
    M ret(2,vector<ll>(B,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<B;j++){
            for(int k=0;k<2;k++){
                ret[i][j]=(ret[i][j]+a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return ret;
}

int main(){
    OAO
    ll m,f;
    int k;
    M init={{0,1},{1,1}};
    while(cin>>m>>f>>k){
        M base=init,Mat={{m},{f}},I={{1,0},{0,1}};
        while(k){
            if(k&1){
                I=multi(base,I);
            };
            base=multi(base,base);
            k>>=1;
        }
        //cout<<"---------\n";
        Mat=multi(I,Mat);
        cout<<(Mat[0][0]+Mat[1][0])%MOD<<'\n';
    }
    return 0;
}