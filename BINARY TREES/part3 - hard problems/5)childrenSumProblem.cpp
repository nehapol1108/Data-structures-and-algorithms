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

//VERY IMP QUESTION
//TC->O(N) SC->O(N)
void changeBT(Node *root){
    if(root==NULL)return;
    int child = 0;
    //calculating curr child value
    if(root->left)child+=root->left->data;
    if(root->right)child+=root->right->data;


    if(child>=root->data) root->data = child;
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;   
    }

    changeBT(root->left);
    changeBT(root->right);

    int total = 0;
    if(root->left)total+=root->left->data;
    if(root->right)total+=root->right->data;

    //making sure it is not a leaf node
    if(root->left || root->right) root->data = total;
}
int main(){
    
    return 0;
}