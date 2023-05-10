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
struct TreeNode {
    int val;
    TreeNode *left;   TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// Time Complexity: O(N)
// Reason: We are doing a simple  reverse postorder  traversal.
// Space Complexity: O(N)
// Reason: Worst case time complexity will be O(N) (in case of skewed tree).
class Solution {
public:
    Node* prev=NULL;
    void flatten(Node *root)
    {
        if(root==NULL)return;

        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left=NULL;
        prev = root;
    } 
};


// Time Complexity: O(N)
// Reason: The loop will execute for every node once.
// Space Complexity: O(N)
void flatten(Node *root)
{
    if(root==NULL)return;

    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node *curr = s.top();
        s.pop();
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
        if(!s.empty()){
            curr->right = s.top();     
        }
        curr->left=NULL;
    }
}
// Time Complexity: O(N)
// Reason: Time complexity will be the same as that of a morris traversal
// Space Complexity: O(1)
// Reason: We are not using any extra space.
void flatten2(TreeNode* root) {
    if(root==NULL)return;
    //morris travel related soln
    TreeNode* curr = root;
    
    while(curr!=NULL){
        if(curr->left!=NULL){
            TreeNode* prev = curr->left;
            while(prev->right){
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
    
}
int main(){
    
    return 0;
}