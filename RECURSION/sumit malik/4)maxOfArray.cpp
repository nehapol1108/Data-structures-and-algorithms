#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxxi(vector<int>a,int i){
    if(i==a.size()-1){
        return a[i];
    }
    int ms = maxxi(a,i+1);
    if(a[i]>ms){
        return a[i];
    }else{
        return ms;
    }
} 
int main(){
    vector<int>a = {4,32,5,4,23};
    cout<<maxxi(a,0);
    return 0;
}