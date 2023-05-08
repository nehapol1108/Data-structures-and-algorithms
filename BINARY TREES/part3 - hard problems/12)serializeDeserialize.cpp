#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;   TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//  Time Complexity: O(N)
// Space Complexity: O(N)
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root==NULL){
        return "";
    }
    string s = "";
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*curr = q.front();
        q.pop();
        if(curr==NULL)s.append("#,");
        else s.append(to_string(curr->val)+',');
        if(curr!=NULL){
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.size()==0)return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode * curr = q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#"){
            curr->left = NULL;
        }else{
            TreeNode* leftNode = new TreeNode(stoi(str));
            curr->left = leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#"){
            curr->right = NULL;
        }else{
            TreeNode* rightNode = new TreeNode(stoi(str));
            curr->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
} 


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
//GFG WALA
//  Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> serialize1(Node *root) 
{
        vector<int>s;
    if(root==NULL){
        return s;
    }
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*curr = q.front();
        q.pop();
        if(curr==NULL)s.push_back(-1);
        else s.push_back(curr->data);
        if(curr!=NULL){
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

//Function to deserialize a list and construct the tree.
Node * deSerialize1(vector<int> &a)
{
    if(a.size()==0)return NULL;
    
    Node* root = new Node(a[0]);
    queue<Node*>q;
    int i=1;
    q.push(root);
    while(!q.empty() || i<a.size()){
        Node * curr = q.front();
        q.pop();
        if(a[i]==-1){
            curr->left = NULL;
        }else{
            Node* leftNode = new Node(a[i]);
            curr->left = leftNode;
            q.push(leftNode);
        }
        i++;
        if(a[i]==-1){
            curr->right = NULL;
        }else{
            Node* rightNode = new Node(a[i]);
            curr->right = rightNode;
            q.push(rightNode);
        }
        i++;
    }
    return root;
}

int main(){
    
    return 0;
}