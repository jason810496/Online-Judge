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
const int MAX_N = 400005;
const int INF = 1e9;

/*
    TOI exe (hard )
    prefix sum + b-search
    AC
*/
int n;
ll val[MAX_N]={},Diff[MAX_N]={};
vector<int> tag[MAX_N];
signed main(){
    OAO
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val[i]>>Diff[i];
        Diff[i]+=Diff[i-1];
    }

    int cnt=0;
    ll total=0; // cnt day > 0
    for(int i=1;i<=n;i++){
        int L=i+1,R=n,mid;

        if(!tag[i].empty() ){
            for(const int &it:tag[i]){
                total-=val[it]-(Diff[i-1]-Diff[it]);
                cnt--;
            }
        } 

        ll cur_minus=cnt*(Diff[i]-Diff[i-1]); //last
        cnt++; // current day
        total+=val[i];
        total-=cur_minus;
        cout<<total<<'\n';

        while(L<=R){
            mid=(L+R)/2;
            if(Diff[mid]-Diff[i]==val[i]){
                L=mid;
                break;
            }
            if(Diff[mid]-Diff[i]>val[i]){
                R=mid-1;
            }
            else L=mid+1;
        }
        tag[L].PB(i);
    }
    return 0;
}