#include<iostream>
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
}

node * findAtPositionK(node * head,int k){
    while(k-- && head){
        head = head->next;
    }
    return head;
}

int length(node * head){
    int k=0;
    while(head){
        head = head->next;
        k++;
    }
    return k;
}
void swap(node *& head, int i,int j){
    if(i==j)
        return;
    if(i==0 && j==1){
        node * a = head;
        node * b = head->next;
        node * bNext = b->next;
        head = b;
        b->next = a;
        a->next = bNext;
        return;
    }
    if(i==0){
        node * prev = findAtPositionK(head,j-1);
        node * a = head;
        node * b = prev->next;
        node * bNext = b->next;
        head = b;
        b->next = a->next;
        prev->next = a;
        a->next = bNext;
        return;
    }
    if(j-i==1){
        node * prev = findAtPositionK(head,i-1);
        node * a = prev->next;
        node * b = a->next;
        node * bNext = b->next;
        prev->next = b;
        b->next = a;
        a->next = bNext;
        return;
    }
    node * prev1 = findAtPositionK(head,i-1);
    node * prev2 = findAtPositionK(head,j-1);
    node * a = prev1->next;
    node * b = prev2->next;
    node * bNext = b->next;
    prev1->next = b;
    b->next = a->next;
    prev2->next = a;
    a->next = bNext;
    return;
}
void insertionsort(node * &head,int i,int j,int n)
{
    if(i==n-1){
        return;
    }
    if(j==-1){
        return;
    }

    node * curr = findAtPositionK(head,j+1);
    node * prev = findAtPositionK(head,j);
    if(prev->data > curr->data){
        swap(head,j,j+1);
    }
    insertionsort(head,i,j-1,n);

    insertionsort(head,i+1,i+1,n);
}
int main()
{
    int n;
    cin>>n;
    node * head = createlinkedlist(n);
    insertionsort(head,0,0,n);
    print(head);
}
