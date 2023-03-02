#include<bits/stdc++.h>
#define ll long long
using namespace std;
//  https://www.youtube.com/watch?v=vS_lYbc6BUk&ab_channel=Education4u
string postToInfix(string post) {
    stack<string>s;
    string temp;
    for(int i=0;i<post.size();i++){
        temp=post[i];
        if(isalpha(post[i])){
            s.push(temp);
        }
        else{
            string a1 = s.top();
            s.pop();
            string a2 = s.top();
            s.pop();
            s.push("("+a2+ temp + a1 + ")");
        }
    }
    return s.top();
}
int main(){
    
    return 0;
}