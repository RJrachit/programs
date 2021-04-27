
#include<iostream>
using namespace std;

int fact(int n){
    int f=1;
    for(int i=1;i<=n;i++)
        f=f*i;
    return f;
}
int ncr(int n){
    int com;
    int r=n;
    for(int i=0;i<=r;i++){
    com=fact(n)/(fact(i)*fact(n-i));
    cout<<com<<" ";
    }
    return 0;

}



int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ncr(i);
        cout<<endl;
    }

}
