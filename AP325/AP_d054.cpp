#include<iostream>
#define ll long long
using namespace std;
/*

done
AC
b-search
hard

*/
int n,m;
int prefix=0,arr[100005];

bool Enough(int L){
    int Energy=L;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(Energy< arr[i]){
            Energy=L;
            cnt++;
        }
        Energy-=arr[i];
        
        if(Energy < 0) return false;
    }

    return (cnt<=m);
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prefix+=arr[i];
    }
    int len=0;
    for(int jump=prefix/2; jump ; jump/=2){
        while( len+jump < prefix && !Enough(len+jump) ){
            len+=jump;
            // cout<<len<<'\n';
        }
        
    }
    cout<<len+1;
    return 0;
}