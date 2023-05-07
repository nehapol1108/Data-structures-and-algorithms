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
bool func(Node* leftNode,Node* rightNode){
    if(leftNode==NULL && rightNode==NULL)return true;
    if(leftNode==NULL || rightNode==NULL || leftNode->data!=rightNode->data )return false;

    return func(leftNode->left,rightNode->right) && func(leftNode->right,rightNode->left);
}

bool isSymmetric(struct Node* root)
{
    if(root==NULL)return true;
    return func(root->left,root->right);
} 
int main(){
    
    return 0;
}