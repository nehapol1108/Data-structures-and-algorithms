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

 //TC->O(N)logn SC->O(N)   we can omit this Logn complexity by mannually finding the index through O(n) but then complexity would be O(n^2)
TreeNode * buildTree(vector<int>& pre,int preStart,int preEnd,vector<int>& in,int inStart,int inEnd,map<int,int>&m){
    if(preStart>preEnd || inStart>inEnd){
        return NULL;
    }
    TreeNode *root = new TreeNode(pre[preStart]);
    int inRoot = m[root->val];
    int numsLeft = inRoot-inStart;
    
    root->left = buildTree(pre,preStart+1,preStart+numsLeft,in,inStart,inRoot-1,m);
    root->right = buildTree(pre,preStart+1+numsLeft,preEnd,in,inRoot+1,inEnd,m);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preStart = 0, preEnd =preorder.size() - 1;
    int inStart = 0, inEnd = inorder.size()- 1;
    map < int, int > mp;
    for (int i = inStart; i <= inEnd; i++) {
        mp[inorder[i]] = i;
    }   
    return buildTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
} 
int main(){
    
    return 0;
}