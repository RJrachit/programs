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

node * createTreePre()
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

void leftview(node * root,int k)
{
    int static m = 1;
    if(root==0){
        return;
    }
    if(k>=m)
      {
         cout<<root->data<<" ";
         m++;
      }
    leftview(root->left,k+1);
    leftview(root->right,k+1);
    return;
}

int main()
{
    node * root = createTreePre();

    leftview(root,1);
}
