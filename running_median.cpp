#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int * a= new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    priority_queue<int> qmax;
    priority_queue<int,vector<int>,greater<int> > qmin;
    float median;
    qmax.push(a[0]);
    median = a[0];
    for(int i=1;i<n;i++)
    {
        cout<<median<<" ";
        if(a[i]>median)
        {
            qmin.push(a[i]);
        }
        else{
            qmax.push(a[i]);
        }
        if(qmin.size()==qmax.size())
        {
            median = (qmin.top()+qmax.top())/2.0;
        }
        else if(qmin.size()-1==qmax.size())
        {
            median = qmin.top();
        }
        else if(qmax.size()-1==qmin.size())
        {
            median = qmax.top();
        }
        else if(qmax.size()>qmin.size())
        {
            qmin.push(qmax.top());
            qmax.pop();
            median = (qmin.top()+qmax.top())/2.0;
        }
        else if(qmax.size()<qmin.size())
        {
            qmax.push(qmin.top());
            qmin.pop();
            median = (qmin.top()+qmax.top())/2.0;
        }
    }
    cout<<median;
}

