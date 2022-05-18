#include<bits/stdc++.h>
using namespace std;
#define N 200005
/*
AC but so slow ?
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    map<int,int > M;
    int arr[N],n,Size=0,left=1,right=1,sum,ans=N;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(M.find(arr[i])==M.end()){
            M[arr[i]]=0;
            Size++;
        }
    }
    while(right<=n){
        
        if (M[arr[right]]==0) sum++;
        M[arr[right]]++;
        right++;
        while(M[arr[left]]>1){
            M[arr[left]]--;
            left++;
        }
        
        if(sum==Size) ans=min(ans,right-left);
        //cout<<sum<<' '<<left<<' '<<right<<'\n';
    }
    cout<<ans;
    return 0;
}