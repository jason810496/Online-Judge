#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
typedef pair<int,int> pii;
const int MAX_N = 1e9+5;
const int INF = 1000005;
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
    AC
    
    fib + bianry search

*/
int main(){
    OAO
    int t ,L,R; 
    cin>>t;
    vector<int> fib(50);

    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<50;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }

    while(t--){
        cin>>L>>R;
        if(L>R) swap(L,R);
        auto iter_L=lower_bound(range(fib),L);
        auto iter_R=upper_bound(range(fib),R);
        //cout<<(*iter_L)<<" "<<(*iter_R)<<'\n';
        int cnt=iter_R-iter_L;
        for(;iter_L!=iter_R;iter_L++) cout<<(*iter_L)<<'\n';
        cout<<cnt<<'\n'<<(t? "------\n":"");
    }

    return 0;
}