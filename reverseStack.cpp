#include<iostream>
using namespace std;
template<typename T>
struct node
{
    T data;
    node * next;
    node(T data)
    {
        this->data=data;
        next=NULL;
    }
};

template<typename T>
struct stack
{
    node<T> * head;
    int count;
    stack(){
        head = NULL;
        count = 0;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return head==0;
    }
    void push(T data)
    {
        node<T> * temp = new node<T>(data);
        count++;
        temp->next = head ;
        head = temp;
        return;
    }
    void pop()
    {
        node<T>*temp = head;
        head=head->next;
        delete temp;
        count--;
        return;
    }
    T top()
    {
        if(head)
            return head->data;
        return -1;
    }
};

void print(stack<int> &s){
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return;
}

void reverseStack(stack<int>&s,stack<int>s1){
    int n = s.size();
    for(int i=0;i<n;i++){
        int top = s.top();
        s.pop();
        for(int j=0;j<n-i-1;j++){
            s1.push(s.top());
            s.pop();
        }
        s.push(top);
        while(!s1.isEmpty()){
            s.push(s1.top());
            s1.pop();
        }
    }
}
//****************************************
void mirror(stack<int>&s,stack<int>&s1){
   if(s.empty()){
    return;
   }
   int top = s.top();
   s.pop();
   mirror(s,s1);
   s1.push(top);
    return;
}
void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void copy(stack<int>&s,stack<int>&s1){
    while(!s1.empty()){
        s.push(s1.top());
        s1.pop();
    }
}
//***************************************
int main()
{
    int n,data;
    cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++){
        cin>>data;
        s.push(data);
    }
    stack<int>s1;
    reverseStack(s,s1);
    print(s);
}
