#include<iostream>
#include<string.h>
using namespace std;
int count(char s[],int i)
{
    int c=0;
    if(s[i+1]==0)
    {
        return 0;
    }
    if(s[i]=='h'){
        if(s[i+1]=='i'){
            if(s[i+2]=='t'){
                c=count(s,i+1);
                return c;
            }

            c+=1;
            c+=count(s,i+1);
            return c;
        }
    }
    c+=count(s,i+1);
    return c;
}

void remove(char s[],int i,int index[],int &k)
{
    if(s[i+1]==0){
        return;
    }
    if(s[i]=='h')
    {
        if(s[i+1]=='i')
        {
            if(s[i+2]=='t'){
                remove(s,i+1,index,k);
                return;
            }
            index[k]=i;
            k++;
            for(int j=i;s[j]!=0;j++){
                s[j]=s[j+2];
            }
            remove(s,i,index,k);
            return;

        }
    }
    remove(s,i+1,index,k);
}

void bye(char s[],int i,int index[],int j,int k)
{
    if(i==index[j] && j<k){
        j++;
        cout<<"bye";
        bye(s,i,index,j,k);
        return;
    }
    if(s[i]==0)
    {
        return;
    }
    cout<<s[i];
    bye(s,i+1,index,j,k);


}



int main()
{
    char s[1000];
    int index[1000];
    int k=0;
    cin>>s;
    cout<<count(s,0)<<endl;

    remove(s,0,index,k);
    cout<<s;

    cout<<endl;
    bye(s,0,index,0,k);


	return 0;
}
