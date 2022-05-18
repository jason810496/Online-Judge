/*
 ██████╗ ██████╗ ██████╗ ███████╗     ██████╗ ██╗   ██╗████████╗
██╔════╝██╔═══██╗██╔══██╗██╔════╝    ██╔═══██╗██║   ██║╚══██╔══╝
██║     ██║   ██║██║  ██║█████╗      ██║   ██║██║   ██║   ██║   
██║     ██║   ██║██║  ██║██╔══╝      ██║   ██║██║   ██║   ██║   
╚██████╗╚██████╔╝██████╔╝███████╗    ╚██████╔╝╚██████╔╝   ██║   
 ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝     ╚═════╝  ╚═════╝    ╚═╝   
                                                                
 █████╗  ██████╗    ██╗███╗   ██╗                               
██╔══██╗██╔════╝    ██║████╗  ██║                               
███████║██║         ██║██╔██╗ ██║                               
██╔══██║██║         ██║██║╚██╗██║                               
██║  ██║╚██████╗    ██║██║ ╚████║                               
╚═╝  ╚═╝ ╚═════╝    ╚═╝╚═╝  ╚═══╝                                                                                                                                                                            
*/
#pragma GCC optimize("O2")
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<sstream>
#include<limits>
#include<math.h>
#include<unordered_map>
#include <iomanip>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INF = 1e9;

int K=0;
unordered_map<string,int> H;

inline void dd(string s){
    if(H.find(s)==H.end()) H[s]=K++;
}
signed main(){
    OAO

    int n;cin>>n;
    
    vector<int> vec;
    string str;
    cin>>str;

    for(int i=0;i<4;i++){
        getline(cin,str);
        
        bool flag=false;
        for(auto &i:str){
            if(i==','){
                flag=true;
                i=' ';
                break;
            }
        } 

        stringstream ss(str);

        string a,b;
        if(flag){ 
            ss>>a>>b;
            dd(a);
            dd(b);
        }
        else{
            ss>>a;
            dd(a);
        }
    }

    for(auto i:H){
        cout<<i.F<<' '<<i.S<<'\n';
    }
    return 0;
}
