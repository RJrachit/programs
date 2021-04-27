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

bool path(node * root,int k,int * arr,int &i)
{
    if(root==0){
        return false;
    }
    k =k - root->data;
    if(root->left==0 && root->right==0 && k==0){
        arr[i] = root->data;
        return true;
    }

    if(k<0){
        return false;
    }

    if(path(root->left,k,arr,i)){
        i++;
        arr[i] = root->data;
        return true;
    }
    else if(path(root->right,k,arr,i)){
        i++;
        arr[i] = root->data;
        return true;
    }
    return false;
}

int main()
{
    node * root = createTreePre();
    int k;
    cin>>k;
    int i=0;
    int * arr = new int[i];
    path(root,k,arr,i);
    for(int j=i;j>=0;j--){
        cout<<arr[j]<<" ";
    }
}
