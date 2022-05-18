#include<iostream>
#include<algorithm>
#define N 50005
using namespace std;
/*
AC hard
binary search + greedy
*/
int Pos[N],n,k;
bool enough(int R){
    int End_Pos=Pos[0]+R ,cnt=1;
    for(int i=1;i<n;i++){
        while(Pos[i] >End_Pos){
            End_Pos= Pos[i]+R;
            cnt++;
        }
    }
    return (cnt<=k);
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>Pos[i];
    sort(Pos,Pos+n);

    int cur_len=0, Total_len=Pos[n-1]-Pos[0];
    for(int Jump=Total_len/2 ;Jump>0 ;Jump/=2){
        while( cur_len+Jump<Total_len && !enough(cur_len+Jump)){
            cur_len+=Jump;
        }
    }
    cout<<cur_len+1;
    return 0;
}