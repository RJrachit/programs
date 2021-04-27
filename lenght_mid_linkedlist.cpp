#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    int data;
    node * next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
node * createLinkedList()
{
    int data;
    cin>>data;
    node * head=NULL;
    if(data!=-1){
        head=new node(data);
        cin>>data;
    }
    node * tail=head;
    while(data!=-1)
    {
        node * temp=new node(data);
        tail->next=temp;
        tail=tail->next;
        cin>>data;
    }
    return head;
}
node * ithFromLast(node *head,int i)
{
    static int n=i;
    if(head==0){
        return 0;
    }
    node * it = ithFromLast(head ->next,i);
    if(n==0){
        return it;
    }
    n--;
    return head;
}
int main()
{
    node * head = createLinkedList();
    int i;
    cin>>i;
    node * temp = ithFromLast(head,i);
    cout<<endl<<temp->data;

}
