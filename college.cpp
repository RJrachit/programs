#include<iostream>
#include<math.h>
using namespace std;

int pow(int num,int j)
{
    cout<<"In pow(int,int) \n";
    try
    {
        if(num == 0 && j == 0){
            throw false;
        }
        else
        {
            int n = 1;
            for(int i=0;i<j;i++){
                n *= num;
            }
            throw n;
        }
    }
    catch(bool flag){
        throw flag;
    }
    catch(int x)
    {
        throw x;
    }
    catch(...){
        throw;
    }
}

float pow(double num, int j)
{
    cout<<"In pow(float,int) \n";

    try
    {
        if(num == 0 && j == 0){
            throw false;
        }

        else
        {
            double n = 1;
            for(int i=0;i<j;i++){
                n *= num;
            }
            throw n;
        }
    }
    catch(bool flag){
        throw flag;
    }
    catch(double x)
    {
        throw x;
    }

    catch(...){throw;}

}
int main()
{
    float n ;
    try
    {
        pow(2,3);
        pow(0,5);
        pow(2.0,4);
        pow(0,0);
    }
    catch(bool x)
    {
        if(x == false){
            cout<<"cant compute \n";
        }
    }
    catch(double x){
        cout<<"answer = "<<x<<endl;
    }
    catch(int x){
        cout<<"answer = "<<x<<endl;
    }
    catch(...){
        cout<<"answer = "<<0<<endl;
    }
}
