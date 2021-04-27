#include<iostream>
using namespace std;
int main()
{
    int n,len=0,i;
    char str1[100],str2[100]={};
    cin>>n;
    cin.get();
    while(n)
    {
        cin.getline(str1,100);
        for(i=0;str1[i]!=0;i++)
        if(i>len)
        {
            for(int c=0;str1[c]!=0;c++)
                str2[c]=str1[c];
            len=i;

        }


        n--;
    }
    for(i=0;str2[i]!=0;i++)
    cout<<str2[i];
    cout<<endl;
    cout<<len+1;
    return 0;
}
