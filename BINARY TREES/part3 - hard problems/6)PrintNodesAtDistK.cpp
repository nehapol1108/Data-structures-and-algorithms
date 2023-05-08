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
void markParent(Node *root,unordered_map<Node*,Node*>&parents){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        if(curr->left){
            parents[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            parents[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
void findTargetNode(Node *root,int target,Node * &tar){
    if(root==NULL){
        return;
    }
    if(root->data==target){
        tar = root;
    }
    findTargetNode(root->left,target,tar);
    findTargetNode(root->right,target,tar);
    
}

//TC->O(NLOGN) SC->O(N)+O(N)+O(N) = O(N)
vector <int> KDistanceNodes(Node* root, int target , int k)
{
    unordered_map<Node*,Node*>parents;
    markParent(root,parents);

    queue<Node*>q;
    Node *tar=NULL;
    vector<int>res;
    
    findTargetNode(root,target,tar);

    unordered_map<Node*,bool>visited;
    q.push(tar);
    visited[tar] = true;
    int curr_level = 0;

    while(!q.empty()){
        if(curr_level++==k){
            break;
        }
        int size = q.size();
        for(int i=0;i<size;i++){
            Node *curr = q.front();
            q.pop();
            if(curr->left && visited[curr->left]==false){
                visited[curr->left] = true;
                q.push(curr->left);
            }
                if(curr->right && visited[curr->right]==false){
                visited[curr->right] = true;
                q.push(curr->right);
            }
            if(parents[curr] && visited[parents[curr]]==false){
                    visited[parents[curr]] = true;
                    q.push(parents[curr]);
            }
        }
    }
    while(!q.empty()){
        res.push_back(q.front()->data);
        q.pop();
    }
    sort(res.begin(),res.end());
    return res;
} 
int main(){
    
    return 0;
}