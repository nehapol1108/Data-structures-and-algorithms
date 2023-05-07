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

// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> bottomView(Node *root)
{
    map<int,int>m;
    queue<pair<Node*,int>>q;
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node *curr = it.first;
        m[it.second]=curr->data;
        
        if(curr->left!=NULL){
            q.push({curr->left,it.second-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,it.second+1});
        }
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}
int main(){
    
    return 0;
}