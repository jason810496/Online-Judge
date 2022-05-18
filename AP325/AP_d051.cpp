#include<iostream>
using namespace std;
/*AC*/
#define N 100005
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,arr[N],x,MAX_d=0,Low=INT32_MAX;
    cin>>n;
    while(n--){
        cin>>x;
        MAX_d=max(MAX_d, x-Low);
        Low=min(Low,x);
    }
    cout<<MAX_d;
    return 0;
}