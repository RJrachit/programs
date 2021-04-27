#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct graph
{
    int N,M;
    unordered_map<int, unordered_map<int, vector<pair<int,int> > > > m;

    graph(int n,int m)
    {
        N = n;
        M = m;
    }

    void addedge(int i,int j,int u,int v)
    {
        m[i][j].push_back(make_pair(u,v));
        m[u][v].push_back(make_pair(i,j));
    }
    void deleteEdge(int i,int j)
    {
        vector<pair<int,int> > :: iterator itvector;
        for(itvector = m[i][j].begin();itvector != m[i][j].end();itvector++)
        {
            int u = itvector->first;
            int v = itvector->second;
            m[u][v]
        }
    }

    void show()
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                cout<<i<<","<<j<<"-->";
                vector<pair<int,int> > :: iterator it = m[i][j].begin();
                for(; it != m[i][j].end();it++)
                {
                    cout<<it->first<<","<<it->second<<"   ";
                }
                cout<<endl;
            }
        }
    }
};

int main()
{
    graph g(4,4);
    g.addedge(1,1,1,3);
    g.addedge(1,1,3,1);
    g.addedge(1,3,2,3);
    g.addedge(2,3,2,4);
    g.addedge(2,3,3,3);
    g.addedge(3,3,3,4);
    g.show();cout<<"========================";
    g.deleteEdge(2,3);
    g.show();
}
