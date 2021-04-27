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


node * bst(int n)
{
    if(n==0){
        return 0;
    }
    int data;
    cin>>data;
    node * root;
    root = new node(data);
    while(--n)
    {
        int data;
        cin>>data;

        node * it = root;
        node * prev = it;
        while(it)
        {
            if(it->data>data){
                prev =  it;
                it = it->left;
            }
            else
            {
                prev = it;
                it = it->right;
            }
        }
        if(prev->data>data){
            prev->left = new node(data);
        }
        else{
            prev->right = new node(data);
        }
    }
    return root;
}


node * deleteElement(node * root,int data){
    if(!root){
        return NULL;
    }
    if(root->data == data){
        // no child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // 1 child
        if((!root->left && root->right) || (root->left && !root->right)){
            node * temp;
            if(root->left){
                temp = root->left;
            }else{
                temp = root->right;
            }
            delete root;
            return temp;
        }
        // 2 child
        node * parent = root;
        node * it = root->left;
        while(it->right)
        {
            parent = it;
            it = it->right;
        }
        if(parent!=root)
        {
            parent->right = it->left;
            it->left = root->left;
        }
        it->right = root->right;
        delete root;
        return it;
    }
    if(root->data>data)
    {
        root->left = deleteElement(root->left,data);
    }
    else
    {
        root->right = deleteElement(root->right,data);
    }
    return root;
}

void printpreorder(node * root)
{
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
    return;
}

int main()
{

        int n;
        cin>>n;
        node * root = bst(n);
        cout<<"enter element to be deleted : "<<endl;
        int m;
        cin>>m;
        root = deleteElement(root,m);
        printpreorder(root);
        cout<<endl;
        cout<<"enter element to be deleted : "<<endl;

        cin>>m;
        root = deleteElement(root,m);
        printpreorder(root);
        cout<<endl;
        cout<<"enter element to be deleted : "<<endl;

        cin>>m;
        root = deleteElement(root,m);
        printpreorder(root);
        cout<<endl;
        return 0;

}
/*
1
7
5 3 2 4 7 6 8
3
2 3 5
*/
