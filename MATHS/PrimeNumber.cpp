#include<bits/stdc++.h>
#define ll long long
using namespace std;
//brute force method  complexity -> O(n)
bool brute_force_method(int n){
    if(n==1){
        return false;
    }
    for(int i=2;i<n;i++){
        if((n%i)==0){
            return false;
        }
    }
    return true;
} 

//efficient method complexity -> O(root n)
bool square_root_method(int n){
    if(n==1){
        return false;
    }
    for(int i=2;i*i<n;i++){
        if((n%i)==0){
            return false;
        }
    }
    return true;
} 
//more efficient method
bool square_root_method_more_eff(int n){
    if(n==1){
        return false;
    }
    if(n==2 || n==3){
        return true;
    }
    if(n%2==0 || n%3==0){
        return false;
    }
    for(int i=5;i*i<n;i=i+6){
        if((n%i)==0 || (n%(i+2))==0){
            return false;
        }
    }
    return true;
} 
int main(){
    int n=8;
    if(brute_force_method(n)){
        cout<<"PRIME"<<endl;
    }else{
        cout<<"NON PRIME"<<endl;
    }
     if(square_root_method(n)){
        cout<<"PRIME"<<endl;
    }else{
        cout<<"NON PRIME"<<endl;
    }
     if(square_root_method_more_eff(n)){
        cout<<"PRIME"<<endl;
    }else{
        cout<<"NON PRIME"<<endl;
    }
    return 0;
}