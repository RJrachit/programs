#include <iostream>
using namespace std;
#define ll long long
#define db double
const int s = 100000;
ll k;
void print(db * dp[],ll n,ll m){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

db findSum(db * dp[],int i,int j,int len){
    int x = i + len -1;
    int y = j + len -1;
    db left,up,add = 0;
    
    if(i-1 >= 0 && j-1 >= 0){
        add = dp[i-1][j-1];
    }
    if(i-1 >= 0){
        up = dp[i-1][y];
    }else{
        up = 0;
    }
    
    if(j-1 >= 0){
        left = dp[x][j-1];
    }else{
        left = 0;
    }
    
    
    
    return dp[x][y] - left - up + add;
}

int binS(int row,int l,int r,int len,db * dp[]){
    int col = r;
    while(l < r){
        ll m = (l+r)/2;
        
        double sum = findSum(dp,row,m,len);
        double avg = double(sum)/double(len*len);
        
        if(avg >= k){
            r = m;
        }else{
            l = m + 1;
        } 
    }
    double sum = findSum(dp,row,r,len);
    double avg = double(sum)/double(len*len);
    if(avg >= k){
        // cout<<row<<" "<<r<<"avg="<<avg<<" val="<<col-r+1<<endl;;
        
        return col- r + 1;
    }
    return 0;
}

void test(){
    ll n,m;
    cin>>n>>m>>k;
    db * dp[n];
    for(int i=0;i<n;i++){
        dp[i] = new db[m];
    }
    ll arr[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    for(int i=1;i<m;i++){
        dp[0][i] = arr[0][i] + dp[0][i-1];
    }
    for(int i=1;i<n;i++){
        ll sum = 0;
        for(int j=0;j<m;j++){
            sum += arr[i][j];
            dp[i][j] = dp[i-1][j] + sum;
        }
    }
    // print(dp,n,m);
    
    int len = 1;
    int maxLen = min(n,m);
    ll ans = 0;
    while(len <= maxLen){
        
        for(int i = 0;i<=n-len;i++){
            
            ans += binS(i,0,m-len,len,dp);
                
        }
        len++;
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
