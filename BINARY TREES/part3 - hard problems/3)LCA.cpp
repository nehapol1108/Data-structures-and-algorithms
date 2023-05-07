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
 struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//APPROACH 1  find path of both and the last element common in their path is the ans
//  Time complexity: O(N)+O(N) where n is the number of nodes.
// Space complexity: O(N)+O(N), auxiliary space.
bool func(Node *root, vector<Node*>&v,int val){
    if(root==NULL){
        return false;
    }
    
    v.push_back(root);
    if(root->data==val){
        return true;
    }    
    if(func(root->left,v,val) || func(root->right,v,val)){
        return true;
    }
    v.pop_back();
    return false;
    
}
Node* lca(Node* root ,int n1 ,int n2 )
{
    vector<Node*>v1;
    vector<Node*>v2;
    if(root==NULL)return root;
    
    func(root,v1,n1);
    func(root,v2,n2);
    Node *ans = root;
    for(int i=0;i<min(v1.size(),v2.size());i++){
        if(v1[i]==v2[i]){
            ans = v1[i];
        }else{
            break;
        }
    }
    return ans;
}

//APPROACH 2
//  Time complexity: O(N) where n is the number of nodes.
// Space complexity: O(N), auxiliary space.
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //base case
    if (root == NULL || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    //result
    if(left == NULL) {
        return right;
    }
    else if(right == NULL) {
        return left;
    }
    else { //both left and right are not null, we found our result
        return root;
    }
}

int main(){
    
    return 0;
}