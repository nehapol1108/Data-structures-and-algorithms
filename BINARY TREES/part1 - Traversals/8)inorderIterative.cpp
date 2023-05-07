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

//TC->O(N) SC->O(N) or O(Height of BT) -> for right or left skewed
vector<int> inOrder(Node* root) {
    vector<int>ans;
    stack<Node*>s;
    Node *temp = root;
    while(true){
        if(temp!=NULL){
            s.push(temp);
            temp = temp->left;
        }else{
            if(s.empty()){
                break;
            }
            temp = s.top();
            s.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
} 
int main(){
    
    return 0;
}