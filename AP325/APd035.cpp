#include<bits/stdc++.h>
using namespace std;
#define N 200005
/*
AC
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n ,MAX_len=1,cur_len=0,arr[N];cin>>n;
    map<int,int> M;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        M[arr[i]]=0;
    }
    int r=1,l=1,col;
    while(r<=n){
        if(M[arr[r]]==0){
            M[arr[r]]++;
            cur_len++;
        }
        else if(M[arr[r]]==1){
            while(arr[l]!=arr[r]){
                M[arr[l]]--;
                l++;
                cur_len--;
            }
            M[arr[l]]--;
            l++;
            cur_len--;
        }
        MAX_len=max(MAX_len,r-l+1);
        r++;
    }
    cout<<MAX_len;
    return 0;
}