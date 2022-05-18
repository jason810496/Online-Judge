#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
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
    AC
    LCS + DSU

*/
int P[55],Size[55],MAX;

void Init(){
    MAX=1;
    for(int i=0;i<55;i++) P[i]=i,Size[i]=1;
}

inline int Find(int x){
    return (x==P[x] ? x:P[x]=Find(P[x]));
}

void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if(a==b) return ;

    if(Size[a] >= Size[b]){
        Size[a]+=Size[b];
        Size[b]=0;
        P[b]=a;
        MAX=max(MAX,Size[a]);
    }
    else{
        swap(a,b);
        Size[a]+=Size[b];
        Size[b]=0;
        P[b]=a;
        MAX=max(MAX,Size[a]);
    }
}

bool LCS(string a,string b){
    int n=a.size(),m=b.size();

    vector<vector<int> > dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }


    int lcs=(dp[n][m]*2),min_len=min(n,m);

    return lcs>=min_len ;
}

int main(){
    OAO
    int t , n; cin>>t;
    while(t--){
        Init();
        cin>>n;
        vector<string> vec;
        string str;
        for(int i=0;i<n;i++){
            cin>>str;
            vec.push_back(str);
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if( LCS(vec[i],vec[j]) ){
                    Union(i+1,j+1);
                }
                
            }
        }

        cout<<MAX<<'\n';
    }

    return 0;
}