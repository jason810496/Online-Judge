#include<bits/stdc++.h>
using namespace std;
#define N 200005
/*
AC
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m,arr[N],cur=0,ans=0; cin>>m>>n;
    map<int,int > M;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(M.find(arr[i])==M.end()) M[arr[i]]=0;
    }
    int l=1,r=1;
    for(;r<=m;r++){
        if(M[arr[r]]==0) cur++;
        M[arr[r]]++;
    }
    if(cur==m) ans++;

    for(;r<=n;r++,l++){
        M[arr[l]]--;
        if(M[arr[l]]==0) cur--;

        if(M[arr[r]]==0) cur++;
        M[arr[r]]++;

        if(cur==m) ans++;
    }
    cout<<ans;

    return 0;
}