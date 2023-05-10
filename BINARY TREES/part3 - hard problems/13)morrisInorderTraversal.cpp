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
// Time Complexity: 1+2+3+...+n -> near about O(N).
// Space Complexity: O(1)
vector<int> inorderTraversal(TreeNode* root) {
    vector<int>ans;
    TreeNode *curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            ans.push_back(curr->val);
            curr = curr->right;
        }else{
            TreeNode * prev = curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
} 
int main(){
    
    return 0;
}