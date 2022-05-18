#include<iostream>
#define N 10005
using namespace std;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,arr[N];
    long long x,MAX=0,cur_Max=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        cur_Max=max(cur_Max+x, x);
        MAX=max(cur_Max,MAX);
    }
    cout<<MAX;
    return 0;
}