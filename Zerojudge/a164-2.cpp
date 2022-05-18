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
const int MAX_N =4e5+5;
const int N = 2e6+5;
const int INF = 1e9;

int T[MAX_N];
/*
    Segment tree optimization
*/
int main(){
    OAO
    int t=1,n,q,L,R;
    int vec[MAX_N];
    while(cin>>n>>q){
        cout<<"Case "<<t++<<":\n";
        for(int i=1;i<=n;i++) cin>>vec[i];
        while(q--){
            cin>>L>>R;
            int Mx=-INF,cur_L=L,cur_R=L,LL=L,RR=L,cur=-INF;
            for(int i=L;i<=R;i++){
                // cur=max(cur+vec[i],vec[i])
                // Mx=max(Mx,cur)
                if(cur+vec[i]>=vec[i]){
                    cur=cur+vec[i];
                    cur_R=i;
                }
                else{
                    cur=vec[i];
                    cur_L=i;
                    cur_R=i;
                }

                if(cur>Mx){
                    Mx=cur;
                    RR=cur_R;
                    LL=cur_L;
                }
            }
            cout<<LL<<" "<<RR<<" "<<Mx<<"\n";
        }
    }
    return 0;
}