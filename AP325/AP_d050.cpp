#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int Start,End,n; 
    cin>>n;
    vector<pair<int,int> > vec(n);
    for(auto &i:vec){
        cin>>Start>>End;
        i={Start,End};
    }

    sort(vec.begin(),vec.end());
    pair<int,int > Last=vec[0];
    ll total=0;
    for(auto seg:vec){
        if(seg.first > Last.second){
            total+=Last.second-Last.first;
            Last=seg;
            continue;
        }

        Last.second=max(Last.second,seg.second);
    }
    total+= Last.second-Last.first;
    cout<<total;
    return 0;
}