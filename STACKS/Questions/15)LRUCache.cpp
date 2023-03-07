#include<bits/stdc++.h>
#define ll long long
using namespace std;
class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    class node{
        public:
            int k,v;
            node *prev,*next;
            node(int k,int v){
                this->k = k;
                this->v = v;
            }
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int size=0;
    unordered_map<int,node *>m;
    LRUCache(int cap)
    {
        size = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    void insertNode(node *&newnode){
        newnode->next = head->next;
        head->next->prev = newnode;
        head->next = newnode;
        newnode->prev=head;
    }
    void delNode(node *&delnode){
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int GET(int key)
    {
        if(m.find(key)==m.end()){
            return -1;
        }
        node *resnode = m[key];
        int val = resnode->v;
        m.erase(key);
        delNode(resnode);
        insertNode(resnode);
        m[key] = head->next;
        return val;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(m.find(key)!=m.end()){
            node *existingKey = m[key];
            m.erase(key);
            delNode(existingKey);
        }
        if(m.size()==size){
            m.erase(tail->prev->k);
            delNode(tail->prev);
        }
        node *newnode = new node(key,value);
        insertNode(newnode);
        m[key] = head->next;
    }
};
int main(){
    
    return 0;
}