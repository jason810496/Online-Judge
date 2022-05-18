#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long

const int MX_N = 200005;
ll ans=0;
int sum[MX_N]={},item[MX_N]={};
int n , m ;
int main(){
	OAO	
	int s,f,v;

	cin>>n>>m;
	while(m--){
		cin>>s>>f>>v;
		sum[s]+=v;
		sum[f+1]-=v;
	}

	vector<int> vec;

	for(int i=0;i<n;i++) cin>>item[i];
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
		vec.push_back(sum[i]);
	}

	sort(vec.begin(),vec.end());
	sort(item,item+n,greater<int>());

	ll ans=0;


	for(int i=0;i<n;i++){
		ans+=item[i]*vec[i];
	}


	cout<<ans;
	return 0;
}
