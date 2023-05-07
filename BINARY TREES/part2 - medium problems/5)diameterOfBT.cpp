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
//TC->O(N^2) SC->O(N) approch 1
int height(Node * root){
    if(root==NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh,rh);
}
int findmax(Node *root){
    if(root==NULL){
        return 0;
    }
    int ht = height(root->left) + height(root->right);
    
    int leftd = findmax(root->left);
    int rightd = findmax(root->right);
    return max(ht,max(leftd,rightd));
    
}
int diameter(Node* root) {
    if(root==NULL){
        return 0;
    }
    return 1 + findmax(root);
} 


//TC->O(N) SC->O(N) approch 2
int findmax(Node *root,int &maxi){
    if(root==NULL){
        return 0;
    }
    int leftd = findmax(root->left,maxi);
    int rightd = findmax(root->right,maxi);
    maxi  = max(maxi,leftd+rightd);
    
    return 1 + max(leftd,rightd);
    
}
int diameter(Node* root) {
    if(root==NULL){
        return 0;
    }
    int maxi = 0;
    findmax(root,maxi);
    return maxi+1;
}
int main(){
    
    return 0;
}