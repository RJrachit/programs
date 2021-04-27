#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        long long int dp[100005]={};
        long long int previous_count[200];
        for(int i=0;i<200;i++){
            previous_count[i]=-1;
        }
        dp[0] = 1;
        long int mod = 1000000007;
        for(int i=1;i<=s.length();i++)
        {
            dp[i] = (dp[i-1]*2)%mod;
            if(previous_count[s[i-1]]!=-1){
                dp[i] = (dp[i] - dp[previous_count[s[i-1]]-1]+mod)%mod;
            }
            previous_count[s[i-1]] = i;
        }
        cout<<dp[s.length()]<<endl;
    }
}
