#include <iostream>
using namespace std;
int j = 1;
void test(){
    int n,k,b,t;
    cin>>n>>k>>b>>t;
    int pos[n];
    int speed[n];
    for(int i=0;i<n;i++){
        cin>>pos[i];
    }
    for(int i=0;i<n;i++){
        cin>>speed[i];
    }

    int swaps = 0;
    int slowChicks = 0;
    int cnt = 0;
    for(int i=n-1;i>=0;i--){
        int canReach = speed[i]*t;
        int toReach = b-pos[i];
        if(toReach <= canReach){
            swaps += slowChicks;
            cnt++;
        }else{
            slowChicks++;
        }
        if(cnt == k){
            break;
        }
    }
    if(cnt < k){
        cout<<"Case #"<<j<<": IMPOSSIBLE";
    }else{
        cout<<"Case #"<<j<<": "<<swaps;
    }
    cout<<endl;
    return;
}

using namespace std;
int main() {
    int t;
    cin>>t;
    while(j<=t){
        test();
        j++;
    }
}
