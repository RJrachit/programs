#include <bits/stdc++.h>
using namespace std;
vector<int> ans;

void print(){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;
}

void sum(int i,int n,int k,int * arr,int s){

    if(i >= n){
        return;
    }

    if(s + arr[i] == k){
        ans.push_back(arr[i]);
        print();
        ans.pop_back();
    }
    sum(i+1,n,k,arr,s); //exclude arr[i]
    
    ans.push_back(arr[i]);
    sum(i+1,n,k,arr,s+arr[i]); //include arr[i]
    ans.pop_back();
    return;
}
int main() {
    int n = 7,k = 6;
    int arr[] = {1,2,3,4,5,1,2};
    int s = 0;
    sum(0,n,k,arr,s);
    return 0;
}
