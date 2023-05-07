#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};
int main(){
    struct node*root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    return 0;
}