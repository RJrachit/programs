#include<iostream>
#include<vector>
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

node * createlinkedlist(int n)
{
    node * head = NULL;
    if(n==0){
        return NULL;
    }
        int data;
        cin>>data;
        head = new node(data);

    node * tail = head;
    while(n>1)
    {
        int data;
        cin>>data;
        node * temp = new node(data);
        tail -> next = temp;
        tail = tail -> next; //tail = temp ;
        n--;
    }
    return head;
}
void print(node * head){

    while(head!=0){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL";
}
node * reverseLL(node * head,node * &tail)
{
    if(head==0)
    {
        return 0;
    }
    if(head->next==0)
    {
        tail = head ;
        return head;
    }
    node * newhead = reverseLL(head->next,tail);
    tail->next = head ;
    tail = tail->next;
    tail->next = NULL;
    return newhead;

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

pair<node *,node *> reverseLL2(node * head)
{
    if(head->next==0){
        pair<node *,node *> temp(head,head);
        return temp;
    }
    pair<node*,node*> p = reverseLL2(head->next);
    p.second->next=head;
    p.second = head;
    p.second ->next = 0;
    return p;
}

int main()
{
    int n;
    cin>>n;
    node * head = createlinkedlist(n);
    node * tail;
    head=(reverseLL(head,tail));
    print(head);
    cout<<endl;
    //********************************
    pair<node *, node*> p = reverseLL2(head);
    print(p.first);
}
