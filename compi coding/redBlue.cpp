#include <iostream>
using namespace std;
#define ll long long 
void test(){
    ll r,b,d;
    cin>>r>>b>>d;
    if(b > r){
        ll t = r;
        r = b;
        b = t;
    }
    d++;
    ll x = b*d;
    if(r > x){
        cout<<"NO";
    }else{
        cout<<"YES";
    }
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        test();
        cout<<endl;
    }
}