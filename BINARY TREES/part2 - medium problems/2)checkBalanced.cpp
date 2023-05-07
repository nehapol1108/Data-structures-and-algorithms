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

//TC->O(N^2) SC->O(N)
int height(Node *root){
    if(root==NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    
    return 1 + max(lh,rh);
}
bool isBalanced(Node *root)
{
    if(root==NULL){
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)>1)return false;
    
    bool checkLeft = isBalanced(root->left);
    bool checkRight = isBalanced(root->right);
    if(!checkLeft || !checkRight){
        return false;
    }
    return true;
} 

//TC->O(N) SC->O(N)
int height(Node *root){
    if(root==NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh==-1 || rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    return 1 + max(lh,rh);
}
bool isBalanced(Node *root)
{
    return height(root)==-1?false:true;
}
int main(){
    
    return 0;
}