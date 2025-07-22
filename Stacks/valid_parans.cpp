#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    string parans = "()()()()(((((())))))";
    stack<char> st;
    for(int i=0;i<parans.size();i++){
        if(st.size() == 0) st.push(parans[i]);
        else if(parans[i] == ')' && st.top() == '(')st.pop();
        else if(parans[i] == ')') st.push(parans[i]);
        else st.push('(');
    }
    if(st.size() == 0) cout<<true;
    else cout<<false;
}
