#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n , target ,L , R;
    int S[100005],dis[100005];
    
    cin>>n>>target>>L>>R;
    for(int i=0;i<n;i++) cin>>S[i];

    memset(dis,-1,sizeof(dis));
    queue<int> q;
    
    int index,iL,iR;
    q.push(0);
    dis[0]=0;
    while(q.size() && dis[target]==-1){
        index=q.front();
        q.pop();
        iL=index+L;
        iR=index+R;
        if(iL>0 && S[iL]>0 && S[iL]<n &&S[iL]==-1){
            q.push(S[iL]);
            dis[S[iL]]=dis[index]+1;
        }
      
            
        if(iR<n && S[iR]>0 && S[iR]<n && S[iR]==-1){
            q.push(S[iR]);
            dis[S[iR]]=dis[index]+1;
            
        }
         
    }
    // for(int i=0;i<n;i++){
    //     cout<<dis[i]<<' ';
    // }
    cout<<dis[target];
    return 0;
}