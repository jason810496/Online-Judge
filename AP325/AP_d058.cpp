#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
/*
Greedy 
miss x1
AC
*/
struct item{
    int t,d;
}Items[100005];
inline bool comp(item a,item b){
    return a.d<b.d;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>Items[i].t;
        for(int i=0;i<n;i++) cin>>Items[i].d;
        sort(Items,Items+n,comp);
        ll Time=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            Time+=Items[i].t;
            if(Items[i].d<Time){
                flag=false;
                break;
            }
        }
        cout<<(flag? "yes\n":"no\n");
    }
    return 0;
}
