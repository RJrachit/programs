#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
using namespace std;
int dp[100000];
int lis(int* a,int n)
{
    for(int i=0;i<n;i++){
        dp[i] = 1;
    }
    for(int i=1;i<n;i++)
    {
        int best = 1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j]){
                int temp = dp[j]+dp[i];
                best = max(temp,best);
            }
        }
        dp[i] = best;
    }
    int m = INT_MIN;
    for(int i=0;i<n;i++){
        if(dp[i]>m){
            m = dp[i];
        }
    }
    return m;
}

int main()
{
    int n;
    cin>>n;
    int * a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<lis(a,n);
}
