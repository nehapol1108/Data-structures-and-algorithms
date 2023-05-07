#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 struct TreeNode {
    int val;
    TreeNode *left;   TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 //TC->O(N) SC->O(N)
int height(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        //IN case both left and right node are null
        if(root->left==NULL && root->right==NULL){
          return 1;
        }
         //IN case both left node is null we find only in right direction
        if(root->left==NULL){
          return 1+height(root->right);;
        }
         //IN case both right node is null we find only in left direction
        if(root->right==NULL){
          return 1+height(root->left);;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        //IN case both left and right node both exists
        return 1 + min(lh,rh);
    }
    int minDepth(TreeNode* root) {
        return height(root);
    }
int main(){
    
    return 0;
}