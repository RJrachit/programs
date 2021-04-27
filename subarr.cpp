#include<iostream>
using namespace std;
int main()
{
    int n,a1[100000],a2[100000],a3[100000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a1[i];

    for(int i=0;i<n;i++)
        cin>>a3[i];

    for(int i=0;i<n;i++)
    {
        int temp;
        temp=a1[i];
        a2[temp]=i;

    }

    for(int i=0;i<n;i++)
    {
        if(a3[i]!=a2[i])
        {
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
    return 0;

}
