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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    bool flag=true;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++){
            TreeNode * temp = q.front();
            q.pop();
            int index = flag ? i:size-i-1;
            level[index] = temp->val;
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }             
        }
        flag = !flag;
        ans.push_back(level);
    }
    return ans;
} 
int main(){
    
    return 0;
}