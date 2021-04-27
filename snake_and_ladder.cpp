#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<queue>
#include<list>
#include<vector>
using namespace std;

class graph
{
    int boxes;
    int lc;
    int sc;
    list<int> * l;
public:
    graph(int n,int l,int s)
    {
        boxes = n;
        lc = l;
        sc = s;
        this->l = new list<int>[n+1];
    }
    void addedge(int u,int v)
    {
        l[u].push_back(v);
    }

    int bfs(int src)
    {
        vector<bool> visited;
        for(int i=0;i<=boxes;i++)
        {
            visited.push_back(0);
        }

        visited[src] = true;
        queue<int> q;
        q.push(src);
        int * dist = new int[boxes];
        for(int i=0;i<=boxes;i++)
        {
            dist[i] = INT8_MAX;
        }
        dist[src] = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(auto it = l[curr].begin();it != l[curr].end();it++)
            {
                if(!visited[*it])
                {
                    visited[*it] = true;
                    q.push(*it);
                    dist[*it] = dist[curr] + 1;
                }
            }
        }
        return dist[boxes];
    }
    void print()
    {
        for(int i=1;i<=boxes;i++)
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

};

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,l,s;
        cin>>n>>l>>s;
        graph g(n,l,s);
        int * boxes = new int[n+1];
        for(int i=0;i<=n;i++)
        {
            boxes[i]= 0;
        }
        for(int i=0;i<s+l;i++)
        {
            int v,u;
            cin>>v>>u;
            boxes[v] = u-v;
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=1;j<=6 && i+j<=n;j++)
            {
                g.addedge(i,i+j+boxes[i+j]);
            }
        }
        //g.print();
        cout<<g.bfs(1)<<endl;
    }
}
