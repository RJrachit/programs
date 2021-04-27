#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

struct graph
{
    int n,M,k,e;
    unordered_map< int,vector< int> > m;
    graph(int N,int M,int K,int E){
        n = N;
        this->M = M;
        k = K;
        e = E;
    }
    void addedge( int u, int v,bool def = true)
    {
        m[u].push_back(v);
        if(def)
            m[v].push_back(u);
    }



    void shortestpath(int src,pair< int, int>* arr){
        vector<int> dist;
        for(int i=0;i<=e;i++){
            dist.push_back(INT_MAX);
        }

        dist[src] = 0;
        set<pair<double,int> > s;
        // dist , vertex  --- so that sorted in order of weight
        s.insert(make_pair(0,src));



    }




    void print()
    {
        for(auto it = m.begin(); it != m.end();it++)
        {
            cout<<it->first<<" : ";
            for(auto it2 = m[it->first].begin() ; it2!= m[it->first].end();it2++){
                cout<<*it2<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
         int x,y;
        cin>>x>>y;
         int n,m,k;

        cin>>n>>m>>k;

        int e = n+m+k;
        pair< int, int>* arr = new pair< int, int>[n+m+k+1];

        int i=1;
        for(;i<=n;i++){
            cin>>arr[i].first;
            cin>>arr[i].second;
        }
        int j = i;
        for(;i<=n+m;i++){
            cin>>arr[i].first;
            cin>>arr[i].second;
        }
        int l = i;

        for(;i<=n+m+k;i++){
            cin>>arr[i].first;
            cin>>arr[i].second;
        }
        m = j;
        k = l;
        graph g(n,m,k,e);
        for( i = 1;i<=n;i++){
            for(j = m;j<k;j++){
                g.addedge(i,j);
            }
        }
        for( i = 1;i<=n;i++){
            for(j = k;j<=e;j++){
                g.addedge(i,j,false);
            }
        }
        for( i = m;i<k;i++){
            for(j = k;j<=e;j++){
                g.addedge(i,j,false);
            }
        }
        for(i=1;i<k;i++){
            g.addedge(0,i,false);
        }
        g.print();

    }

    return 0;
}
