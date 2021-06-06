#include <iostream>
using namespace std;
#define ll long long 
void test(){
    ll x,y,k;
    cin>>x>>y>>k;
    ll ans = x - 1;
    ans += x*(y-1);
    if(ans != k){
        cout<<"NO";
    }else{
        cout<<"YES";
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        test();
        cout<<endl;
    }
}