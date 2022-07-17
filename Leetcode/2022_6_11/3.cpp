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

    int N = 1001;
    int BIT[1005];
    #define low(x) x&-x
    #define ll long long 

    void Add(int idx){
        for(int i=idx;i<=N;i+=low(i)){
            BIT[i]+=1;
        }
    }

    int Query(int idx){
        int ans=0;
        for(int i=idx;i;i-=low(i)){
            ans+=BIT[i];
        }

        return ans;
    }

    int longestSubsequence(string s, int k) {
        int n = s.size();
        // cout<<s<<" "<<k<<"\n";
        N = n;
        memset(BIT,0,sizeof(BIT) );

        ll K = k;

        set<int> St;
        for(int i=0;i<n;i++){
            if( s[i]=='0'){
                St.insert( i );
                Add(i+1);
            }
        }

        int mx = St.size() , cnt = mx;

        ll cur=0;

        for(int i=n-1;i>=0;i--){
            if( s[i]=='0' ) continue;

            int rk = cnt - Query(i+1);
            if( rk>32 ) break;
            // cout<<"rk : "<<rk<<"\n";
            // cout<<"1<<rk: "<< (1<<rk) <<"\n";

            if( (cur+ (1LL<<rk)) > K ) break;

            cur += 1<<rk;
            Add(i+1);
            mx++;
            cnt++;
            
        }

        // cout<<" cur : "<<cur<<"\n";
        return mx;
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
    string t1 = "1001010" , t2 = "00101001" , t3 = "001010101011010100010101101010010";
    cout<<"\n ans : \n "<<solve.longestSubsequence(t1,5)<<"\n";
    cout<<"\n ans : \n "<<solve.longestSubsequence(t2,1)<<"\n";
    cout<<"\n ans : \n "<<solve.longestSubsequence(t3,93951055)<<"\n";
    return 0;
}