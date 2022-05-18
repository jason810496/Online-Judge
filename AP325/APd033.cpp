#include<iostream>
using namespace std;
#define N 200005
/*
Sliding Window AC

*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,L,MAX=0,sum=0,i,color[N]={0},cur[N];
    cin>>n>>L;
    for(i=1;i<=L;i++){
        cin>>cur[i];
        if(color[cur[i]]==0) sum++;
        color[cur[i]]++;
    }
    MAX=max(MAX,sum);
    for(int j=1;i<=n;j++,i++){
        cin>>cur[i];
        color[cur[j]]--;
        if(color[cur[j]]==0) sum--;
        if(color[cur[i]]==0) sum++;
        color[cur[i]]++;
        MAX=max(MAX,sum);
    }
    cout<<MAX;
    return 0;
}