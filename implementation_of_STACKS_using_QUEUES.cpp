#include<iostream>
#include<queue>
using namespace std;

struct stack
{
    queue<int> q1;
    queue<int> q2;

    bool isEmpty(){
        return q1.empty() && q2.empty();
    }
    int size(){
        return q1.size() | q2.size();
    }
    void push(int data){
        if(!q1.empty()){
            q2.push(data);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
        else{
            q1.push(data);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }

    }
    void pop()
    {
        if(q1.empty()){
            q2.pop();
        }
        else{
            q1.pop();
        }
    }
    int top()
    {
        if(q1.empty()){
            return q2.front();
        }
        else{
            return q1.front();
        }
    }
};

void print(stack s)
{
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main()
{
    stack s;
    s.push(1);s.push(2);s.push(3);
    cout<<s.size();
}


