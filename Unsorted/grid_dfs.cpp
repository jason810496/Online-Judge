#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef pair<int,int> pii;

const int MAX_N= 1e3+5;
bool vis[MAX_N][MAX_N]={};
int count[MAX_N][MAX_N]={}; 
void BFS(int st_r,int st_c){

    // initialize BFS
    queue<pii> q;
    vis[st_r][st_c]=1;
    count[st_r][st_c]=1;
    q.push({st_r,st_c});
    // keep BFS 
    while(q.size() ){

    }
}

int main(){
    OAO

    return 0;
}