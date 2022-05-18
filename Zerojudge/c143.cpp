#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define cc first
#define rr second
#define ll long long 
#define range(x) x.begin(),x.end()
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
    WA 87% ...

*/
int main(){
    OAO
    bool G[505][505];
    int C,R,t,ans=0;
    cin>>R>>C>>t;
    int r1,c1,r2,c2,r,c;
    while(t--){
        cin>>r1>>c1>>r2>>c2;
        if(r1 > r2) r=-1;
        else if(r1==r2) r=0;
        else r=1;

        if(c1 >c2) c=-1;
        else if(c1==c2) c=0;
        else c=1;

        for(int n=max(abs(r1-r2),abs(c1-c2));n>=0;n--){
            if(!G[r1][c1]){
                ans++;
                G[r1][c1]=1;
            }
            r1+=r;
            c1+=c;
        }
    }

    // for(int i=1;i<=R;i++){
    //     for(int j=1;j<=C;j++){
    //         cout<<G[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<ans;
    return 0;
}