#include <iostream>
using namespace std;
#define ll unsigned long long
void test(){
    ll n;
    cin>>n;
    
    if(n == 0){
        cout<<0;
        return;
    }else if(n == 1){
        cout<<20;
        return;
    }else if(n == 2){
        cout<<36;
        return;
    }else if(n == 3){
        cout<<51;
        return;
    }
    else if(n == 4){
        cout<<60;
        return;
    }
    int last = n%4;
    // int levels = n/4;
    
    ll ans = 0;
    
    ans += ((n-last)/4)*44;
    
    // if(n >= 4){
    //     ans += 16 - last*4;    
    // }
    if(last == 0){
        ans += 16;
    }else if(last == 1){
        ans += 32;
    }else if(last == 2){
        ans += 44;
    }else if(last == 3){
        ans += 55;
    }
    cout<<ans;
    return;
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    test();
	    cout<<endl;
	}
	return 0;
}
