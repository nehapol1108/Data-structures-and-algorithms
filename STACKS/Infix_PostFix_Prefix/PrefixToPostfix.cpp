// https://www.youtube.com/watch?v=jZxII0guwUo&ab_channel=SpreadEducation.
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string preToPost(string pre) {
    reverse(pre.begin(),pre.end());
    stack<string>s;
    for(int i=0;i<pre.size();i++){
        if((pre[i]>='A' && pre[i]<='Z') || (pre[i]>='a' && pre[i]<='z')){
            string temp;
            temp.push_back(pre[i]);
            s.push(temp);
        }
        else{
            string a1 = s.top();
            s.pop();
            string a2 = s.top();
            s.pop();
            string temp;
            temp+=a1;
            temp+=a2;
            temp.push_back(pre[i]);
            s.push(temp);
        }
    }
    return s.top();
}
int main(){
    
    return 0;
}