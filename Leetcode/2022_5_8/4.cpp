#include<bits/stdc++.h>
using namespace std;


#define F first
#define S second
#define ll long long 
#define all(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INF = 1e9;

struct Node{
    int L,R,x,y;
    Node(int l=0,int r=0,int X=0,int Y=0){
        L=l;
        R=r;
        x=X;
        y=Y;
    }
};

class Solution {
public:
    int MX_step ;
    int half;
    int n , m;
    int pos[2][2] = {{0,1},{1,0}};
    bool flag = false;

    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();

        MX_step = n+m-1;
        if( MX_step%2 ==1 ) return false;
        half = MX_step/2;

        queue< Node> q;

        q.push( Node(0,0,0,0) );

        while(q.size() ) {
            Node P = q.front()  ; q.pop();
            if( grid[P.x][P.y]=='(') P.L++;
            else P.R++;

            // cout<<P.x<<' '<<P.y<' '<<grid[P.x][P.y]<<'\n';

            if( P.x==n-1 && P.y==m-1){
                if( P.L==P.R ) return true;
            }

            if( P.L > half || P.R > half || P.R>P.L ) continue;

            for(int k=0;k<2;k++){
                int i  = P.x+pos[k][0] , j = P.y+pos[k][1];
                if( i>=n || j>=m ) continue;

                q.push( Node(i,j,P.L,P.R) );
            }
        }

        return false;
    }
};

/*

TLE CASE
[["(","(",")","(",")","(","(",")","(","(",")",")",")",")",")","(",")","(","(",")","(","(",")",")",")",")",")","(","(","(","("],[")","(","(","(",")","(",")","(","(",")",")",")",")","(",")",")","(","(",")",")","(",")","(",")","(","(",")","(",")","(","("],[")",")","(","(",")","(","(",")",")",")",")","(","(",")",")","(",")","(",")",")","(","(","(",")",")",")","(",")",")","(",")"],["(","(",")","(",")","(","(",")","(","(","(",")",")","(",")","(",")",")",")",")",")",")","(","(",")","(",")","(",")","(","("],[")",")","(",")",")","(","(","(",")",")","(",")","(",")",")",")","(","(","(",")",")","(",")","(",")",")","(","(","(","(",")"],[")",")","(","(",")","(",")","(",")","(",")","(",")",")","(",")","(",")",")","(",")","(","(","(",")","(",")",")",")","(","("],[")","(","(","(","(","(","(",")",")","(","(",")","(",")",")","(",")",")",")","(","(","(",")","(","(",")",")","(",")","(",")"],[")",")","(","(","(","(","(","(","(",")",")","(","(","(","(","(","(","(","(","(","(","(","(",")",")","(","(",")",")","(",")"],["(",")",")",")","(","(",")",")",")",")","(",")",")","(",")",")","(","(","(","(","(","(","(",")",")","(","(",")",")","(","("],["(","(",")","(",")",")",")",")","(","(","(",")",")",")","(",")","(","(",")","(","(","(",")","(","(","(","(","(",")",")",")"],["(",")","(","(","(","(",")","(","(",")",")","(","(",")","(","(","(",")","(","(","(",")",")","(",")",")","(",")","(","(",")"],[")",")","(","(","(","(",")","(","(",")",")","(",")",")","(",")","(","(","(","(","(","(","(",")","(","(",")",")","(","(","("],["(",")",")",")","(",")","(","(","(",")",")",")","(",")","(",")",")","(","(","(","(",")","(",")",")",")",")",")",")","(","("],["(","(","(","(","(","(",")",")","(",")","(","(","(",")",")","(",")","(",")","(",")","(","(","(",")",")",")","(",")","(","("],["(",")",")",")",")","(","(",")",")",")",")",")",")","(","(",")","(",")",")","(",")","(",")",")",")","(","(",")","(","(","("],["(",")",")","(","(",")",")","(",")",")","(","(","(",")",")",")",")","(","(","(",")",")","(",")","(","(","(","(",")",")",")"],[")","(","(",")","(","(",")",")",")","(","(","(","(",")","(",")",")",")","(",")","(",")","(","(",")","(","(","(","(","(","("],["(",")","(",")","(","(",")",")",")",")",")","(","(",")",")","(",")","(",")",")",")",")","(","(","(",")","(",")","(",")",")"],["(",")","(",")",")",")","(","(","(",")","(",")","(","(",")",")","(",")","(",")","(",")","(","(","(","(","(",")","(",")","("],[")",")",")",")",")","(",")",")","(","(",")","(",")",")","(",")",")","(","(","(","(",")","(","(","(","(",")",")",")",")","("],[")","(","(","(","(","(",")","(",")",")",")",")","(","(","(",")",")","(",")",")","(","(","(","(","(","(",")",")","(","(","("],["(","(","(",")",")","(",")","(",")",")",")",")","(",")",")",")",")","(",")","(","(","(","(",")","(","(","(","(","(","(",")"]]

*/