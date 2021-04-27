#include<bits/stdc++.h>
using namespace std;

void decToBinary(unsigned long long n,int* num)
{
    // array to store binary number
    int binaryNum[64];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        num[j] = binaryNum[j];
}
unsigned long long binToDec(int *arr)
{
    unsigned long long num = 0;
    unsigned long long pow = 1;
    for(int i=0;i<64;i++){
        unsigned long long x = arr[i];
        num = num + pow*x;
        pow *= 2;
    }
    return num;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unsigned long long x,y,z,l,r,func =0,out,index;

        cin>>x>>y>>l>>r;

        for(unsigned long long i=l;i<=r;i++)
        {
            unsigned long long curr = (x&i)*(y&i);
            if(curr>func){
                func = curr;
                index = i;
            }
        }
        cout<<"correct : "<<func<<" "<<index<<endl;




        int xa[64] = {};
        int ya[64] = {};
        int za[64] = {};
        int la[64] = {};
        int ra[64] = {};
        decToBinary(x,xa);
        decToBinary(y,ya);
        decToBinary(l,la);
        decToBinary(r,ra);
        z = x|y;
        decToBinary(z,za);

        int i = 63;
        while(ra[i] == 0){
            za[i] = 0;
            i--;
        }
        int j = i;

        while(j>=0){
            if(ra[j]==0)
            {
                za[j] = 0;
            }
            else{
                if(xa[j]==1 || ya[j]==1){

                }
                else{
                    za[j] = 0;
                }
            }


            j--;
        }
        unsigned long long k = binToDec(za);
        unsigned long long m = (x&k)*(y&k);
        cout<<m<<" "<<k<<endl;
    }

}
