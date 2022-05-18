#include<bits/stdc++.h>
#define ll long long 
using namespace std;
/*
DFS AC
*/
int n,m,Graph[105][105];
int pos[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
ll ANS=0;
bool visited[105][105];
void DFS(int I,int J){
    // cout<<I<<' '<<J<<'\n';
    int Min=INT32_MAX,si=-1,sj=-1,I__,J__;
    for(int i=0;i<4;i++){
        I__=I+pos[i][0];
        J__=J+pos[i][1];
        if(I__<=0||I__>n||J__<=0||J__>m) continue;
        if(visited[I__][J__]) continue;
        if(Graph[I__][J__]<Min){
            Min=Graph[I__][J__];
            si=I__;
            sj=J__;
        }
    }

    if(si==-1) return;
    ANS+=Min;
    visited[si][sj]=true;
    DFS(si,sj);
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>m;
    int si,sj,Min=INT32_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>Graph[i][j];
            if(Graph[i][j]<Min){
                si=i;
                sj=j;
                Min=Graph[i][j];
            }
        }
    }
    visited[si][sj]=true;
    ANS+=Graph[si][sj];
    DFS(si,sj);
    cout<<ANS;
    return 0;
}