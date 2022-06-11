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
    bool strongPasswordCheckerII(string pwd) {
        int n =pwd.size();
        if( n<8 ) return false;
        bool lower=0, upper=0 , digit=0, spec=0 , adj=1;
        string ss = "!@#$%^&*()-+";

        int i=0;
        for(char c:pwd){
            if( 'a'<= c && c<='z' ) lower=1;
            if( 'A'<= c &&  c<='Z') upper=1;
            if( isdigit(c) ) digit=1;
            
            for(char s:ss){
                if(s==c){
                    spec=1;
                    break;
                }
            }
            if(i!=0){
                if(pwd[i]==pwd[i-1]){
                    adj=0;
                    break;
                }
            }
            i++;
        }

        return lower&&upper&&digit&&spec&&adj;
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