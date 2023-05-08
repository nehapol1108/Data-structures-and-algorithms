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
//Approach 1
// Time Complexity: O(N).
// Auxiliary Space: O(N).
void func(Node *root,int &ans){
    if(root==NULL){
        return ;
    }
    ans++;
    func(root->left,ans);
    func(root->right,ans);
}

//Approach 2
// Time Complexity: O((LogN)2).
// Auxiliary Space: O(Log N).
int leftHeight(Node *root){
    int h =0;
    while(root){
        h++;
        root=root->left;
    }
    return h;
}
int rightHeight(Node *root){
    int h =0;
    while(root){
        h++;
        root=root->right;
    }
    return h;
}
int countNodes(Node* root) {
    // Write your code here
    if(root==NULL){
        return 0;
    }
    int lh = leftHeight(root);
    int rh = rightHeight(root);
    if(lh==rh)return (1<<lh) - 1;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
} 
int main(){
    
    return 0;
}