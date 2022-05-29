#include<bits/stdc++.h>
using namespace std;



#define F first
#define S second
#define ll long long 
#define all(x) x.begin(),x.end()
#define PB push_back
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
typedef pair<int,long long> pil;

const int MAX_N = 100005;
const int INF = 1e9;

class Solution {
public:
    

    
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

    Solution solve;

    Change();
    return 0;
}