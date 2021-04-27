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
        return 0;
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

void sortStack(stack<int>&s)
{
    stack<int> s1;
    int n = s.size();
    int i=0;

    while(i<n)
    {
        int temp = s.top();
        s.pop();
        for(int j=i;j<n-1;j++)
        {
            if(temp>s.top()){
                s1.push(temp);
                temp = s.top();
                s.pop();
            }
            else{
                s1.push(s.top());
                s.pop();
            }
        }
        s.push(temp);
        while(!s1.isEmpty())
        {
            s.push(s1.top());
            s1.pop();
        }
        i++;
    }
}


int main()
{
    int n;
    cin>>n;
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        s.push(data);
    }
    sortStack(s);
    print(s);
}
