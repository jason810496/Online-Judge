#include<bits/stdc++.h>
using namespace std;


#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define all(x) x.begin(),x.end()
#define PB push_back
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
typedef pair<int,long long> pil;

const int MAX_N = 100005;
const int INF = 1e9;

class Solution {
public:
    int n , m ;
    int pos[4][2] = { {0,1} , { 1,0 } ,{ 0,-1 }, {-1,0 } };

    vector< vector<int> > DP;
    int DFS(int x,int y,vector<vector<int> > &g){
        if(DP[x][y] != INF ) return DP[x][y];
        if( x==n-1 && y==m-1 ) return DP[x][y] = 0;

        int ret =INF ;
        for(int k=0;k<4;k++){
            int i = x+pos[k][0] ,  j= y+pos[k][1];
            if( i<0 || j<0 ||i>=n ||j>=m ) continue;

            DP[x][y] = min( DP[x][y] , DFS(i,j,g) );
            ret = min( ret , DP[x][y] );
        } 

        return DP[x][y] = ret + g[x][y] ;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        
        vector< vector<int> > dp( n , vector<int>(m , INF ) );

        dp[0][0] = grid[0][0];

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        // cout<<"===\n";

        // for(int x=0;x<n;x++){
        //     for(int y=0;y<m;y++){

        //         for(int k=0;k<4;k++){
        //             int i = x+pos[k][0] , j= y+pos[k][1];
        //             if( i<0 || j<0 || i>=n || j>=m ) continue;

        //             dp[i][j] = min( dp[i][j] , dp[x][y] + grid[i][j] );

        //         }
        //     }
        // }

        dp[n-1][m-1]=0;

        for(int x=n-1;x>=0;x--){
            for(int y=m-1;y>=0;y--){

                for(int k=0;k<4;k++){
                    int i = x+pos[k][0] , j= y+pos[k][1];
                    if( i<0 || j<0 || i>=n || j>=m ) continue;

                    dp[i][j] = min( dp[i][j] , dp[x][y] + grid[i][j] );

                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j]<<' ';
            }
            cout<<'\n';
        }

        return dp[0][0];


    //    DP.resize( n, vector<int>(m,INF) );

    //     int ans = DFS(0,0,grid);

    //    for(int i=0;i<n;i++){
    //        for(int j=0;j<m;j++){
    //            cout<<DP[i][j]<<' ';
    //        }
    //        cout<<'\n';
    //    }

    //    return dp[0][0];
    }

};


void Change(){
    string str;
    getline(cin,str);

    for(char i:str){
        if( i=='[') cout<<'{';
        else if(i==']') cout<<'}';
        else cout<<i;
    }
    cout<<'\n';
}

int main(){
    //OAO
    
    Solution solve1,solve2;

    // Change();

    vector< vector<int> > T1 = {{0,1,1},{1,1,0},{1,1,0}};
    vector< vector<int> > T2 = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    cout<<solve1.minimumObstacles(T1)<<'\n';
    cout<<solve2.minimumObstacles(T2)<<'\n';
    return 0;
}