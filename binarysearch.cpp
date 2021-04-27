#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];
        int k;
    cin>>k;
    int start=0;
    int end=n;
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(a[mid]<k)
        {
            start=mid+1;

        }
        else if(a[mid]>k)
        {
            end=mid-1;

        }
        if(a[mid]==k)
        {
            cout<<"F";
            return 0;

        }

    }
    cout<<"nf";

}
