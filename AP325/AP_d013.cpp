#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end(
#define MEM(x,i) memset(x,0,sizeof(x))
#define rep(i,n) for(int i=0;i<n++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
typedef pair<int,int> pii;
const int MAX_N = 1e9+5;
const int INF = 1e9;
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
/*
    fast power (big interger)

*/
ll y,p,sum=0;

ll fast_pow(ll num,int n){
    if(n==0) return 1;
    if(n%2==0){
        ll temp=fast_pow(num,n/2)%p;
        return (temp*temp)%p;
    }

    return (num*fast_pow(num,n-1) )%p;
}
int main(){
    OAO
    string x;
    cin>>x>>y>>p;
    for(char ch:x){
        sum=(sum*10+ch-'0')%p;
    }

    cout<<fast_pow(sum,y);
    return 0;
}