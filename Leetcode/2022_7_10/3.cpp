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
const int INF = 1e9;

class Solution {
public:
    bool canChange(string start, string target) {
        int n  = start.size();
        vector<int> LList , RList ; 
        vector<int> Lt , Rt;
        for(int i=0 ;i<n;i++){
            if( start[i]=='R' ) RList.push_back( i );
            else if( start[i]=='L') LList.push_back( i );
        }
        for(int i=0;i<n;i++){
            if( target[i]=='R' ) Rt.push_back( i );
            else if( target[i]=='L') Lt.push_back( i );
        }

        int cntL = LList.size() , cntR = RList.size();
        if( cntL!=Lt.size() || cntR!=Rt.size() ) return false;

        for(int i=0;i<cntL;i++){
            if(Lt[i]>LList[i] ) return false;
        }

        for(int i=0;i<cntR;i++){
            if( Rt[i]<RList[i]  ) return false;
        }

        int cntStartR=0 , cntTargetR=0;

        for(int i=0,l1=0,l2=0;i<n;i++){
            if( start[i]=='R' ) cntStartR++;
            if( target[i]=='R') cntTargetR++;

            if( start[i]=='L') LList[l1++]=cntStartR;
            if( target[i]=='L') Lt[l2++]=cntTargetR;
        }

        for(int i=0;i<cntL;i++){
            if(LList[i]!=Lt[i] ) return false;
        }

        return true;
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

    vi t1 = {1,3,5,2,4,8,2,2};
    cout<<solve.minMaxGame(t1);
    return 0;
}