#include<bits/stdc++.h>
using namespace std;
vector<int> twos;
vector<int> threes;
vector<int> more;
vector<vector<int> > out;
int arr[1000000];
bool visited[1000000];
int findElements(int * arr,bool * visited,int i)
{
    int x = 0;
    while(!visited[i])
    {
        x++;
        visited[i] = 1;
        i = arr[i];
    }

    return x;
}

int solve(int * arr,int i)
{
    int a,b,c;
    while(arr[i] != i)
    {
        a = i;
        b = arr[i];
        c = arr[b];
        int nxt = arr[c];
        if(a==b || b==c || a==c){
            //twos
            twos.push_back(i);
            break;
        }

        int t = arr[b];
        arr[b] = arr[a];
        arr[a] = arr[c];
        arr[c] = t;

        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        out.push_back(v);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        twos.clear();
        threes.clear();
        more.clear();
        out.clear();

        for(int i=1;i<n+1;i++){
            cin>>arr[i];
        }



        for(int i=1;i<n+1;i++){
            visited[i] = 0;
        }

        bool flag = 1;
        for(int i=1;i<n+1;i++)
        {
            if(arr[i] == i){
                visited[i] = 1;
                continue;
            }
            flag = 0;
        }

        if(flag){
            cout<<0<<endl;
            continue;
        }

        for(int i=1;i<n+1;i++)
        {
            if(!visited[i]){
                int x = findElements(arr,visited,i);
                if(x==2){
                    twos.push_back(i);
                }
                else if(x==3){
                    threes.push_back(i);
                }
                else if(x>3){
                    more.push_back(i);
                }
            }
        }

        for(int i=1;i<n+1;i++){
            visited[i] = 0;
        }
        //solving >=threes;


        for(int i=0;i<threes.size();i++)
        {
            solve(arr,threes[i]);
        }

        for(int i=0;i<more.size();i++)
        {
            solve(arr,more[i]);
        }

        //twos
        if(twos.size()%2 != 0){
            cout<<-1<<endl;
            continue;
        }

        for(int i=0;i<twos.size();i+=2)
        {
            int a = twos[i];
            int b = arr[a];
            int c = twos[i+1];
            int d = arr[c];

            int t = arr[b];
            arr[b] = arr[a];
            arr[a] = arr[c];
            arr[c] = t;

            vector<int> v;
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            out.push_back(v);

            t = arr[a];
            arr[a] = arr[c];
            arr[c] = arr[d];
            arr[d] = t;

            vector<int> v1;
            v1.push_back(a);
            v1.push_back(d);
            v1.push_back(c);
            out.push_back(v1);
        }

        if(out.size()>k){
            cout<<-1<<endl;
        }
        else{
            cout<<out.size()<<endl;
            for(int i=0;i<out.size();i++){
                for(int j=0;j<3;j++){
                    cout<<out[i][j]<<" ";
                }
                cout<<endl;
            }
        }

    }
}
