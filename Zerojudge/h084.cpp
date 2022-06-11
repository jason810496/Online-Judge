#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define pii pair<int,int>
#define F first
#define S second

const int N = 200005;


int n , k ;
ll arr[N];
int Line[5005];

bool check(ll ht){
	int len=0 , idx=1;

	for(int i=1;i<=n && idx<=k;i++){
		if(arr[i] >= ht ){
			len++;
		}
		else len=0;

		if( len >= Line[ idx ] ){
			idx++;
			len=0;
		}
	}

	return (idx>k) ;
}

int main(){

	OAO
	ll Mx_ht=0;

	cin>>n>>k;

	for(int i=1;i<=n;i++){ 
		cin>>arr[i];
		Mx_ht = max( Mx_ht , arr[i]);
	}
	for(int i=1;i<=k;i++){
		cin>>Line[i];
	}

	ll L = 1 , R = Mx_ht;

	while( L <= R ){
		
		ll mid = (R+L)/2 ;
		if( check(mid)) {
			L=mid+1;
			// cout<<" OK : "<<mid<<"\n";
			//cout<<"mid+1 "<< mid <<"\n";

		}
		else{
			R= mid-1;
			// cout<<" NO : "<<mid<<"\n";
			//cout<<"mid-1 "<< mid <<"\n";
		}
	}

	cout<<L-1;
	return 0;
}
