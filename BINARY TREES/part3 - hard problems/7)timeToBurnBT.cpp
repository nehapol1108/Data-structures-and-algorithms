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

int minTime(Node* root, int target) 
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
    int time = 0;
    while(!q.empty()){
        int size = q.size();
        int fl=0;
        for(int i=0;i<size;i++){
            Node *curr = q.front();
            q.pop();
            if(curr->left && visited[curr->left]==false){
                visited[curr->left] = true;
                q.push(curr->left);
                fl=1;
            }
                if(curr->right && visited[curr->right]==false){
                visited[curr->right] = true;
                q.push(curr->right);
                fl=1;
            }
            if(parents[curr] && visited[parents[curr]]==false){
                    visited[parents[curr]] = true;
                    q.push(parents[curr]);
                    fl=1;
            }
        }
        if(fl==1)time++;
    }
    return time;
} 
int main(){
    
    return 0;
}