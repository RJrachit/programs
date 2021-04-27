#include <iostream>
using namespace std;

void test(){
    int n,k;
    cin>>n>>k;
    bool * arr = new bool[n];
    int total = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            total++;
        }
    }


    int j=k-1;
    int ones = 0;
    for(int i=0;i<=j;i++){
        if(arr[i] == 1){
            ones++;
        }
    }
    j++;
    int minOnes = ones;
    for(int i=1;j<n;i++,j++){

        if(arr[i-1]==1){
            ones--;
        }
        if(arr[j] == 1){
            ones++;
        }
        if(ones < minOnes){
            minOnes = ones;
        }
    }
    int ans = 0;
    ans += (minOnes*(minOnes+1))/2;
    total -= minOnes;
    ans += total;
    cout<<ans<<endl;
    return;

}

int main() {
    int t;
    cin>>t;
    while(t--){
        test();

    }
}
