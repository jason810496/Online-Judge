#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define N 100005
#define ll long long
typedef pair<long long,long long> pll;
/*
AC
sort by endtime of every line

*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,s,e;
    cin>>n;
    vector<pll> vec(n);
    for(auto &i:vec){
        cin>>s>>e;
        i.first=e;
        i.second=s;
    }
    sort(vec.begin(),vec.end());
    ll End=-1;
    int cnt=0;
    for(auto i:vec){
        if(i.second > End){
            cnt++;
            End=i.first;
        }
    }
    cout<<cnt;
    return 0;   
}