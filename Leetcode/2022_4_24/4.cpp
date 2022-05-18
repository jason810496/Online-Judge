#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INF = 1e9;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();

        cout<<n<<'\n';
        sort(range(flowers));
        vector<int> temp(people);

        sort(range(temp));
        temp.resize(unique(range(temp))-temp.begin());

        unordered_map<int,int> M;

        int L_idx = 0;
        int Contain=0;

        priority_queue< int , vector<int> , greater<int> > pq;
        vector<int> ans;
        for(int &posX : temp){
            // while( L_idx < n && flowers[L_idx][1] < posX ){
            //     L_idx++;
            // }
            while( pq.size() && pq.top() < posX ){
                pq.pop();
                Contain--;
            }
            while( L_idx < n && flowers[L_idx][0]<=posX ){
                if( flowers[L_idx][1] < posX ){
                    L_idx++;
                    continue;
                }
                pq.push( flowers[L_idx][1] );
                L_idx++;
                Contain++;
            }

            // people[ t.S ] = Contain;

            M[ posX ] = Contain;
        }
        cout<<L_idx<<'\n';

        for(int &i:people){
            i=M[i];
        }
        return people;
    }
};

/*
Input:
[[50,50],[36,49],[6,16],[21,38],[43,44],[48,50],[28,40],[30,33]]
[6,44,13,48,6,11,1,35]
Output:
[1,2,1,2,1,1,0,3]
Expected:
[1,2,1,2,1,1,0,2]


*/