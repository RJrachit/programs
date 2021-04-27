#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
    node(int data)
    {
        this->data=data;
        left=0;
        right=0;
    }
};

node * createTreelevel()
{
    queue<node *>q;
    int data;
    cin>>data;
    if(data!=-1){
        node * temp = new node(data);
        q.push(temp);
    }
    node * root = q.front();
    while(!q.empty())
    {
        node * curr = q.front();
        q.pop();
        cin>>data;
        if(data!=-1){
            node * left = new node (data);
            curr->left = left;
            q.push(left);
        }
        cin>>data;
        if(data!=-1){
            node * right = new node (data);
            curr->right = right;
            q.push(right);
        }
    }
    return root;
}

void inorder(node * head)
{
    if(head == NULL){
        return;
    }
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
    return;
}
void postorder(node*head)
{
    if(head==NULL){
        return;
    }
    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
    return;
}
void preorder(node*head)
{
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
    return;
}


int main()
{
    node * head = createTreelevel();
    cout<<"Inorder ";
    inorder(head);
    cout<<endl;
    cout<<"Postorder ";
    postorder(head);
    cout<<endl;
    cout<<"Preorder ";
    preorder(head);
    return 0;
}
