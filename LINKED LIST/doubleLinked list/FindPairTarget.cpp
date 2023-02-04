#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data){
            this->data = data;
            next=NULL;
            prev =NULL;
        }
};
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    Node *start = head;
    Node *end = head;
    int i=0,j=0;
    while(end->next!=NULL){
        end=end->next;
        j++;
    }
    vector<pair<int, int>>v;
    while(i<j){
        if((start->data+end->data)==target){
            v.push_back({start->data,end->data});
            start=start->next;
            end=end->prev;
            i++;
            j--;
        }else if((start->data+end->data)>target){
            end=end->prev;
            j--;
        }else{

            start=start->next;
            i++;
        }
    }
    
    return v;
} 
int main(){
    
    return 0;
}