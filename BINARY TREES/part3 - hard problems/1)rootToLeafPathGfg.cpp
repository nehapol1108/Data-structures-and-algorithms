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

//TC->O(N) SC->O(N)
void func(Node *root, vector<int>&v,vector<vector<int>>&ans){
     if(root==NULL){
         return;
     }
     v.push_back(root->data);
     if(root->left==NULL && root->right==NULL){
         ans.push_back(v);
     }
     func(root->left,v,ans);
     func(root->right,v,ans);
     v.pop_back();
     
 }
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>>ans;
    vector<int>v;
    if(root==NULL)return ans;
    
    func(root,v,ans);
    return ans;
}
 
int main(){
    
    return 0;
}