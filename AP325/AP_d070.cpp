#include<iostream>
#include<string>
using namespace std;
/*
DP LCS
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int len1,len2,DP[505][505];
    string s1,s2;
    cin>>s1>>s2;
    len1=s1.size();
    len2=s2.size();
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            // if(i==0||j==0) DP[i][j]=0;
            if(s1[i-1]==s2[j-1]){
                DP[i][j]=DP[i-1][j-1]+1;
            }
            else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    cout<<DP[len1][len2];
    return 0;
}