#include<iostream>
#define ll long long 
/*
 AC Sliding Window
*/
using namespace std;
int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);

	int n,K,arr[200005];cin>>n>>K;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int L,R,ans=0,cnt=0;
	for(L=0,R=0;R<n;R++){
		sum+=arr[R];
		while(sum>K){
			sum-=arr[L++];
		}
		if(sum>ans){
			ans=sum;
			cnt=1;
		}
		else if (sum==ans) cnt++;
	}
	cout<<ans<< '\n'<< cnt;
	return 0;
}
