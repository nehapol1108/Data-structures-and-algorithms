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
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node * temp = q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
} 
int main(){
    
    return 0;
}