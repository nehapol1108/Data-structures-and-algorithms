#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/path-sum/description/
struct TreeNode {
    int val;
    TreeNode *left;   TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root==NULL){
        return false;
    }
    if(root->left==NULL && root->right==NULL){
        return targetSum==root->val;
    }
    bool lh = false;
    bool rh = false;
    if(root->left!=NULL){
        lh = hasPathSum(root->left,targetSum-root->val);
    }
    if(root->right!=NULL){
        rh = hasPathSum(root->right,targetSum-root->val);
    }
    
    return lh || rh;
} 
int main(){
    
    return 0;
}