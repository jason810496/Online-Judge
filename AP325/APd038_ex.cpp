#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
ll pos[100005],ans=0;

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    // ifstream Cin("/home/jason/Desktop/ap325_release/ch3/Q_3_14_1.in");
    // ofstream Cout("/home/jason/Desktop/Cpp test/output01.txt");
    //if(Cin.is_open()){
        //cout<<"open\n";
        int N,m;cin>>N>>m;
        //cout<<N<<m;
        vector<pii> Line(N);
        
        
        for(auto &i:Line){
            //cin>>i.first>i.second;
            cin>>i.first>>i.second;
        }
        
        for(int i=0;i<m;i++) cin>>pos[i];
        for(int i=0;i<m;i++){
            ll cur_max=INT_MIN;
            for(auto cur:Line){
                cur_max=max(cur_max, cur.first*pos[i]+cur.second);
            }
            ans+=cur_max;
            //cout<<ans<<'\n';
            cout<<ans<<'\n';
        }
        cout<<ans<<'\n';
    //}
    
    return 0;
}
/* ex
7
12
15
17
18
18
19
21
24
29

*/