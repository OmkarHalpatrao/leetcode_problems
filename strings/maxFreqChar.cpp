
#include <bits/stdc++.h>

using namespace std;

char freq(string s){
    int freq[26]={};
    
    int cnt=0; //to keep track of max freq
    char ans;   //to keep track of max freq char 
    
    for(auto ch:s){
        int cr = ch - 'a';
        freq[cr]++;
        // cout<<cr<<endl;
        
        if(cnt<freq[cr]){
            cnt = freq[cr];
            ans = ch;
        }
    }
    
    return ans;
}

char maxFreq(string s){
    unordered_map<char,int>mpp;
    
    char ans;
    int max =0;
    
    for(auto  ch:s){
        mpp[ch]++;
        
        if(max<mpp[ch]){
            ans =ch;
            max = mpp[ch];
        }
    }
    
    return ans;
}


int main() {
    
    string str = "raceacar";
    
    cout<<"max freq char:"<<maxFreq(str)<<endl;
    cout<<"max freq char:"<<freq(str);
    

    return 0;
}
