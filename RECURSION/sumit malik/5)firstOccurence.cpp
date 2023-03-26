#include<bits/stdc++.h>
#define ll long long
using namespace std;
int firstIndex(vector<int>a,int i,int x){
    if(i==a.size()){
        return -1;
    }
    if(a[i]==x){
        return i;
    }else{
        int it = firstIndex(a,i+1,x);
        return it;
    }
} 
int main(){
    vector<int>a = {4,32,5,4,23};
    cout<<firstIndex(a,0,4);
    return 0;
}