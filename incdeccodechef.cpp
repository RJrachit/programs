#include<bits/stdc++.h>
using namespace std;




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        //cout<<t<<" t";
        cin>>n;
        int arr[n];
        int h[100000] = {};
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        bool flag = false;
        for(int i=0;i<n;i++){
            h[arr[i]] += 1;
            if(h[arr[i]]>2){
                cout<<"NO"<<endl;
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        if(arr[n-1] == arr[n-2]){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(h[arr[i]] == 2){
                ans.push_back(arr[i]);
                h[arr[i]] -= 1;
            }
        }

        for(int i=n-1;i>=0;i--){
            if(h[arr[i]] == 1){
                ans.push_back(arr[i]);
                h[arr[i]] -= 1;
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
