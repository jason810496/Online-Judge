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
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

const int MAX_N = 100005;
const int INF = 1e9;

class Solution {
public:
    
    int n , m , total ;
    vvi move = { {0,1} , {1,0} , {0,-1} , {-1,0 } };

    inline int get_id(int i,int j){
        return i*m+j;
    }
    inline pii get_pos(int id){
        return {id/m , id%m};
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        n= grid.size() , m =grid[0].size() , total = n*m;
        vector<int> dis( total , INF );
        vector< bool > vis( total );

        priority_queue< pii , vector< pii > , greater<pii> > pq;

        dis[0]=0;
        vis[0]=1;
        pq.push( { 0 , 0 } );

        while( pq.size() ){
            int D = pq.top().F;
            int id= pq.top().S;

            if( id==total-1 ){
                break;
            }
            pq.pop();
            pii t = get_pos( id );
            int x=t.F , y=t.S;

            for(auto &mv: move){
                int i = x+mv[0] , j = y+mv[1];
                int nxt_id = get_id( i , j );
                if( i<0 || j<0 || i>=n || j>=m || vis[ nxt_id ] ) continue;
                
                dis[ nxt_id ] = dis[ id ]+grid[i][j];
                vis[ nxt_id ] = 1;

                pq.push( { dis[nxt_id] , nxt_id } );
            }
        }

        return dis[ total-1 ];
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