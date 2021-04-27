#include<iostream>
using namespace std;
void bubble(int a[],int n,int i,int j)
{
    if(i==n){
        return;
    }
    if(j==n-i)
    {
        return;
    }
    if(j<n-i-1)
    {
            if(a[j]>a[j+1])
            {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
    }

    bubble(a,n,i,j+1);
    if(j==0)
    bubble(a,n,i+1,0);
    return;
}

int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubble(a,n,0,0);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}
