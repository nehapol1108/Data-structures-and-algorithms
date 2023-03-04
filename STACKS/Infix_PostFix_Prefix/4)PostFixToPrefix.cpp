#include<bits/stdc++.h>
#define ll long long
using namespace std;
//  https://www.youtube.com/watch?v=smQ88h1qzQY&t=1s&ab_channel=SpreadEducation.
string postToPre(string post) {
    stack<string>s;
    for(int i=0;i<post.size();i++){
        if((post[i]>='A' && post[i]<='Z') || (post[i]>='a' && post[i]<='z')){
            string temp;
            temp.push_back(post[i]);
            s.push(temp);
        }
        else{
            string a1 = s.top();
            s.pop();
            string a2 = s.top();
            s.pop();
            string temp;
            temp.push_back(post[i]);
            temp+=a2;
            temp+=a1;
            s.push(temp);
        }
    }
    return s.top();
}
int main(){
    
    return 0;
}