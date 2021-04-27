#include<iostream>
using namespace std;

/*7
10 1 2 7 6 1 5
8
*/
bool targetsum(int * a,int n,int target,int i,int sum)
{
    if(sum>target){
        return false;
    }
    if(sum==target){
        return true;
    }

    for(int j=i;j<n;j++)
    {
        sum=sum+a[j];
        if(targetsum(a,n,target,j+1,sum)){
            cout<<a[j]<<" ";
            return true;
        }
        sum-=a[j];
    }
    return false;
}


int main()
{
    int n,target,a[15];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=a[j];
            }

        }
    }
    cin>>target;
    targetsum(a,n,target,0,0);
}
