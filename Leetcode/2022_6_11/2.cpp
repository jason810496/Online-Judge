#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);


#define F first
#define S second
#define ll long long 
#define all(x) x.begin(),x.end()
#define PB push_back
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
typedef pair<int,long long> pil;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
const int MAX_N = 100005;


class Solution {
public:
    const int INF = 1e9;
    int minimumNumbers(int num, int k) {

        vector<int> coin , dp(num+1,INF);
        for(int v=k;v<=num;v+=10){
            coin.push_back( v );
        }

        dp[0]=0;

        for(int v=1;v<=num;v++){
            for(int &c:coin){
                if( c<=v ){
                    if( dp[v-c]!=INF){
                        dp[v]=min( dp[v] , dp[v-c]+1 );
                    }
                }
            }
        }

        // cout<<"dp[num] : "<<dp[num]<<"\n";
        return (dp[num]==INF ? -1:dp[num] );
    }
};


void Change(){
    string str;
    getline(cin,str);

    for(char i:str){
        if( i=='[') cout<<'{';
        else if(i==']') cout<<'}';
        else cout<<i;
    }
    cout<<'\n';
}




int main(){
    //OAO

    Solution solve;

    cout<<solve.minimumNumbers(3,3);
    cout<<solve.minimumNumbers(20,1);
    return 0;
}