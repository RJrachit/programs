#include<iostream>
#include<stack>
using namespace std;
template<typename T>
struct queue
{
    stack<T>s1;
    stack<T>s2;
    int size()
    {
        return s2.size();
    }
    bool isEmpty(){
        return s2.size()==0;
    }
    void push(T data)
    {
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(data);
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    void pop()
    {
        if(!s2.empty()){
            s2.pop();
        }
        return;
    }
    T top()
    {
        if(!s2.empty()){
            return s2.top();
        }
        else
            return 0;
    }

};

int main()
{
    queue<int>q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        q.push(i);
    }
    while(!q.isEmpty()){
        cout<<q.top()<<" ";
        q.pop();
    }
}
