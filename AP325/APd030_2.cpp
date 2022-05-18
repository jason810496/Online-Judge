#include<bits/stdc++.h>
using namespace std;
#define N 100005

int n,L,pos[N],ht[N],ans=0,MAX_H=0;

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    stack<int > stk;
    cin>>n>>L;
    for(int i=1;i<=n;i++) cin>>pos[i];
    for(int i=1;i<=n;i++) cin>>ht[i];
    pos[0]=0,pos[n+1]=L; //limit
    ht[0]=INT_MAX,ht[n+1]=INT_MAX;
    stk.push(0); //from left to right
    for(int i=1;i<=n;i++){
        if(pos[i]-ht[i]>=pos[stk.top()]|| pos[i]+ht[i]<= pos[i+1]){
            ans++,MAX_H=max(MAX_H,ht[i]);

            while(pos[stk.top()]+ht[stk.top()]<=pos[i+1]){
                ans++,MAX_H=max(MAX_H,ht[stk.top()]);
                stk.pop();
            }
        }
        else stk.push(i);
    }
    cout<<ans<<'\n'<<MAX_H;
    return 0;
}