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

bool deleteleaves(node * root)
{
    if(root==0){
        return false;
    }
    if(root->left==0 && root->right==0){
        return true;
    }

    if(deleteleaves(root->left)){
        delete root->left;
        root->left = 0;
    }
    if(deleteleaves(root->right)){
        delete root->right;
        root->right = 0;
    }

    return false;
}

void print(node * root)
{
    if(root==0){
        return;
    }
    if(root->left){
       cout<<root->left->data<<" => ";
    }
    else{
        cout<<"END => ";
    }
    cout<<root->data;
    if(root->right){
        cout<<" <= "<<root->right->data;
    }
    else{
        cout<<" <= END";
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}

int main()
{
    node * root = createTreePre();
    deleteleaves(root);
    print(root);
}
