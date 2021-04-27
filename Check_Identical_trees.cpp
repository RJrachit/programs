#include<iostream>
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

bool compare(node * root1,node * root2)
{
    if(root1==0 && root2!=0){
        return false;
    }
    else if(root1!=0 && root2==0){
        return false;
    }
    else if(root1==0 && root2==0){
        return true;
    }
    else if(root1->data != root2->data){
        return false;
    }
    return compare(root1->left,root2->left) && compare(root1->right,root2->right);
}

int main()
{
    node * root1 = createTreePre();
    node * root2 = createTreePre();
    if(compare(root1,root2)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
