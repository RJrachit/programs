#include <iostream>
using namespace std;

int solve(int * arr,int n){

    int sqSum = 0;
    int sum = 0;
    int maxSum = 0;

    for(int i=0;i<n;i++){
        int curr = arr[i]*arr[i] + sum;

        if(curr > sqSum){
            sqSum = curr;
        }else{
            sqSum += arr[i];
        }
        if(maxSum < sqSum){
            maxSum = sqSum;
        }
        sum += arr[i];

        if(sum < 0){
            sum = 0;
        }

    }

    return maxSum;
}

int main() {
    int n;;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n)<<endl;
    return 0;
}
