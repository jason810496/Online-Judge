#include<bits/stdc++.h>
using namespace std;


int n,K,MAX_D,D,arr[200005];
deque< int > max_dq , min_dq ;
inline void Add_min(int cur){
	while(min_dp.size() && cur >= arr[min_dq.back()] <= cur ){
		min_dp.pop_back();
	}
	min_dp.push_back(cur);
}
int main(){
	cin.tie(0);ios_base::sync_with_stdio(0):

	return 0;
}
