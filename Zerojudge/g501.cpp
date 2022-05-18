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

int arr[4][13]={
    {1, 2, 3, 5, 6, 8, 11, 13, 17, 21, 22},
    {2, 3, 5, 7, 8, 13, 16, 17, 21, 22, 24},
    {1, 3, 5, 6, 7, 15, 16, 17, 22, 23, 24, 25},
    {2, 4, 5, 7, 8, 15, 17, 21, 23, 25}
};
/*11
  11
  12
  10
*/
/*
    AC
*/
int H ,n , Size[4]={11,11,12,10},stk[30];
unordered_map<int,int> Map;

void DFS(int id,int depth,int last){
    if(depth==n){
        int Set=0;
        for(int i=0;i<n;i++){
            Set|=(1<<stk[i]);
        }
        Map[Set]++;
    }
    for(int i=last+1;i<=Size[id];i++){
        stk[depth]=arr[id][i-1];
        DFS(id,depth+1,i);
    }
}

signed main(){
    //OAO
    cin>>H>>n;
    for(int k=0;k<4;k++){
        DFS(k,0,0);
    }
    int ans=0;
    for(auto i:Map){
        if(i.S>=H) ans++;
    }
    cout<<ans;
    return 0;
}