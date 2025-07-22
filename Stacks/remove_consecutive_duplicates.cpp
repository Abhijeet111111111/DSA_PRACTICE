#include <iostream>
#include <stack>
#include <string>
using namespace std;

void display_stack(stack<char> st){
    if(st.size() == 0) return ;
    char ch = st.top();
    st.pop();
    display_stack(st);
    cout<<ch<<" ";
}

int main()
{
    string str = "aaabebbcdeeg";
    stack<char> st;
    for(int i=0;i<str.size();i++){
        if(st.size() == 0) st.push(str[i]);
        else if(st.top() != str[i]) st.push(str[i]);
    }
    display_stack(st);

    
}