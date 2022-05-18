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

// TLE , I/O optimize
int main(){
    OAO
    int n ,base=1;
    cin>>n;

    vector<short> vec;
    vec.push_back(0);
    while( vec.size() < 10005 ){
        for(int i=0;i<base;i++) vec.push_back(0);
        for(int i=0;i<base;i++) vec.push_back(1);
        for(int i=0;i<base;i++) vec.push_back(2);
        for(int i=0;i<base;i++) vec.push_back(3);
        base++;
    }

    // cout<<i<<' '<<cur<<'\n';
    int j = vec[n];
    if( j==0) cout<<"Pen";
    else if( j==1) cout<<"Pineapple";
    else if( j==2) cout<<"Apple";
    else cout<<"Pineapple pen";
    return 0;
}