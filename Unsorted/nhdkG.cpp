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
const int INF = 1e9+5;
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
// AC
inline bool prim(int x){
    if( x<=1 ) return 0;
    if( x<=3 ) return 1;

    if(x%2==0 || x%3==0) return 0;

    for(int i=5;i*i<=x;i+=6){
        if(x%i==0 || x%(i+2)==0) return 0;
    } 
    return 1;
}
inline int convert(const string &str){
    int ret=0;
    for(const char ch:str){
        ret=ret*10+ch-'0';
    }

    return ret;
}
//bitset<INF> prim=0;
int main(){
    OAO
    int t,mx=0; cin>>t;
    vector<string> vec(t);
    for(string &i:vec){
        cin>>i;
        //sort(range(i),greater<char>());
        //mx=max(mx,convert(i));
    }
    // prim[1]=1;
    // for(int i=2;i*i<=mx;++i){
    //     if(!prim[i]){
    //         for(int j=i*2;j<=mx;j+=i){
    //             prim[j]=1;
    //         }
    //     }
    // } 
    
    for(string str:vec){
        sort(range(str));
        if(!prim(convert(str))) goto End;
        while(next_permutation(range(str))){
            if(!prim(convert(str))) goto End;
        }

        cout<<"YES\n";
        continue;
        End:
        cout<<"NO\n";
    }
    return 0;
}