#include<bits/stdc++.h>
#define ll long long
using namespace std;
//  https://leetcode.com/problems/remove-k-digits/
// https://www.youtube.com/watch?v=3QJzHqNAEXs&ab_channel=TECHDOSE

//TC->O(N*K)
//SC->O(1)

//The first algorithm is straight-forward. Let's think about the simplest case: how to remove 1 digit from the number so that the new number is the smallest possible？ Well, one can simply scan from left to right, and remove the first "peak" digit; the peak digit is larger than its right neighbor. One can repeat this procedure k times, and obtain the first algorithm:
string removeKdigits(string num, int k) {
    while (k > 0) {
        int n = num.size();
        int i = 0;
        while (i+1<n && num[i]<=num[i+1])  i++;
        num.erase(i, 1);
        k--;
    }
    // trim leading zeros
    int s = 0;
    while (s<(int)num.size()-1 && num[s]=='0')  s++;
    num.erase(0, s);
    
    return num=="" ? "0" : num;
}
//TC->O(N)
//SC->O(N)
string removeKdigits(string s, int k) {
    stack<int>st;
    int n=s.size();
    
    for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && st.top()>s[i]-'0'){
            k--;
            st.pop();
        }
        if((s[i]-'0')!=0 || !st.empty()){
            st.push(s[i]-'0');
        }
    }

    //if there is no peak then numbers will be there in increasing order
    //eg-> 123
    while(!st.empty() && k--){
        st.pop();
    }
    
    if(st.empty())return "0";
    
    while(!st.empty()){
        s[n-1]=st.top()+'0';
        st.pop();
        n--;
    }
    //here n represent starting point of subarray
    return s.substr(n)==""?"0":s.substr(n);
}
int main(){
    
    return 0;
}