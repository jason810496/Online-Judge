#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n , target ,L , R;
    
    cin>>n>>target>>L>>R;

    vector<int> dis(n,-1) , S(n);
    
    for(int i=0;i<n;i++) cin>>S[i];

    queue<int> q;

    q.push(0);
    dis[0]=0;
    

    while( q.size() && dis[ target]==-1){
        int cur = q.front();
        q.pop();

        int idx = cur-L;

        if( idx>=0 && S[ idx ]>=0 && S[idx]<n && dis[ S[idx] ]==-1 ){
            q.push( S[idx] );
            dis[ S[idx] ] = dis[ cur ]+1;
        }
        idx = cur+R;

        if( idx<n && S[ idx ]>=0 && S[idx]<n && dis[ S[idx] ]==-1 ){
            q.push( S[idx] );
            dis[ S[idx] ] = dis[ cur ]+1;
        }

    }

    cout<<dis[target];
    return 0;
}