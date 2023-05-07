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
bool isLeaf(Node * node){
    if(node->left==NULL && node->right==NULL){
        return true;
    }
    return false;
}

//O(H)
void addLeftBoundary(Node *root,vector<int>&ans){
    Node *curr = root->left;
    while(curr){
        if(!isLeaf(curr))ans.push_back(curr->data);
        if(curr->left)curr = curr->left;
        else{
            curr = curr->right;
        }
    }
}
//O(N)  preorder 
void addLeaves(Node *root,vector<int>&ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
    }
    if(root->left)addLeaves(root->left,ans);
    if(root->right)addLeaves(root->right,ans);
}
//O(H)
void addRightBoundary(Node *root,vector<int>&ans){
    Node *curr = root->right;
    vector<int>temp;
    while(curr){
        if(!isLeaf(curr))temp.push_back(curr->data);
        if(curr->right)curr = curr->right;
        else{
            curr = curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}

//TC->O(H) +O(N) + O(H) ~ O(N) TC->O(N) //auzilary stack space
vector <int> boundary(Node *root)
{
    //Your code here
    
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    if(!isLeaf(root))ans.push_back(root->data);
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
} 
int main(){
    
    return 0;
}