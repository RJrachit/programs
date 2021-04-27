#include<iostream>
using namespace std;
int main()
{
    char a[100][100];
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++)
    cin.getline(a[i],100);
    int i=0;
    while(i<n)
    {
        for(int j=0;j<n-i-1;j++)
        {
            int k=0;
            while(a[j][k]==a[j+1][k] && a[j][k]!='\0')
            {
                k++;
            }
            if(a[j][k]>a[j+1][k])
            {
                //copy strings here

                char temp;
                temp=a[j][k];
                a[j][k]=a[j+1][k];
                a[j+1][k]=temp;
            }
        }
        i++;
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;a[i][j]!=0;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}
