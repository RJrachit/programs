#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<queue>
#include<list>
#include<vector>
using namespace std;
int n,m;
pair<int,int> direction(int k)
{
    if(k==1) //up
    {
        return make_pair(-1,0);
    }
    else if(k==2) //down
    {
        return make_pair(1,0);
    }
    else if(k==3) //right
    {
        return make_pair(0,1);
    }
    else if(k==4) //left
    {
        return make_pair(0,-1);
    }
}

int dfs(int i,int j,bool visited[][1010],bool pond[][1010])
{
    if(visited[i][j])
    {
        return 0;
    }
    visited[i][j] = 1;

    if(pond[i][j] == 0){
        return 0;
    }

    int c = 1;
    //cout<<i<<","<<j<<"--";
    for(int k=1;k<=4;k++)
    {
        pair<int,int> p = direction(k);

        if(i+p.first >=0 && i+p.first < n && j+p.second >=0 && j+p.second < m){
            c += dfs(i+p.first,j+p.second,visited,pond);
        }
    }
    return c;
}

int main()
{

    cin>>n>>m;
    bool pond[1010][1010];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            cin>>pond[i][j];
        }
    }
    int max = INT_MIN;
    bool visited[1010][1010];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(pond[i][j]==0)
            {
                pond[i][j]=1;

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++){
                        visited[i][j] = 0;
                    }
                }

                int c = dfs(i,j,visited,pond);

                if(c>max){
                    max = c;
                }
                //cout<<endl;
                pond[i][j]=0;
            }
        }
    }
    cout<<max;


}
