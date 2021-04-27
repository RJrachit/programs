#include<iostream>
using namespace std;
int main()
{
    char a[200],b[100];
    int i;
    cin.getline(a,100);
    cin.getline(b,100);
    for(i=0;a[i]!='\0';i++);
    i=i-1;

    for(int j=0;b[j]!='\0';i++){
        a[i]=b[j];
        j++;
    }

    cout<<a;
}
