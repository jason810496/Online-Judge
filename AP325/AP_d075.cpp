#include<iostream>
using namespace std;
/*
DP 0/1 kapsack 
AC
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,item[105],M,S,Weight,dp[200005],sum_item=0;
    cin>>n>>M>>S;
    for(int i=0;i<n;i++){  
        cin>>item[i];
        sum_item+=item[i];
    }
    Weight=M-S;
    for(int i=0;i<n;i++){ //for all items
        for(int w=Weight ; w-item[i]>=0 ;w--){
            dp[w]=max(dp[w],dp[w-item[i]]+item[i]);
        }
    }
    cout<<sum_item-dp[Weight];
    return 0;
}