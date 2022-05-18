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

/*  TOI Exe
    weighted job schedule
    AC
*/
struct line{
    int val,st,ed;
}Lines[MAX_N];

int dp[MAX_N]={},Len,n;
signed main(){
    OAO
    cin>>Len>>n;
    for(int i=0;i<n;i++){
        cin>>Lines[i].st>>Lines[i].ed;
        Lines[i].val=Lines[i].ed-Lines[i].st;
    }

    sort(Lines,Lines+n,[&](line a,line b){
        return a.ed<b.ed;
    });

    dp[0]=Lines[0].val;

    for(int i=1;i<n;i++){
        int L=0,R=i-1,mid,idx=-1,Incusive=Lines[i].val;

        while(L<=R){
            mid=(L+R)/2;
            if(Lines[mid].ed<=Lines[i].st){
                idx=mid;
                L=mid+1;
            }
            else R=mid-1;
        }
        if(idx!=-1) Incusive+=dp[idx];
        dp[i]=max(dp[i-1],Incusive);
        
    }
    cout<<dp[n-1]<<'\n';

    return 0;
}