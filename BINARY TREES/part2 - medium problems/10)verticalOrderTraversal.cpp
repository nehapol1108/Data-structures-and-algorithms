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

// Time Complexity: O(N*logN*logN*logN)
// Space Complexity: O(N) + O(N)
vector<int> verticalOrder(Node *root)
{
    map<int,map<int,vector<int>>>m;
    queue<pair<Node*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
        int size = q.size();
        
        
        auto temp = q.front();
        q.pop();
        Node *curr = temp.first;
        int x = temp.second.first, y = temp.second.second;
        m[x][y].push_back(curr->data);
        if(curr->left){
            q.push({curr->left,{x-1,y+1}});
        }
        if(curr->right){
            q.push({curr->right,{x+1,y+1}});
        }
        
        
    }
    vector<int>ans;
    for(auto p:m){
        for(auto q:p.second){
            for(auto j:q.second){
                ans.push_back(j);
            }
        }
    }
    return ans;
    
    
}
int main(){
    
    return 0;
}