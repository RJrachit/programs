#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int a,b,c,d;
        cin>>a>>b>>c>>d;
        long int x,y,x1,y1,x2,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;

        if((x1==x2 && (a!=0 || b!=0)) || (y1==y2 &&(c!=0 || d!=0)))
        {
            cout<<"No"<<endl;
            continue;
        }

        long int path_x = x + b-a;
        long int path_y = y + d-c;

        if(path_x<=x2 && path_x>=x1){
            if(path_y<=y2 && path_y>=y1){
                cout<<"Yes \n";
            }
            else{
            cout<<"No \n";
            }
        }
        else{
            cout<<"No \n";
        }
    }
    return 0;
}
