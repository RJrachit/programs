
#include<iostream>
using namespace std;
int main()
{
    char temp,arr[100];
    cin.getline(arr,100);

    int i=0;
    for(;arr[i]!=0;i++);
    i=i-1;
    int j=0;
    while(i>j)
    {
        temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
        j++;
        i--;

    }

    for(i=0;arr[i]!=0;i++)
        cout<<arr[i];

    cin.get(ch);



}
