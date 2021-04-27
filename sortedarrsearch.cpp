#include<iostream>
using namespace std;
int main()
{
   int a[100][100],n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
        cin>>a[i][j];
   }
   int num;
   cin>>num;

   int i=0,j=m-1;
   while(i<n && j>=0)
   {
       if(num==a[i][j]){
        cout<<"found "<<i<<" "<<j;
        return 0;
       }
       else if(num>a[i][j])
        i++;
       else
        j--;
   }
   cout<<"not found";

}
