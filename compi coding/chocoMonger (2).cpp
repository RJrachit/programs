#include <bits/stdc++.h>
using namespace std;

void fill(int * bits, int num){

    for(int i =31;i>=0;i--){
        if(num & 1){
            bits[i]++;
        }
        num = num>>1;
    }
    return;
}
long long dec(int * bits){
    int pow = 1;
    long long ans = 0;
    int x = 1;
    for(int i=31;i>=0;i--){
        if(bits[i]){
            ans += pow; 
        }
        pow = pow * 2;
    }
    return ans;
}
void rem(int * bits,int num){
    if(num == 0){
        return;
    }
    for(int i =31;i>=0;i--){
        if(num & 1){
            bits[i]--;
        }
        num = num>>1;
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];    
    }
    int q[k];
    

    int bits[32] = {};
    
    for(int i=0;i<n;i++){
        fill(bits,arr[i]);
    }
    // for(int i=31;i>=0;i--){
    //     cout<<bits[i];
    // }
    cout<<dec(bits)<<endl;
    
    for(int i=0;i<k;i++){
        int ind,val;
        cin>>ind>>val;
        ind--;
        rem(bits,arr[ind]);
        arr[ind] = val;
        
        fill(bits,val);
        
        cout<<dec(bits)<<endl;
    }

    // cout<<dec(bits);
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
        // cout<<endl;
    }
}
