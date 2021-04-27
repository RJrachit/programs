#include<iostream>
#include<queue>
using namespace std;
int static c = 0;
struct node
{
    int data;
    node * left;
    node * right;
    node (int data)
    {
        this->data = data;
        left = 0;
        right = 0;
    }
};

node * bst(int n)
{
    if(n==0){
        return 0;
    }
    int data;
    node * root;
    cin>>data;
    root = new node(data);
    node * temp = root;
    while(--n)
    {
        node * parent = temp;
        temp = root;
        cin>>data;
        while(temp)
        {
            if(temp->data > data)
            {
                parent = temp;
                temp = temp->left;
            }
            else{
                parent = temp;
                temp = temp->right;
            }
        }

        if(parent->data > data)
        {
            parent->left = new node(data);
        }
        else{
            parent->right =  new node(data);
        }
    }
    return root;
}

node * bstinorder(int a[],int n, int start ,int end)
{
    if(start > end){
        return 0;
    }
    int mid = (start + end)/2;
    node * root = new node(a[mid]);
    root->left = bstinorder(a,n,start,mid-1);
    root->right = bstinorder(a,n,mid+1,end);
    return root;
}
void print(node * root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    return;
}

void sumnode(node * root,int &sum)
{
    if(!root){
        return;
    }
    sumnode(root->right,sum);
    int temp = root->data;
    root->data+=sum;
    sum += temp;
    sumnode(root->left,sum);
    return;
}

int main()
{
    int n;
    cin>>n;

    node * root = bst(n);
    int sum =0 ;
    print(root);
    sumnode(root,sum);
    print(root);
}
