#include<bits/stdc++.h>
/*

Link List AC
*/
using namespace std;
#define N 100005
struct node{
	int pre,next,hight,pos;
	bool live=true;
}arr[N];

queue<int > q;	
void can_remove(int cur_i){
	if(!arr[cur_i].live) return ;
	int Pre=arr[cur_i].pre;
	int Next=arr[cur_i].next;
	int Hight=arr[cur_i].hight;
	int Pos=arr[cur_i].pos;
	if(Pos+Hight<=arr[Next].pos || Pos-Hight>=arr[Pre].pos){
		q.push(cur_i);
		arr[Next].pre=Pre;
		arr[Pre].next=Next;
		arr[cur_i].live=false;
	}
	return ;
}
int n,R,MAX_H=0,cnt=0;
int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>n>>R;
	//init border 
	arr[0].pos=0,arr[n+1].pos=R;
	arr[0].live=false, arr[n+1].live=false;
	for(int i=1;i<=n;i++){
		cin>>arr[i].pos;
		arr[i].pre=i-1, arr[i].next=i+1;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i].hight;
	}
	for(int i=1;i<=n;i++){
		can_remove(i);
	}

	while(q.size()){
		int  cur=q.front()	;
		q.pop();
		//cout<<cur<<' '<<arr[cur].hight<<'\n';
		MAX_H=max(MAX_H,arr[cur].hight);
		cnt++;
		can_remove( arr[cur].pre);
		can_remove(arr[cur].next);
	}

	cout<<cnt<<'\n'<<MAX_H;
	return 0;
}
