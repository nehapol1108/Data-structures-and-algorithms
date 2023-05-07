#include<bits/stdc++.h>
#define ll long long
using namespace std;
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

//Function to return a list containing the inorder traversal of the tree.

//TC->O(N) SC->O(N)
void func(Node *root,vector<int>&ans){
    if(root==NULL){
        return ;
    }
    func(root->left,ans);
    ans.push_back(root->data);
    func(root->right,ans);
}
vector <int> inorder(Node* root)
{
  vector<int>ans;
  func(root,ans);
  return ans;
} 
int main(){
    
    return 0;
}