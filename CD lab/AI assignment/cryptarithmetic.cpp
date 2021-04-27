#include <bits/stdc++.h>
using namespace std;

bool solve(string s1,string s2,string s3,bool * hash,vector<pair<char,int> > letters,int i){
    if(i == n){
        check(s1,s2,s3,letters);
    }
}

bool crypto(string s1,string s2,string s3){
    bool h[256]={};

    for(int i=0;i<s1.size();i++){
        h[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++){
        h[s2[i]]++;
    }
    for(int i=0;i<s3.size();i++){
        h[s3[i]]++;
    }
    int count = 0;
    for(int i=0;i<256;i++){
        if(h[i]){
            count++;
        }
    }
    
    if(count > 10){
        return false;
    }
    vector<pair<char,int> > letters;
    for(int i=0;i<256;i++){
        if(h[i]){
            char c = i;
            letters.push_back(make_pair(c,-1));
        }
    }
    for(int i=0;i<256;i++){
        h[i] = 0;
    }
    solve(s1,s2,s3,h,letters,0);
}

int main(){
    string s1 = "SEND"; 
    string s2 = "MORE"; 
    string s3 = "MONEY";

    if(!crypto(s1,s2,s3)){
        cout<<"Not valid strings";
    }
    return 0;
}