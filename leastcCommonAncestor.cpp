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

bool findnode(node * root,int data)
{
    if(root==0){
        return false;
    }
    if(root->data==data){
        return true;
    }
    bool temp = findnode(root->left,data);
    if(temp==false){
        temp = findnode(root->right,data);
    }
    return temp;
}

node * lca(node * root,node * &ancestor,int a,int b)
{
    if(root==0){
        return 0;
    }
    if(findnode(root,a) && findnode(root,b))
    {
        ancestor = root;
        lca(root->left,ancestor,a,b);
        lca(root->right,ancestor,a,b);
    }
    else{
        return 0;
    }
}

int main()
{
    node * root = createTreePre();
    int a,b;
    cin>>a>>b;
    node * ancestor = 0;
    lca(root,ancestor,a,b);
    if(ancestor!=0){
        cout<<ancestor->data;
    }
}
