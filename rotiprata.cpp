#include<bits/stdc++.h>
using namespace std;

bool possible(int *arr,int val,int n,int m){

    int cnt = 0;
    for(int i=0;i<m;i++){
        int curr = arr[i];
        int j = 2;
        while(curr <= val){
            curr += arr[i]*j;
            cnt++;
            j++;
        }

        if(cnt >= n){
            return true;
        }
    }
    return false;
}

void test(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    int st = 0;
    int en = 8*(1000)*(1000+1)/2;
    int mid = 0;
    sort(arr,arr + m);
    while(st<en){
        mid = (st+en)/2;

        if(possible(arr,mid,n,m)){
            en = mid;
        }else{
            st = mid + 1;
        }
    }
    cout<<en<<endl;
    return;
}
// 3
// 10
// 4 1 2 3 4
// 8
// 1 1
// 8
// 8 1 1 1 1 1 1 1 1
int main(){
    int t;
    cin>>t;
    while(t--){
        test();
    }

    return 0;

}