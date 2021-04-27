#include <bits/stdc++.h>
using namespace std;
#define M 1000000007


double slope(pair<double,double> a,pair<double,double> b)
{
    if(a.first == b.first){
        return 100;
    }

    return (a.second - b.second)/(a.first - b.first);
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        pair<double,double> points[n];
        pair<double,double> query[q];
        for(int i=0;i<n;i++){
            cin>>points[i].first;
            cin>>points[i].second;
        }
        pair<double,double> iso[q];

        for(int i=0;i<q;i++){
            cin>>query[i].first;
            cin>>query[i].second;
            double temp = (query[i].second - query[i].first)/2;
            pair<double,double> p = make_pair(temp + query[i].first,temp);
            iso[i] = p;
        }

        for(int i=0;i<q;i++)
        {
            int sum = 0;

            for(int j=0;j<n;j++)
            {
                if(abs(slope(iso[i],points[j]))>=1 && iso[i].second >= points[j].second){
                    //cout<<points[j].first<<","<<points[j].second<<" i-"<<i<<" ";
                    sum++;
                }
            }
            cout<<sum<<" ";
        }
        cout<<endl;
    }

    return 0;
}
