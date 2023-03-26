#include<bits/stdc++.h>
#define ll long long
using namespace std;
int lastIndex(vector<int>a,int i,int x){
    if(i==a.size()){
        return -1;
    }
    int it = lastIndex(a,i+1,x);
    if(it==-1){
        if(a[i]==x){
            return i;
        }else{
            return -1;
        }
    }else{
        return it;
    }
    
} 
int main(){
    vector<int>a = {4,32,5,4,23};
    cout<<lastIndex(a,0,4);
    return 0;
}