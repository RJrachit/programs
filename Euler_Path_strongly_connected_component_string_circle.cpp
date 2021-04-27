#include <bits/stdc++.h>
#include<string>
using namespace std;

class graph
{
    unordered_map<char ,vector<char> > g;
    unordered_map<char ,vector<char> > gt;
    stack<char> s;
    int  in[257] = {};
    int  out[257] = {};
    int *edges;

    void addEdgeGt(char u,char v)
    {
        gt[u].push_back(v);
        return;
    }

    void formTranspose()
    {
        for(auto it= g.begin();it!=g.end();it++)
        {
            for(auto it2 = g[it->first].begin();it2 != g[it->first].end();it2++)
            {
                addEdgeGt(*it2,it->first);
            }
        }
    }

    void dfs(char ,bool*);
    bool isSCC();
    bool isEqual();
    void makeStack(char ,bool * );
    bool checkComponent();

public:
    graph(int n)
    {
        edges = new int[n];
    }


    void addEdge(char u,char v)
    {
        g[u].push_back(v);
        out[u]++;
        in[v]++;
        return;
    }

    void printGraph()
    {
        for(auto it= g.begin();it!=g.end();it++)
        {
            cout<<it->first<<" : ";
            for(auto it2 = g[it->first].begin();it2 != g[it->first].end();it2++)
            {
                cout<<*it2<<" ";
            }
            cout<<endl;
        }
    }
    void printGraphT()
    {
        for(auto it= gt.begin();it!=gt.end();it++)
        {
            cout<<it->first<<" : ";
            for(auto it2 = gt[it->first].begin();it2 != gt[it->first].end();it2++)
            {
                cout<<*it2<<" ";
            }
            cout<<endl;
        }
    }


    bool checkEuler()
    {
        formTranspose();
        if(isSCC()==0){
            return false;
        }
        if(isEqual()==0){
            return false;
        }
        return true;
    }
};

bool graph :: isEqual(){
    for(int i=0;i<257;i++){
        if(out[i]!=in[i]){
            return false;
        }
    }
    return true;
}

void graph :: makeStack(char src,bool * visited)
{
    visited[src] = true;

    for(auto it = g[src].begin();it != g[src].end() ;it++)
    {
        if(!visited[*it]){
            makeStack(*it,visited);
        }
    }
    s.push(src);
    return;
}
void graph :: dfs(char src,bool * visited)
{
    if(visited[src]){
        return;
    }
    visited[src] = true;

    for(auto it = gt[src].begin();it != gt[src].end();it++)
    {
        dfs(*it,visited);
    }
    return;
}
bool graph::checkComponent()
{
    bool visited[257] = {};
    bool flag = false;

    while(!s.empty())
    {
        char src = s.top();
        s.pop();
        if(!visited[src]){
            if(flag){
                return false;
            }
            dfs(src,visited);
            flag = true;
        }
    }
    return true;
}

bool graph :: isSCC()
{
    auto it = g.begin();
    bool visited[257] = {};
    for(;it != g.end();it++){
        if(!visited[it->first]){
                //cout<<it->first;
            makeStack(it->first,visited);
        }
    }
    bool checkSCC = checkComponent();
    return checkSCC;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string * str = new string[n];
        graph g(n);
        for(int i=0;i<n;i++){
            cin>>str[i];
            char en = str[i][str[i].length()-1];
            char st = str[i][0];
            g.addEdge(st,en);
        }
        if(g.checkEuler()){
            cout<<"1"<<endl;
        }
        else{
            cout<<"0"<<endl;
        }

        g.printGraph();
        cout<<"************";
        g.printGraphT();
    }
}
