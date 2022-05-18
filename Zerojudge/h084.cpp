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
	vector<int> vec;

	int len=0;

	for(int i=1;i<=n;i++){
		if(arr[i] >= ht ){
			len++;
		}
		else{
			if(len>0) vec.push_back(len);
			len=0;
		}
	}

	if(len>0) vec.push_back(len);
	
	//cout<<"check\n";
	/*for( auto it :vec ){
		cout<<it<<' ';
	}
	cout<<'\n'; */
	while(vec.size()>=k){
		
		int sz=vec.size();
		bool tag=true;
		for(int i=0;i<k;i++){
			if(vec[sz-i-1]<Line[k-i]){
				vec.pop_back();
				tag=false;

				break;
			}
		}
		//cout<<"t\n";
		if(tag)return true;
	}

	return false;
}

int main(){

	OAO
	ll Mx_ht=0;

	cin>>n>>k;

	for(int i=1;i<=n;i++){ 
		cin>>arr[i];
		Mx_ht = max( Mx_ht , arr[i]);
	}
	for(int i=1;i<=k;i++){ cin>>Line[i]; }

	ll L = 1 , R = Mx_ht;

	while( L <= R ){
		
		ll mid = L+(R-L)/2;
		if( check(mid)) {
			L=mid+1;
			//cout<<"mid+1 "<< mid <<"\n";

		}
		else{
			R= mid-1;
			//cout<<"mid-1 "<< mid <<"\n";
		}
	}

	cout<<L-1;
	return 0;
}
