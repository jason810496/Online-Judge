#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) X&-x
const int MAX_N = 1e3+5;
int T[MAX_N] , arr[MAX_N];
int n;

void init(){
    for(int i=1;i<=n;++i){
        T[i]+=arr[i];
        int j=i+lowbit(i);
        if(j<=n ) T[j]+=T[i];
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    return 0;
}