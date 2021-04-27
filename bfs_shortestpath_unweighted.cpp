#include<iostream>
#include<queue>
#include<unordered_map>
#include<map>
#include<list>
#include<vector>
using namespace std;

template<typename T>
class graph
{

    int vertices;
    list<int> * l;
public:
    map<int,int> dist;
    graph(int n){
        vertices = n;
        l = new list<int>[n+1];

    }
    void addedge(T u,T v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print()
    {
        for(int i=1;i<=vertices;i++)
        {
            cout<<i<<"->";
            list<int> :: iterator it;
            for(it = l[i].begin();it != l[i].end();it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(int src)
    {
        vector<bool> visited;
        for(int i=0;i<=vertices;i++)
        {
            visited.push_back(false);
        }
        for(int i=1;i<=vertices;i++)
        {
            dist[i] = -1;
        }
        dist.erase(src);
        visited[src] = true;
        queue<int> q;
        list<int> :: iterator it;

        it = l[src].begin();
        for(;it != l[src].end();it++)
        {
            q.push(*it);
            visited[*it] = true;
            dist[*it] = 6;
        }
        while(!q.empty())
        {
            it = l[q.front()].begin();
            for(;it != l[q.front()].end();it++)
            {
                if(!visited[*it])
                {
                    visited[*it] = true;
                    q.push(*it);
                    dist[*it] = 6 + dist[q.front()];
                }
            }
            q.pop();
        }
    }

};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int edges;
        cin>>edges;
        graph<int> g(n);
        for(int i=0;i<edges;i++)
        {
            int u,v;
            cin>>u>>v;
            g.addedge(u,v);
        }
        int src;
        cin>>src;
        g.bfs(src);
        map<int,int> :: iterator it;
        for(it = g.dist.begin();it != g.dist.end();it++)
        {
            cout<<it->second<<" ";
        }
        cout<<endl;
    }
}

