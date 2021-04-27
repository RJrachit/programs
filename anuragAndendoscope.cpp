#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<queue>
#include<list>
#include<vector>
using namespace std;

struct node
{
    int * b;
    node(int m){
        b = new int[m];
    }
};

class direction
{
    int d1[4][2] = {{1,0},{0,1},{-1,0},{0,-1}} ;
    int d2[4][2] = {{1,0},{-1,0},{0,0},{0,0}} ;
    int d3[4][2] = {{0,1},{0,-1},{0,0},{0,0}} ;
    int d4[4][2] = {{-1,0},{0,1},{0,0},{0,0}} ;
    int d5[4][2] = {{0,1},{1,0},{0,0},{0,0}} ;
    int d6[4][2] = {{1,0},{0,-1},{0,0},{0,0}} ;
    int d7[4][2] = {{0,-1},{-1,0},{0,0},{0,0}} ;

public:

    int * findDir(int k,int d[4][2])
    {
        if(k==1){
            for(int i=0;i<4;i++){
                for(int j=0;j<2;j++)
                    d[i][j]=d1[i][j];
            }
        }
        else if(k==2){
            for(int i=0;i<4;i++){
                for(int j=0;j<2;j++)
                    d[i][j]=d2[i][j];
            }
        }
        else if(k==3){
            for(int i=0;i<4;i++){
                for(int j=0;j<2;j++)
                    d[i][j]=d3[i][j];
            }
        }
        else if(k==4){
            for(int i=0;i<4;i++){
                for(int j=0;j<2;j++)
                    d[i][j]=d4[i][j];
            }
        }
        else if(k==5){
            for(int i=0;i<4;i++){
                for(int j=0;j<2;j++)
                    d[i][j]=d5[i][j];
            }
        }
        else if(k==6){
            for(int i=0;i<4;i++){
                for(int j=0;j<2;j++)
                    d[i][j]=d6[i][j];
            }
        }
        else if(k==7){
            for(int i=0;i<4;i++){
                for(int j=0;j<2;j++)
                    d[i][j]=d7[i][j];
            }}
            else{
                for(int i=0;i<4;i++){
                    for(int j=0;j<2;j++)
                    {
                        d[i][j]=0;
                    }
                }
            }

    }


};

bool exist(node ** a,int x,int y,int p,int q,int n,int m)
{
    direction dir;
    int d[4][2];
    dir.findDir(a[p]->b[q],d);
    for(int i2 =0; i2<4;i2++)
        {
            if((d[i2][0]!=0 || d[i2][1]!=0) && p+d[i2][0] >= 0 && q+d[i2][1] >= 0 && p+d[i2][0] < n && q+d[i2][1] < m)
            {

                if(p+d[i2][0]==x && q+d[i2][1]==y){

                    return true;
                }
            }
        }
    return false;
}

class graph
{
    int N,M;
    unordered_map<int, unordered_map<int ,list<pair<int,int> > > > m;
public:
    graph(int n,int m){
        this->N=n;
        this->M=m;
    }
    void addedge(int x,int y,int a,int b)
    {
        {
            m[x][y].push_back(make_pair(a,b));
            m[a][b].push_back(make_pair(x,y));
        }
    }
    void print()
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cout<<i<<","<<j;
                for(auto it = m[i][j].begin();it != m[i][j].end() ;it++)
                {
                    cout<<" ("<<it->first<<","<<it->second<<") ";
                }
                cout<<endl;
            }
        }
    }
    int dfs(int x,int y,int l,bool visited[][51])
    {
        if(visited[x][y]){
            return 0;
        }
        int c=1;
        //cout<<"("<<x<<","<<y<<")"<<" ";
        visited[x][y] = 1;
        if(l==0){
            return c;
        }


        for(auto it = m[x][y].begin();it!=m[x][y].end();it++)
        {
            c += dfs(it->first,it->second,l-1,visited);

        }
        return c;
    }
    int dfsdriver(int x,int y,int l)
    {
        bool visited[51][51];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                visited[i][j]=0;
            }
        }
        int c = dfs(x,y,l-1,visited);
        return c;
    }
};


int main()
{
    int t;
    cin>>t;
    int i=0;
    while(i<t)
    {
        int n,m,x,y,l;
        cin>>n>>m>>x>>y>>l;

        node ** a = new node*[n];
        for(int i=0;i<n;i++)
        {
            a[i] = new node(m);
            for(int j=0;j<m;j++)
            {
                int data;
                cin>>data;
                a[i]->b[j] = data;
            }
        }
        direction dir;
        graph g(n,m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j+=2)
            {
                int d[4][2];
                dir.findDir(a[i]->b[j],d);

                for(int i2 =0; i2<4;i2++)
                {
                    if((d[i2][0]!=0 || d[i2][1]!=0) && i+d[i2][0] >= 0 && j+d[i2][1] >= 0 && i+d[i2][0] < n && j+d[i2][1] < m)
                    {

                        if(exist(a,i,j,i+d[i2][0],j+d[i2][1],n,m))
                        {
                            g.addedge(i,j,i+d[i2][0],j+d[i2][1]);
                        }
                    }
                }
            }
            i++;
            if(i==n){
                break;
            }
            for(int j=1;j<m;j+=2)
            {
                int d[4][2];
                dir.findDir(a[i]->b[j],d);

                for(int i2 =0; i2<4;i2++)
                {
                    if((d[i2][0]!=0 || d[i2][1]!=0) && i+d[i2][0] >= 0 && j+d[i2][1] >= 0 && i+d[i2][0] < n && j+d[i2][1] < m)
                    {

                        if(exist(a,i,j,i+d[i2][0],j+d[i2][1],n,m))
                        {
                            g.addedge(i,j,i+d[i2][0],j+d[i2][1]);
                        }
                    }
                }
            }
        }
        //g.print();
        //cout<<"#"<<i+1<<" "<<g.dfsdriver(x,y,l)<<endl;;
        if(a[x]->b[y]==0){
            cout<<0<<endl;
        }
        else
        cout<<g.dfsdriver(x,y,l)<<endl;;
        for(int i=0;i<n;i++)
        {
            delete a[i];
        }
        delete a;
        i++;
    }

}
