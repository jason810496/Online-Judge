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
    WLOJ
    prefix sum + b-search
*/
int val[MAX_N]={},n;
ll Diff[MAX_N]={};
vector<int> tag[MAX_N];
signed main(){
    OAO
    cin>>n;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<=n;i++){
        cin>>Diff[i];
        if(Diff[i]<=0) Diff[i]=0;
        Diff[i]+=Diff[i-1];
    }

    ll total=0,Minus;
    int cnt=0;
    for(int i=1;i<=n;i++){
        
        cnt++;
        int L=i,R=n,mid;
        while(L<=R){
            mid=(L+R)/2;
            if(Diff[mid]-Diff[i-1]>=val[i] ) R=mid-1;
            else L=mid+1;
        }
        tag[L].PB(i);
        
        for(const int it:tag[i]){
            Minus+=val[it]-(Diff[i-1]-Diff[it-1]);
            cnt--;
        }
        //cout<<cnt<<" cnt\n";
        Minus+=cnt*(Diff[i]-Diff[i-1]);
        cout<<Minus<<' ';
        Minus=0;
    }
    return 0;
}