#include <bits/stdc++.h>
using namespace std;

void test(){
    int n,m,k;
    cin>>n>>m>>k;
    if( k==0){
        cout<<n*m<<endl;
        return;
    }
    int * x = new int[k];
    int * y = new int[k];

    for(int i=0;i<k;i++){
        cin>>x[i];
        cin>>y[i];
    }
    sort(x,x+k);
    sort(y,y+k);
    int maxx = x[0]-1;
    int maxy = y[0]-1;
    for(int i=1;i<k;i++){
        maxx = max(maxx,x[i]-x[i-1]-1);
        maxy = max(maxy,y[i]-y[i-1]-1);
    }
    maxx = max(maxx,n-x[k-1]);
    maxy = max(maxy,m-y[k-1]);
    cout<<maxx*maxy<<endl;
    return;

}

int main() {
    int t;
    cin>>t;
    while(t--){
        test();
    }
    return 0;
}
