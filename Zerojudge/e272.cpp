#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define M vector<vector<ll>  >
ll dp[10005];
M base;
base.resize(2,vector<ll>(2,1));
base[1][1]=0;
inline M m(M a,M b){
	M ret;
	ret.resize(2,vector<ll>(2));
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				ret[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return ret;
}
inline M sub(int n){
	if(n==1) return base;
	if(n%2==0){
		M temp=sub(n-2);
		return m(temp,temp);
	}
	return m(sub(n-1),base);
}
int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	vector<pair<int,int> > vec;
	int a,b;
	while(cin>>a>>b){
		Max=max(Max,max(a,b));
		vec.push_back({a,b});
	}
	return 0;
}
