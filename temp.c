
#include<iostream>
using namespace std;
int MAX = INT8_MAX;
int* hash_array(int A[], int n)
{

    int* hash = new int[MAX]; //MAX is the maximum possible value of A[i]
    for(int i=0;i<=MAX;i++) hash[i]=-1; //initialize hash to -1.
    int count = 0;
    for(int i=0;i<n;i++) // Loop through elements of array
    {
        if(hash[A[i]] == -1) // A[i] was not assigned any hash before
        {
            hash[A[i]] = count; // Assigning hash to A[i]
            count++;
            continue;
        }
        for(int j = 0;j<i;j++)
        {
            if(hash[A[j]] > hash[A[i]]) // All the hashes greater than previous hash of A[i] are decremented.
                hash[A[j]]--;
        }
        hash[A[i]] = count - 1; // Assigning a new hash to A[i]
    }
    return hash;
}

int main()
{
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int * hash =0;
    hash_array(a,n);
    for(int i=0;i<MAX;i++)
    {
        if(hash[i] != -1)
        {
            cout<<hash[i]<<endl;
        }
    }
	return 0;
}
