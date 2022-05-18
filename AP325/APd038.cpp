#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define M 50005
typedef pair<int,int > pii;
int cur_line=0,X_pos[M];
long long N,m,cur_x,cur_val,next_val,ans=0;
inline bool cmp(pii a,pii b){
    return a.F<b.F ? 1 : (a.F==b.F ? a.S>b.S:0);
}
inline bool cmp2(int a,int b){
    return a<b;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>N>>m;
    vector<pii> Line(N);
    for(auto &i:Line) cin>>i.F>>i.S;
    for(int i=0;i<m;i++) cin>>X_pos[i];
    sort(Line.begin(),Line.end(),cmp);
    sort(X_pos,X_pos+m,cmp2);
    
    for(int i=0;i<m;i++){
        cur_x=X_pos[i];

        cur_val=Line[cur_line].F*cur_x +Line[cur_line].S;
        
        if(cur_line+1!=N){
            next_val=Line[cur_line+1].F*cur_x +Line[cur_line+1].S;
        }
        else next_val=INT_MIN;

        while(next_val>=cur_val&&cur_line+1!=N){
            cur_val=next_val;
            next_val=Line[cur_line+1].F*cur_x +Line[cur_line+1].S;
            cur_line++;
        }
        ans+=cur_val;
        cout<<ans<<'\n';
    }
    
    cout<<ans;
    return 0;
}
/*
4 10
-1 0
1 0
-2 -3
2 -3
-5 -4 -3 -2 -1 0 1 2 3 4

//23

*/


/*
7
12
15
13
12
12
13
15
18
23

*/