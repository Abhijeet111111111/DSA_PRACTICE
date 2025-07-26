#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    queue<int> qu ;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    stack<int> st;
    while(qu.size()){
        st.push(qu.front());
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }
    


}