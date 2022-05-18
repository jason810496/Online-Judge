#include<iostream>
#define ll long long 
#define N 100005
using namespace std;
ll H[N];
/*
unfinish
D&C

Concept:
1. have current block
2. don't have current block
   2.1. MAX rect at right side
   2.2. MAX rect at left side
*/
ll Combine_Rect(int L,int mid,int R){
    int i=mid,j=mid+1;
    ll area=0, height=min(H[i],H[j]);
    

    while(i>=L && j<= R){
        height=min( min(H[i],H[j]), height );
        area=max(area , (j-i+1)*height );
        if(i==L) j++;
        else if(j==R) i--;
        else{
            if(H[i-1] > H[j+1]) i--;
            else j++;
        }
    }
    return area;
}
ll Large_Rect(int L,int R){
    if(L==R) return H[L];
    int mid=L+(L+R)>>1;
    //           max from left half , max from right half
    ll Outer=max( Large_Rect(L,mid), Large_Rect(mid+1,R));

    return max(Outer, Combine_Rect(L,mid,R));
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>H[i];
    cout<<Large_Rect(0,n-1);
    return 0;
}