#include<iostream>
using namespace std;
bool check7(int a[],int n,int i,int m)
{
    if(i==n){
        return 0;
    }
    if(a[i]==m){
        return 1;
    }
    return check7(a,n,i+1,m);

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
    if(check7(a,n,0,m))
        cout<<"true";
    else
        cout<<"false";


}
