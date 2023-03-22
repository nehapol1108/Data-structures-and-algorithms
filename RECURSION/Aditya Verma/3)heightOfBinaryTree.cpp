#include<bits/stdc++.h>
#define ll long long
using namespace std;
class node{
    public:
        node * left;
        node * right;
        int val;
};

//TC->O(n) SC->O(N)
int heightOfBinaryTree(node *root){
    if(root==NULL){
        return 0;
    } 
    int left = heightOfBinaryTree(root->left);
    int right = heightOfBinaryTree(root->right);
    return 1 + max(left,right);
}
int main(){
    
    return 0;
}