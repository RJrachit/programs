#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<queue>
#include<list>
#include<vector>

using namespace std;
int dp[1010][1010] = {};
int knapsack(int * item,int * value,int n,int s)
{


    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=s;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=s;j++)
        {
            //include item[i];
            int includeCurrItem = 0;
            if(j-item[i] >= 0){
                includeCurrItem = value[i] + dp[i-1][j-item[i]];
            }
            //not include item[i];
            int notInclude = dp[i-1][j];
            dp[i][j] = max(includeCurrItem,notInclude);

        }
    }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++)
        cout<<dp[i][j]<<"       ";
        cout<<endl;
    }
    return dp[n][s];
}

int main()
{
    int n,s;
    cin>>n>>s;
    int item[1010] = {};
    int value[1010] = {};
    item[0] = 0;
    value[0] = 0;

    for(int i=1;i<=n;i++){
        cin>>item[i];
    }
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }

    int k = knapsack(item,value,n,s);
    cout<<k<<endl;
}
