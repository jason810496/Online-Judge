#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define all(x) x.begin(),x.end()
#define ll long long 

typedef pair<int,int> pii;

const int INT = 1e9;

/*
    AC : Sliding Window 
*/

int main(){
    OAO
    int n , L ;

    cin>>n>>L;
    vector<pii> vec(n);


    for(auto &i:vec){
        cin>>i.F;
    }
    for(auto &i:vec){
        cin>>i.S;
    }

    sort(all(vec)); // sort by x

    int ans=0 ; 
    deque<pii> Min , Max ;
    Min.push_back( vec[0] );
    Max.push_back( vec[0] );
    for(int i=1;i<n;i++){
        int X = vec[i].F;
        int Y = vec[i].S;

        while( Min.size() && Min.front().F < X-L) Min.pop_front();
        while( Max.size() && Max.front().F < X-L) Max.pop_front();

        while( Min.size() && Min.back().S > Y) Min.pop_back();
        while( Max.size() && Max.back().S < Y) Max.pop_back();

        Min.push_back( vec[i] );
        Max.push_back( vec[i] );

        ans = max( ans ,Max.front().S - Min.front().S );
    }

    cout<<ans;
    return 0;
}