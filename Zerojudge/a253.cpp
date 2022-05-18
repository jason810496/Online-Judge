#include<bits/stdc++.h>
// AC
using namespace std;
int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	int a,b;
	map<int,long long > M;
	while(cin>>a&&a!=-1){
		cin>>b;	
		if(M.find(a)!=M.end()){
			M[a]+=b;
		}else M[a]=b;
	}

	while(cin>>a&&a!=-1){
		cin>>b;	
		if(M.find(a)!=M.end()){
			M[a]+=b;
		}else M[a]=b;
	}
	for(auto i:M){
		cout<<i.first<<' '<<i.second<<'\n';
	}
	return 0;
}
