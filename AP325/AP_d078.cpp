#include<bits/stdc++.h>
using namespace std;
// DP LIS
int main(){
    int n ; cin>>n;
    vector<int> vec(n);
    for(auto &i:vec) cin>>i;

    vector<int> LIS;
    for(auto &ele:vec){
    
        if(LIS.empty() || LIS.back() < ele) LIS.push_back(ele);
        else{
            auto it=lower_bound(LIS.begin(),LIS.end(),ele);
            *it=ele;
        }
    }
    cout<<LIS.size();
}