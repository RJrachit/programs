#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    if(b.second==a.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int * a = new int[n];
        int freq[1000] = {};
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        ++freq[a[i]];
	    }

	    vector<pair<int,int> > v;
	    for(int i=0;i<n;i++){
	        if(freq[a[i]]== -1){
	            continue;
	        }
	        cout<<freq[a[i]];
	        v.push_back(make_pair(a[i],freq[a[i]]));
	        freq[a[i]] = -1;
	    }

	    sort(v.begin(),v.end(),compare);
	    for(int i=0;i<v.size();i++){

           // for(int j=0;j<v[i].second;j++)
                //cout<<v[i].first<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
