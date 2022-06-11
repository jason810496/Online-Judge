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
const int MAX_N = 1e6+5;
const int INF = 1e9;

int M[MAX_N];
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& opers) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            M[ nums[i] ] = i ;
        }

        for(auto &op : opers){
            nums[ M[op[0]] ] = op[1];
            M[ op[1] ] = M[ op[0] ];
        }

        return nums;
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

    // Change();

    vi t1 = {1,2,4,6};
    vvi o1 = {{1,3},{4,7},{6,1}};

    vi t2 = {955023,61609,985051,483419,488159,604775,681716,139904,371285,545875,541524,911390};
    vvi o2 = {{681716,929392},{139904,102523},{604775,790401},{911390,167034},{955023,795605},{929392,574783},{102523,176821},{488159,94366},{176821,546283},{985051,425354},{545875,228080},{546283,132911},{795605,242594}};
    auto res = solve.arrayChange( t2 ,o2 );

    for(auto i:res){
        cout<<i<<' ';
    }
    return 0;
}

/*

[955023,61609,985051,483419,488159,604775,681716,139904,371285,545875,541524,911390]
[[681716,929392],[139904,102523],[604775,790401],[911390,167034],[955023,795605],[929392,574783],[102523,176821],[488159,94366],[176821,546283],[985051,425354],[545875,228080],[546283,132911],[795605,242594]]
*/

/*
[322474,44515,963015,769263,667883,487327,947810,955751,802848,496550,141902,995977,468103,959591,579715,778874,325747,601618,434480,901995,187129,800242,6664,918338,319769,242876,573889,625331,265296,165060,354324,162031,490009,38494,788451,774837,392156,9147,915858,627013,456389,955942]
[[625331,376064],[322474,656562],[265296,919737],[955751,322578],[656562,627114],[141902,727205],[901995,713332],[918338,363629],[778874,976303],[6664,7877],[727205,875704],[800242,323467],[325747,492925],[354324,908896],[456389,2202],[187129,367823],[165060,332697],[367823,258654],[492925,621485],[627013,627566],[487327,982233],[627566,529835],[496550,859011],[242876,260319],[959591,222501],[788451,769496],[529835,893573],[915858,726873]]
*/