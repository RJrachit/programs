#include<iostream>
#include<vector>
using namespace std;
class heap
{
    vector<int> v;
    bool minHeap;
    bool compare(int a,int b)
    {
        if(minHeap){
            return a<b;
        }
        else
            return a>b;
    }
    void heapify(int i)
    {
        int left = 2*i;
        int right = 2*i + 1;
        int minindex = i;
        if(left < v.size()-1 && (v[left]<v[i]))
        {
            minindex = left;
        }
        if(right < v.size()-1 && (v[right]<v[minindex]))
        {
            minindex = right;
        }
        swap(v[i],v[minindex]);
        if(minindex != i){

            heapify(minindex);
        }
        return;
    }
public:
    heap(bool type = true)
    {
        minHeap = type;
        v.push_back(-1);
    }

    void push(int data)
    {
        v.push_back(data);
        int index = v.size() - 1;
        int parent = index/2;

        while(index > 1 && (v[index]<v[parent]))
        {
            swap(v[index],v[parent]);
            index = parent;
            parent = parent/2;
        }
    }
    bool empty()
    {
        return v.size()==1;
    }
    int top()
    {
        return v[1];
    }
    void pop()
    {
        int last = v[v.size()-1];
        v[1] = v[last];
        v.pop_back();
        heapify(1);
    }
    void print()
    {
        for(int i=1;i<v.size();i++){
            cout<<v[i]<<" "<<i<<"->";
        }
    }

};
int main()
{
    heap h(false);
    h.push(2);
    h.push(9);
    h.push(90);
    h.push(34);
    h.push(-10);    h.print();
    cout<<endl;
    h.pop();
    h.print();
};

