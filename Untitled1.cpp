#include <iostream>
#include<vector>
using namespace std;

std::vector<long long> rootsHire2020(std::vector<int> roots) {
vector<long long> ans(0,roots.size()+1);

if(roots.size() == 0){
    vector<long long> x;
    return x;
}else if(roots.size()== 1){
    vector<long long> x;
    x.push_back(-roots[0]);
    x.push_back(1);
    return x;
}
cout<<"dasd";
vector<long long> firstTerm;

firstTerm.push_back(-roots[0]);
firstTerm.push_back(1);
vector<long long> secondTerm;


for(int i=1;i<roots.size();i++)
{
    secondTerm.push_back(-roots[i]);
    secondTerm.push_back(1);
    vector<long long> curr(firstTerm.size()+1);
    int currIndex = 0;

    for(int j=0;j<firstTerm.size();j++)
    {
        for(int k=0;k<secondTerm.size();k++)
        {
            long long coef = firstTerm[j]*secondTerm[k];
            cout<<"dasd";
            curr[currIndex + k] += coef;
            cout<<"dasd";
        }
        currIndex++;
    }
    firstTerm.clear();
    for(int k=0;k<curr.size();k++)
    {
        // cout<<curr[k]<<" ";
        firstTerm.push_back(curr[k]);
    }
    secondTerm.clear();
}
for(int i=0;i<firstTerm.size();i++){
    cout<<firstTerm[i]<<" ";
}
return firstTerm;

}




int main() {
    cout<<"Hello World!";
    vector<int> x{1,2};
    rootsHire2020(x);
}
