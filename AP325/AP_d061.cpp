#include<iostream>
#include<vector>
#include<algorithm>
#define L first
#define R second
using namespace std;
typedef pair<int,int> pii;
/*
reference
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;cin>>n;
    pii Range;
    cin>>Range.L>>Range.R;
    vector<pair<int,int> > vec(n);
    for(auto &i:vec) cin>>i.L>>i.R;

    sort(vec.begin(),vec.end());

    int Endline=0,cnt=0;
    for(int i=0;i<n;i++){
        if(vec[i].L <= Range.L ){
            Endline= max(Endline , vec[i].R);
        }
        else{
            if(vec[i].L > Endline){
                cnt=-1;
                break ;
            }

            Range.L =Endline;
            cnt++;
            Endline= max(Endline, vec[i].R);
        }
    }
    cout<<( cnt==-1 ? cnt+(Endline>=Range.R):cnt )<<'\n'; 
    return 0;
}