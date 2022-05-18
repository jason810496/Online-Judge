#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,0,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
typedef pair<int,int> pii;
const int MAX_N = 1e6+5;
const int INF = 1e9;

int main(){
    OAO
    int k;
    string a,b;
    ll A=0,B=0;
    cin>>k>>a>>b;
    int base=1;
    for(auto it = a.rbegin() ; it !=a.rend();it++){
        A+=base*((*it)-'0');
        base*=k;
    }
    base=1;
    for(auto it = b.rbegin() ; it !=b.rend();it++){
        B+=base*((*it)-'0');
        base*=k;
    }
    cout<<A*B;
    return 0;
}