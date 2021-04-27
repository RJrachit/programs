#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int> > m,int k,int src,bool grp[20][20],bool * visited)
{
    if(visited[src]){
        return;
    }

    visited[src] = 1;
    for(auto it = m[src].begin();it<m[src].end();it++)
    {
        grp[k][*it] = 1;
        dfs(m,k,*it,grp,visited);
    }

    return;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        bool done[20] = {};
        cin>>n>>m;
        unordered_map<int , vector<int> > mp;
        int arr[n+1];
        bool grp[20][20] = {};
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            if(arr[i]==i){
            }
        }
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }

        for(int i=1;i<=n;i++){
            bool  visited[20] = {};
            dfs(mp,i,i,grp,visited);
        }

        int cost = 0;
        for(int i=1;i<=n;i++)
        {
            if(i != arr[i]){
                int j = i;
                int des = arr[j];
                while(des != j && des != i)
                {
                    if(grp[j][des]==1){
                        cout<<"swapped 1 : "<<j<<","<<des<<endl;
                        int temp = arr[j];
                        arr[j] = arr[des];
                        arr[des] = temp;
                        des = arr[j];
                        continue;
                    }
                    j = des;
                    des = arr[des];
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(i != arr[i]){
                int des = arr[i];
                while(des != i)
                {
                    cout<<"swapped 2 : "<<i<<","<<des<<endl;
                    int temp = arr[i];
                    arr[i] = arr[des];
                    arr[des] = temp;
                    des = arr[i];
                    cost++;
                }
            }
        }

        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl<<"cost = "<<cost;
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<grp[i][j]<<" ";
            }
            cout<<endl;
        }
        10 6
8 10 3 1 2 6 4 5 9 7
1 2
2 5
2 10
5 6
3 8
5 7
        */
    }
}
