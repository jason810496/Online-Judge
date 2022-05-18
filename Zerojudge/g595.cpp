#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int arr[105]={};

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);

	int n , ans=0; cin>>n;


	arr[0]=arr[n+1]=INF;

	for(int i=1;i<=n;i++) cin>>arr[i];

	for(int i=1;i<=n;i++) ans+=(!arr[i] ? min(arr[i-1],arr[i+1]) : 0);

	cout<<ans;
}
