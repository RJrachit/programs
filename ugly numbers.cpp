#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

long long a[10000] = {};
/*
  alternate



  import java.util.*;
public class Solution {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt();
        while(t-- > 0) {
            int n = scn.nextInt();
            System.out.println(ugly(n));
        }

    }

    public static long ugly(int n) {
        long[] dp = new long[n + 1];
        int i2 = 0, i3 = 0, i5 = 0;
        long next_multiple_of_2 = 2;
        long next_multiple_of_3 = 3;
        long next_multiple_of_5 = 5;
        long next_ugly_no=1;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            next_ugly_no = Math.min(next_multiple_of_2, Math.min(next_multiple_of_3, next_multiple_of_5));
            dp[i]=next_ugly_no;
            if(next_multiple_of_2==next_ugly_no) {
                i2++;
                next_multiple_of_2=dp[i2]*2;
            }
            if(next_multiple_of_3==next_ugly_no) {
                i3++;
                next_multiple_of_3=dp[i3]*3;
            }
            if(next_multiple_of_5==next_ugly_no) {
                i5++;
                next_multiple_of_5=dp[i5]*5;
            }
        }
        return next_ugly_no;
    }

}





*/
int main()
{
    int t;
    cin>>t;
    a[1] = 1;
    int n2 = 2;

    while(t--)
    {
        int n;
        cin>>n;

        if(a[n]!=0){
            cout<<a[n]<<endl;
            continue;
        }

        for(int i = n2;i<=n;i++)
        {
            long long  num = a[i-1];
            long long  best = LLONG_MAX;
            for(int j=i-1;j>=1;j--)
            {
                if(a[j]*2 > num && a[j]*2 < best)
                {
                    best = a[j]*2;
                    //cout<< best<<"-";
                }
                else if(a[j]*3 > num && a[j]*3 < best)
                {
                    best = a[j]*3;
                    //cout<< best<<"-";
                }
                else if(a[j]*5 > num && a[j]*5 < best)
                {
                    best = a[j]*5;
                    //cout<< best<<"-";
                    break;
                }
            }
            a[i] = best;
        }
        cout<<a[n]<<endl;
        n2 = n;
    }
}
