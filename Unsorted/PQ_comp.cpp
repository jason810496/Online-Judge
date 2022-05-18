#include<bits/stdc++.h>
using namespace std;

struct Type{
    int val ;
    Type(int v=0){
        val=v;
    }
};

struct Comparator{
    bool operator() (const Type &a,const Type &b){
        return a.val < b.val;
    }
};

int main(){
    srand(time(NULL));
    // cin.tie(0);ios_base::sync_with_stdio(0);
    int arr[101];
    priority_queue< Type ,vector<Type> ,Comparator > PQ_struct; 
    
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<int> > PQ_pair;
    for(int i=0;i<10;i++){
        arr[i]=rand()%10+1;
        cout<<arr[i]<<' ';
        PQ_struct.push(arr[i]);
    }
    cout<<'\n';

    while(PQ_struct.size() ){
        cout<< PQ_struct.top().val <<" ";
        PQ_struct.pop();
    }


    return 0;
}