#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;   TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
int height(TreeNode *root,int &sum){
    if(root==NULL){
        return 0;
    } 
    int lh = max(0,height(root->left,sum));
    int rh = max(0,height(root->right,sum));
    sum=max(sum,lh+rh + root->val);
    return root->val+max(lh,rh);
}
int maxPathSum(TreeNode* root) {
    int sum=INT_MIN;
    height(root,sum);
    return sum;
}
int main(){
    
    return 0;
}