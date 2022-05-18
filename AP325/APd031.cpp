#include<bits/stdc++.h>
/*
	binary searh (set )
	AC 
*/
#define ll long long 
#define N 200005
using namespace std;
int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	int cur,n,K,cnt,ans=INT_MAX;cin>>n>>K;
	bool flag=false;
	ll Prefix[N] ;Prefix[0]=0;
	set<ll> s;
	for(int i=1;i<=n;i++){
		cin>>cur;
		Prefix[i]=cur+Prefix[i-1];
		s.insert(Prefix[i]);
	}

	for(int i=0;i<=n;i++){
		//Prefix[i] + K <= Prefix[j]
		ll target = Prefix[i]+K,D;
		auto it=s.lower_bound(target);
		if(*it==target){
			if(flag) cnt++;
			else{
				flag=true;
				ans=K;
				cnt=1;
			}
		}
		else{
			it--;
			D=*it-Prefix[i];
			if(ans==INT_MAX||(K-ans)>(K-D)){
				ans=D;
				cnt=1;
			}
			else if(D==ans)cnt++;
		}

		//cout<<D<<' '<<ans<<' '<<cnt<<'\n';

	}

	cout<<ans<<'\n'<<cnt;
	return 0;
}
