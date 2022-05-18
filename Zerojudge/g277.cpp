#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define ll long long 
#define F first
#define S second
#define range(x) x.begin(),x.end()
typedef pair<int,int> pii;


/*   AC    */
/*  APCS P3*/
int n;
int main(){
    vector<pii> sorted;
    vector<ll> prefix;
    cin>>n;
    sorted.resize(n);
    prefix.resize(n+5);
    for(int i=1;i<=n;i++){
        cin>>sorted[i-1].F;
        sorted[i-1].S=i;
        prefix[i]=sorted[i-1].F+prefix[i-1];
    }

    sort(range(sorted));

    int L=1,R=n,mid,cnt=0;

    mid=sorted[cnt].S;
    while(L!=R){
        //cout<<"L,R :"<<L<<" ,"<<R<<"\n";
        while(mid<L||mid>R){
            mid=sorted[++cnt].S;
        }

        ll right=prefix[R]-prefix[mid],left=prefix[mid-1]-prefix[L-1];
        
        if(right>=left){
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }

    cout<<prefix[L]-prefix[L-1];
    return 0;
}