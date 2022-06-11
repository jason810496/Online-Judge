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
    int minMaxGame(vector<int>& arr) {
        vi temp;
        int n = arr.size();
        while( arr.size()>1){
            int t=n/2 , f=1;
            for(int i=0;i<t;i++){
                if( f ){
                    temp.PB( min( arr[i*2] ,arr[i*2+1] ) );
                }
                else temp.PB( max( arr[i*2] ,arr[i*2+1] ) );
                f^=1;
            }
            n>>=1;
            arr=temp;
            temp.clear();
        }
        return arr.back();
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