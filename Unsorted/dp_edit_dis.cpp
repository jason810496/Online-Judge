#pragma GCC optimize("02")
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define range(x) x.begin(),x.end()
#define ll long long 
#define PB push_back
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);

const int MAX_N = 1e5+5;
const int INF = 1e9+5;
typedef pair<int,int> pii;

inline bool comp(const int &a,const int &b){
	return a<b;
}

struct Comparator{
	bool operator()(const int &a,const int &b){
		return a<b;
	}

};
int main(){
	OAO

	int Insert=1,Replace=1,Remove=1;
	priority_queue<int,vector<int> , Comparator> pq;
	string A,B;
	int n=A.size() , m=B.size();
	vector<vector<int> > dp(n+5,vector<int>(m+5,0));

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0){
				dp[i][j]=j*Insert;
			}
			else if(j==0){
				dp[i][j]=i*Insert;
			}
			else if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1];
			else{
				dp[i][j]=min(
					dp[i-1][j-1]+Replace,
					min(
						dp[i-1][j]+Remove,
						dp[i][j-1]+Insert
					)
				
				);
			}
		}
	}

	cout<<dp[n][m];

	cout<<"test";
	return 0;
}
