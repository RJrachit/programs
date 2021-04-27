#include<iostream>
#include<string.h>
using namespace std;
int dp[2005][2005] = {};
int editDistanceRec(char str1[],char str2[],int i,int j)
{
    if(j >= strlen(str2) || i>=strlen(str1)){
        return 0;
    }

    if(str1[i]==str2[j]){
        return editDistanceRec(str1,str2,i+1,j+1);
    }
    else{
        int q1 = editDistanceRec(str1,str2,i,j+1)+1;
        int q2 = editDistanceRec(str1,str2,i+1,j+1)+1;
        int q3 = editDistanceRec(str1,str2,i+1,j)+1;
        return min(q1,min(q2,q3));
    }
}

int editDistanceDP(char str1[],char str2[])
{

    int a = strlen(str1);
    int b = strlen(str2);

    for(int i=0;i <= a;i++){
        dp[0][i] = i;
    }
    for(int i=0;i<=b;i++){
        dp[i][0] = i;
    }

    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=a;j++)
        {
            if(str1[j-1] == str2[i-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min( dp[i-1][j] + 1 , dp[i][j-1]+1 ) ; //insertion , deletion
                dp[i][j] = min( dp[i-1][j-1]+1 , dp[i][j] ) ;     // replacement
            }
        }
    }

    for(int i=0;i<=b;i++){
        for(int j=0;j<=a;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[b][a];
}

int main()
{
    char str1[2000] ,str2[2000] ;
    cin>>str1>>str2;
    cout<<editDistanceDP(str1,str2);
}
