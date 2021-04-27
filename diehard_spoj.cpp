#include <bits/stdc++.h>
using namespace std;
int memo[2000][2000];
int solve(int h,int a,int flag,int ans){
    if((h <= 0 || a <= 0) && flag){
        return ans-1;
    }
    if(h <= 0 || a <= 0){
        return ans;
    }
    if(memo[h][a]){
        return memo[h][a];
    }
    if(flag){
        return memo[h][a] = max(memo[h][a],solve(h+3,a+2,false,ans+1));
    }else{
        memo[h][a] = max(memo[h][a],max(solve(h-5,a-10,true,ans+1),solve(h-20,a+5,true,ans+1)));
        return memo[h][a];
    }
}


void test(){
    int h,a;
    cin>>h>>a;
    cout<<solve(h,a,true,0)<<endl;
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--){

        for(int i=0;i<2000;i++){
            for(int j=0;j<2000;j++){
                memo[i][j] = 0;
            }
        }
        test();
    }
}
