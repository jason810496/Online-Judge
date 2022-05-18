#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define F first
#define S second
/*
80 % AC
*/
int n,limit,y,MAX_d=0;
deque<int> min_dq,max_dq;
map<int,int > M;
void add_min(int i){
    while(min_dq.size()&&M[min_dq.back()]>M[i]) min_dq.pop_back();
    min_dq.push_back(i);
}
void add_max(int i){
    while(max_dq.size()&&M[max_dq.back()]<M[i]) max_dq.pop_back();
    max_dq.push_back(i);
}
int main(){
    ifstream in("Q_3_13_4.in");
    ofstream out("output01.out");
    in>>n>>limit;

    int x_arr[N];
    for(int i=0;i<n;i++) in>>x_arr[i];
    for(int i=0;i<n;i++){
        in>>y;
        M[x_arr[i]]=y;
    }
    int cur_x;
    for(auto i:M){
        cur_x=i.F;
        while(min_dq.size()&&(min_dq.front()+limit<=cur_x)) min_dq.pop_front();
        while(max_dq.size()&&(max_dq.front()+limit<=cur_x)) max_dq.pop_front();
        add_min(cur_x);
        add_max(cur_x);

        MAX_d=max(MAX_d,M[max_dq.front()]-M[min_dq.front()] );
        out<<max_dq.front()<<' '<<min_dq.front()<<' '<<M[max_dq.front()]-M[min_dq.front()]<<'\n';
    }
    out<<MAX_d;

    return 0;
}