#include<iostream>
using namespace std;

int binary(int a[],int end,int start,int m)
{
    if(start>end){
        return -1;
    }
    int mid=(start+end)/2;
    if(a[mid]==m)
        return mid;
    else if(a[mid]>m)
        end=mid-1;
    else
        start=mid+1;
    return binary(a,end,start,m);
}

int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    cout<<binary(a,n-1,0,m);
}
