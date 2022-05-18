#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long 
/*
AC
by stack
Reference:
https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/1394705/C%2B%2B-Solution-using-stack-based-on-a-good-explanation-video 

*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    ll n,H[N];cin>>n;
    for(ll i=0;i<n;i++) cin>>H[i];
    stack<ll> stk_index,stk_height;
    ll MAX=0;
    stk_index.push(0);
    stk_height.push(H[0]);
    for(ll i=1;i<n;i++){
        if(stk_height.size()&&H[i]<stk_height.top()){
            ll id,hi;
            while(stk_height.size() && H[i]<stk_height.top() ){
                id=stk_index.top(); stk_index.pop();
                hi=stk_height.top(); stk_height.pop();

                MAX=max(MAX,(i-id)*hi);
                
            }
            stk_index.push(id);
        }
        else stk_index.push(i);
        stk_height.push(H[i]);

    }
    while(stk_index.size() ) {
        MAX=max(MAX,(n-stk_index.top())*stk_height.top() ) ;
        stk_index.pop();
        stk_height.pop();
    }

    cout<<MAX;
    return 0;
}