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
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N =4e5+5;
const int N = 2e6+5;
const int INF = 1e9;

#define lowbit(x) x&-x 

int n;
vector<int> BIT,arr;
void update(int p ,int val){
    for(int  i = p ; i<=n;i+=lowbit(i) ){
        BIT[i]+=val;
    }
}

int query(int p ){
    int ret=  0;
    for(int i = p ; i ; i-=lowbit(i)){
        ret+=BIT[i];
    }
    return ret ;
}
int main(){
    OAO
    int q , sum=0; cin>>n>>q;

    BIT.resize(n+1);
    arr.resize(n+1);

    for(int i=1 ;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
        update(i, arr[i]);
    }

    int oper ; 
    while( q--){
        cin>>oper;
        if( oper==1 ){
            int  p , c;
            cin>>p>>c;
            update(p,c-arr[p]);
            sum+=c-arr[p];
            arr[p] = c;
        }
        else{
            int k ;
            cin>>k;

            int L=1 , R=n;
            if( sum < k ){
                cout<<"meh\n";
                continue;
            }

            while( L<=R ){
                int mid = (L+R)/2;
                if( query(mid) > k ) R=mid-1;
                else L=mid+1;
            }
            
            int idx = L;

            int st=max(1,idx-5);
            for(int ed=min(n,idx+5) ;st<=ed;st++){
                if( query(st) >=k) break;
            }

            cout<<st<<'\n';
        }
    }
    return 0;
}