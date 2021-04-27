#include <bits/stdc++.h>
using namespace std;


int sqs[1005];

void test(){
    // int mid = (l+h)/2;
    // cout<<sqs[mid];
    // int k;
    // cin>>k;
    // if(k==1){
    //     return true;
    // }else if(k==-1){
    //     exit(1);
    // }

    // if(test(l,mid-1)){
    //     return true;
    // }
    // if(test(mid+1,h)){
    //     return true;
    // }
    // return false;

    for(int i=1000;i>=1;i--){
        cout<<sqs[i]<<endl;

        int k;
        cin>>k;
        if(k==1){
            return ;
        }else if(k==-1){
            exit(1);
        }
    }
    return;
}

int main() {
    int t;
    cin>>t;
    for(int i=1;i<=1000;i++){
        sqs[i] = i*i;
    }
    while(t--){
        test();
    }
}
