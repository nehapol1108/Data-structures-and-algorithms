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

class Solution{
    public:
    //Function to find the height of a binary tree.

    //TC->O(height) SC->O(N)
    int height(struct Node* root){
        if(root==NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        
        return 1 + max(lh,rh);
    }
};
int main(){
    
    return 0;
}