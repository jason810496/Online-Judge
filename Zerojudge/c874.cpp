#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end(
#define MEM(x,i) memset(x,0,sizeof(x))
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

overflow -> py

*/
ll Pow(ll x,int n){
    if(n==0) return 1;
    if(n%2==0){
        ll temp=Pow(x,n/2);
        return temp*temp;
    }

    return x*Pow(x,n-1);
}
int main(){
    OAO
    int n;
    cin>>n;
    ll ans=(ll)(1-Pow(4,n))/(ll)(-3);
    cout<<ans;
    return 0;
}