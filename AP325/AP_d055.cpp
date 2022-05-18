#include<bits/stdc++.h>
#define N 100005
/*
AC sweep line
*/
using namespace std;
struct Point{
    int x,y;
}Line[N];

inline bool comp(Point a,Point b){
    return a.x < b.x;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>Line[i].x;
    for(int i=0;i<n;i++) cin>>Line[i].y;
    sort(Line,Line+n,comp);
    stack<int> stk;

    for(int i=0;i<n;i++){ //for each x
        while( stk.size() && Line[i].y >= Line[stk.top()].y ){
            stk.pop();
        }

        stk.push(i);
    }
    cout<<stk.size();
    return 0;
}