#include<iostream>
using namespace std;
#define T int

void Merge(T *L1,T *R1,T *L2,T *R2){
	int n1=R1-L1 , n2=R2-L2 ,N =n1+n2,i1=0,i2=0,j=0,ret[N];
	for(;i1<n1 && i2<n2 ; j++){
		if(L1[i1]<=L2[i2]) ret[j]=L1[i1++];
		else ret[j]=L2[i2++];
	}
	for(;i1<n1;i1++,j++) ret[j] = L1[i1];
	for(;i2<n2;i2++,j++) ret[j] = L2[i2];
	for(int i=0;i<N;i++) L1[i] = ret[i];
}

void Sort(T *L,T *R){
	int N=R-L,mid=N/2,temp[N];
	if(R-L<=0) return ;
	Sort(L,L+mid);	
	Sort(L+mid+1,R);
	Merge(L,L+mid,L+mid+1,R) ;
}

int main(){
	srand(time(NULL));
	int n,arr[10];
	for(int i=0;i<10;i++){
		arr[i]=rand()%100+1;
	}
	Sort(arr,arr+10);
	for(int i=0;i<10;i++){
		cout<<arr[i]<<' ';
	}
	return 0;
}
