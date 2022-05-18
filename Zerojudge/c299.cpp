#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
typedef pair<int,int> pii;
const int MAX_N = 1e9+5;
const int INF = 1e9;


// AC
int main(){
    int n,Min=INF,Max=-INF,sum=0; 

    while(cin>>n){
        sum=0,Min=INF,Max=-INF;
        vector<int> vec(n);
        for(int &i:vec){
            cin>>i;
            sum+=i;
            Min=min(Min,i);
            Max=max(Max,i);
        }
        // n*(n+1)/2
        int target=Min*n+n*(n-1)/2;

        cout<<Min<<" "<<Max<<" "<<(target==sum ? "yes\n":"no\n");
    }
    

    return 0;
}