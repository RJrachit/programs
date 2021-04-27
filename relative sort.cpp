#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    unordered_map<int,int> freq;
	    int a[n];
	    int b[m];

	    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(freq.find(a[i]) != freq.end()){
                freq[a[i]]++;
            }
            else{
                freq[a[i]] = 1;
            }
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        int k=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<freq[b[i]];j++){
                a[k++] = b[i];

            }

            freq.erase(freq.find(b[i]));
        }
        int p = k;
        for(auto it = freq.begin();it != freq.end();it++){
            for(auto i=0;i <it->second;i++)
                a[k++] = it->first;
        }
        sort(a+p,a+n);

        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }

        cout<<endl;


	}
	return 0;
}
