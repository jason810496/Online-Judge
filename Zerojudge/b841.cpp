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

/*  WA */
int R,C,maze[10][10],MAX=0;
int pos[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int mem[10][10];
bool visited[10][10];

struct node{
    int I,J,cnt;
    node(int i=0,int j=0,int ct=0){
        I=i,J=j,cnt=ct;
    }
};

void BFS(int I,int J){
    int cnt,i,j;
    queue<node> q;
    q.push(node(I,J,1));

    while(q.size() ){
        I=q.front().I;
        J=q.front().J;
        cnt=q.front().cnt;
        q.pop();

        for(int k=0;k<4;k++){
            i=pos[k][0]+I;
            j=pos[k][1]+J;

            if(i<1||j<1||i>R||j>C) continue;
            if( visited[i][j] ) continue;

            if(maze[i][j]==maze[I][J]){
                visited[i][j]=1;
                mem[i][j]=mem[I][J]+1;
                MAX=max(MAX,mem[i][j]);
                q.push(node(i,j,cnt+1));
            }
            else{
                if(cnt>=2){
                    visited[i][j]=1;
                    mem[i][j]=mem[I][J]+1;
                    MAX=max(MAX,mem[i][j]);
                    q.push(node(i,j,1));
                }
            }
        }
    }
    
}
int main(){
    OAO
    cin>>R>>C;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>maze[i][j];
        }
    }

    for(int i=1;i<=R;i++){
        for(int j=1,num;j<=C;j++){
            if(visited[i][j]) continue;
            mem[i][j]=1;
            visited[i][j]=1;
            BFS(i,j);
        }
    }

    cout<<MAX<<'\n';

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cout<<mem[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}