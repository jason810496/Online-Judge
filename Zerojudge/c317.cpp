#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,0,sizeof(x))
typedef pair<int,int> pii;
const int MAX_N = 1e9+5;
const int INF = 1e9;

int main(){
    OAO

    int t ; cin>>t;
    while( t-- ){
        int x,a,b;
        cin>>x>>a>>b;
        int mx=max(a,b) , mn=min(a,b);

        int I=x/mx ;
        int Last = x-I*mx;
        int J=Last/mn;

        while( (I*mx+J*mn) != x && I ){
            I--;
            Last = x-I*mx;
            J = Last/mn;
        }

        if( (I*mx + J*mn)==x ) cout<<I+J<<'\n';
        else cout<<-1<<'\n';
    }
    return 0;
}