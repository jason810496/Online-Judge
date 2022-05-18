
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);


int main(){
    OAO
    string raw,str;
    getline(cin,raw);
    int n; 
    cin>>n;

    stringstream ss(raw);
    
    vector<string> vec;

    while( ss>>str){
        vec.push_back(str);
    }

    cout<<vec[vec.size()-n];
   
    return 0;
}