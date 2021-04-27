#include<bits/stdc++.h>
using namespace std;

bool possible(int *arr,int val,int n,int m){

    int cnt = 0;
    for(int i=0;i<m;i++){
        int curr = 0;
        int C = val*2/arr[i];
        while(curr*curr + curr <= C){
            curr++;
        }
        cnt += curr;

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
    cout<<mid<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        test();
    }

    return 0;

}