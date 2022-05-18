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
const int MAX_N = 1e9+5;
const int INF = 1e9;

inline bool comp(int a,int b){
    return (a==0 ? 1:(b==0 ? 1:a>b));
}
int main(){
    //OAO
    int t,n,x,buck[10];
    cin>>t;
    string str,temp;
    while(t--){
        int ans=0;
        cin>>n;
        getchar();
        getline(cin,str);
        vector<int> vec;
        for(const char ch:str){
            vec.push_back(ch-'0');
        }
            
        
        sort(range(vec));
        // for(const char ch:str){
        //     ans+=ch-'0';
        //     buck[ch-'0']++;
        // }
        for(const auto i:vec) cout<<i<<' ';
        cout<<'\n';
    }

    return 0;
}