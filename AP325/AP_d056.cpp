#include<bits/stdc++.h>
#define N 100005
#define F first
#define S second
using namespace std;
/*
cloest pair (hard) by sweep line

*/
struct Point{
    int x,y;
}P[N];

inline bool comp(Point a,Point b){
    return a.x < b.x;
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>P[i].x;
        cin>>P[i].y;
    }

    sort(P,P+n,comp);
    multimap<int,int > Map; // Map[y]=x  (y,x) ,sorted by y
    int Min_d=200000000;
    for(int i=0;i<n;i++){ // for all x from l to r
        // check [P.y-MIN_D , P.y+MIN_D ]
        auto it=Map.lower_bound( P[i].y-Min_d );
        while(it!=Map.end() && it->F <= P[i].y+Min_d ){

            if(it->S < P[i].x - Min_d){// x is too small 
                it=Map.erase(it);
                continue;
            }

            Min_d=min(Min_d, abs(P[i].x-it->S)+abs(P[i].y-it->F));
            it++;
        }

        Map.insert( {P[i].y, P[i].x} );
    }
    cout<<Min_d;
    return 0;
}