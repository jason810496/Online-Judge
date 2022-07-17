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

/*********************************************************
    Greedy + Binary Index Tree

    Greedy : Choose all '0' then insert '1' from the right

    Binary Index Tree : get 'rank' if current choose '1'

    ( 'rank' : how much elements are located in right of current choosed '1' )

*********************************************************/

/*********************************************************
    Example : 
        s = "1001010", k = 5

        1. choose all '0' : "0000"
        2. start insert '1' into current subsequence :
            seq : "0000"
            str :"1001010"
                       ^
            the most right '1'

        3. get rank of '1'
            seq : "0000"
            str :"1001010"
                       ^
                    rk : 1
        (   seq' : "00010" , only 1 element at the right of current choosed '1' , so the 'rk'=1 )

        4. the value after inserted '1' into sequence :
            value = value + (1<<rk)

        insert '1' into sequence until the sum of sequence > k
    
*********************************************************/

class Solution {
public:

    #define ll long long

    #define lowbit(x) x&-x
    void Update(vector<int> &BIT,int idx){
        for(int i=idx;i<BIT.size();i+=lowbit(i)){
            BIT[i]+=1;
        }
    }

    int Query(vector<int> &BIT,int idx){
        int ans=0;
        for(int i=idx;i;i-=lowbit(i)){
            ans+=BIT[i];
        }
        return ans;
    }

    int longestSubsequence(string s, int k) {
        int n = s.size();

        // Binary Index Tree
        vector<int> BIT(n+5);

        ll Limit = k;

        // varible that store len of seq
        int cnt=0;
        for(int i=0;i<n;i++){
            if( s[i]=='0'){
                Update(BIT,i+1);
                cnt++;
            }
        }

        // avoid overflow 
        ll cur=0;

        for(int i=n-1;i>=0;i--){
            if( s[i]=='0' ) continue;

            // rank = 'sequence len' - 'total element at the left'
            int rk = cnt - Query(BIT,i+1);
            // k < 1e9 < 2^32 , so that rk must < 32
            if( rk>32 ) break;

            if( (cur+ (1<<rk)) > Limit ) break;

            // update sum of seq
            cur += 1<<rk;
            cnt++;
            Update(BIT,i+1);
        }

        return cnt;
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