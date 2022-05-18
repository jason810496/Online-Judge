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
const int MAX_N = 1e3+5;
const int INF = 1e9;
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
/*
inline bool comp(int a,int b){
    return a>b;
}

struct comparator{
    bool operator() (const int &a,const int &b){
        return a>b;
    }
};

*/
ll dp[MAX_N][MAX_N];
int arr[MAX_N],n;

ll Top(int L,int R){
    if(dp[L][R]!=-1 ) return dp[L][R];
    // out of range
    if(L>R ) return 0;
    // if(L+1==R){
    //     return (arr[L]==arr[R] );
    // }
    for(int i=L+1;i<=R;i++){
        //int cnt=(arr[L]==arr[i] ? 1:0);
        ll left=Top(L+1,i-1); // [L+1,i-1]
        ll right=Top(i+1,R);  // [i+1,R ]
        
        dp[L][R]=max(dp[L][R],left+right+(arr[L]==arr[i]) );
    }
    
    return dp[L][R];
}
int main(){
    OAO
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        MEM(dp,-1);
        for(int i=1;i<=n;i++) cin>>arr[i];
        cout<<Top(1,n)<<'\n';
    }
    return 0;
}