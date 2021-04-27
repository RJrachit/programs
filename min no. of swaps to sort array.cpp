
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;
int minSwaps(int A[], int N);
// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}


/*This is a function problem.You only need to complete the function given below*/
/* You are required to complete this method */
int minSwaps(int A[], int N)
{
    int n = N,ans = 0;
    pair<int ,int > arr[n];

        for(int i=0;i<n;i++)
        {
            arr[i].first = A[i];
            arr[i].second = i;
        }
        sort(arr,arr+n);

        vector<bool> v(n,0);
        for(int i=0;i<n;i++)
        {
            int c = 0;
            if(v[i] || arr[i].second == i)
                continue;
            int j = i;
            while(!v[j])
            {
                v[j] == 1;
                j = arr[j].second;cout<<j<<" "<<arr[j].second<<endl;
                c++;

            }
            if(c>0)
            ans += c-1;
        }
        return ans;

}
