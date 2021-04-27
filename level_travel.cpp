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
node * createTreePre()
{
    int data;
    cin>>data;
    node * temp = new node(data);
    char check[6];
    cin>>check;
    if(check[0]=='t'){
        temp->left = createTreePre();
    }
    cin>>check;
    if(check[0]=='t'){
        temp->right = createTreePre();
    }
    return temp;
}

void travel(node * root)
{
    queue<node *>q1;
    queue<node *>q2;
    q1.push(root);
    while(!q1.empty() || !q2.empty())
    {
        while(!q1.empty())
        {
            node * curr = q1.front();
            cout<<curr->data<<" ";
            if(curr->left)
                q2.push(curr->left);
            if(curr->right)
                q2.push(curr->right);
            q1.pop();
        }
        cout<<endl;
        while(!q2.empty())
        {
            node * curr = q2.front();
            cout<<curr->data<<" ";
            if(curr->left)
                q1.push(curr->left);
            if(curr->right)
                q1.push(curr->right);
            q2.pop();
        }
        cout<<endl;
    }
}

int main()
{
    node * root = createTreePre();
    travel(root);
}
