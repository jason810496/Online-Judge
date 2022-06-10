#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define ll long long 
#define F first 
#define S second 
#define all(x) x.begin(),x.end()
#define PB push_back 

typedef pair<int,int> pii;
typedef vector< vector<int> > vvi;
typedef vector<int> vi;

const int INF = 1e9;
const int N = 1e5;

int s,t,n,m,min_dif;
vvi small , big;
// vvi prefix_small , prefix_big;

// 1-based prefix sum 
// inline int Query(vvi &mat,int i1,int j1,int i2,int j2){
//     i1-- , j1--;
//     return ( mat[i2][j2]+mat[i1][j1]-mat[i1][j2]-mat[i2][j1] );
// }
int big_sum , small_sum;

int cnt_diff(int r,int c){
    int cnt=0;
    big_sum=0 , small_sum=0;

    for(int i=0;i<s;i++){
        for(int j=0;j<t;j++){
            if( big[i+r][j+c]!=small[i][j] ) cnt++;

            big_sum+=big[i+r][j+c];
            small_sum+=small[i][j];
        }
    }

    return cnt;
}

signed main(){
    OAO 
    cin>>s>>t>>n>>m>>min_dif;

    small.resize( s , vi(t) );
    big.resize( n , vi(m) );
    // prefix_small.resize( s+1 , vi(t+1) );
    // prefix_big.resize( n+1 , vi(m+1) );

    for(auto &i:small){
        for(auto &j:i) cin>>j;
    }

    for(auto &i:big){
        for(auto &j:i) cin>>j;
    }

    // build prefix small 
    // for(int i=1;i<=s;i++){
    //     for(int j=1 ,sum=0;j<=t;j++){
    //         sum+=small[i-1][j-1];
    //         prefix_small[i][j] = prefix_small[i-1][j] + sum ;
    //     }
    // }
    // build prefix big 
    // for(int i=1;i<=n;i++){
    //     for(int j=1 ,sum=0;j<=m;j++){
    //         sum+=big[i-1][j-1];
    //         prefix_big[i][j] = prefix_big[i-1][j] + sum ;
    //     }
    // }

    int row_shift = n-s;
    int col_shift = m-t;
    
    bool flag = false;
    int  cnt=0 ,ans=INF; 
    for(int r=0;r<=row_shift;r++){
        for(int c=0;c<=col_shift;c++){
            int dif = cnt_diff( r, c );

            if( dif<=min_dif){
                flag = true;
                ans = min( ans , abs(big_sum - small_sum) );
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n'<<ans;

    return 0;
}