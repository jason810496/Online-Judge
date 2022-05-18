#include<bits/stdc++.h>
using namespace std;


#define F first
#define S second
#define ll long long 
#define all(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INF = 1e9;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0 ;
    void DFS(TreeNode *root ,int &child,int &sum){
        if(!root) return ;
        
        int lc=0 , ls=0 , rc=0 , rs=0;
        DFS(root->right , rc ,rs);
        DFS(root->left , lc , ls );

        child = 1+rc+lc;
        sum = root->val +rs + ls;

        if( root->val == (sum/child) ) ans++;

    }
    int averageOfSubtree(TreeNode* root) {

        int child=0 ,sum=0;
        DFS(root,child,sum);
        return ans;
    }
};
