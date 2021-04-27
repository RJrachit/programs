#include<iostream>
using namespace std;

/*

int minJumps(int arr[], int n)
{
    int *jumps = new int[n]; // jumps[n-1] will hold the result
    int i, j;

    if (n == 0 || arr[0] == 0)
        return INT_MAX;

    jumps[0] = 0;

    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n-1];
}

*/



int main()
{
    int n;
    cin>>n;
    int a[10000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int * dp = new int[n+1];
    dp[0] = 1;
    for(int i=0;i<n;i++){
        dp[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=a[i] && j<n;j++)
        {
            if(dp[i+j]==0){
                dp[i+j] = dp[i] +1 ;
            }
            else{
                dp[i+j] = min(dp[i+j],dp[i]+1);
            }
        }
    }

    cout<<dp[n-1];
}
