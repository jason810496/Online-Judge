#include<iostream>
#define N 100005
#define ll long long
using namespace std;
/*
AC
sometime buggy
*/
ll Inversion(int *arr,int L,int R){
    if(R-L<=1 ) return 0;
    int M=(L+R)/2;
    ll Sum=Inversion(arr,L,M)+Inversion(arr,M,R),inv=0;
    int temp[R-L] , j=M , cur=0 ;
    for(int i=L;i<M;i++){
        while( j<R && arr[j]<arr[i] ){
            temp[cur++]=arr[j++];
        }
        temp[cur++]= arr[i];
        inv+=j-M; // cur inversion 
    }

    for(int i=L ;i<j;i++){
        arr[i]=temp[i-L];
    }
    return Sum+inv;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,arr[N];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<Inversion(arr,0,n);
    return 0;
}