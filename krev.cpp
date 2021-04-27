#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct node
{
    int data;
    node * next;
    node(int data)
    {
        this->data=data;
        next = 0;
    }
};

node * createll(int n)
{
    if(n==0){
        return 0;
    }
    int data;
    cin>>data;
    node * head = new node(data);
    node * it = head;
    while(n>1)
    {
        int data;
        cin>>data;
        node * temp = new node(data);
        it -> next = temp;
        it = it->next;
        n--;
    }
    return head;
}
node * reverseLL1(node * head){
    node * prev = NULL;
    node * it = head;
    while(head){
        it = it->next;
        head->next = prev;
        prev = head;
        head = it;
    }
    return prev;
}
node * krev(node * head,int k)
{
    if(head==0){
        return 0;
    }
    node * it = head;
    for(int i=1;it->next!=0&&i<k;i++)
    {
        it = it->next;
    }
    node * newhead = it->next;
    it->next = 0;
    head = reverseLL1(head);
    it = head;
    while(it->next !=0){
        it = it->next;
    }
    newhead = krev(newhead,k);
    it->next = newhead;
    return head;
}

void print(node * head)
{
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    node * head = createll(n);
    head = krev(head,k);
    print(head);
}
