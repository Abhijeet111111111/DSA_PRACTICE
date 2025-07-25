#include <iostream>
using namespace std;
#include <queue>

int main()
{
    queue<int> qu ;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    while(qu.size()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
}