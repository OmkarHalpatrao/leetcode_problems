
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s,string &ans)
{
    unordered_set<char> exists; 
    

    // Traverse through the string
    for (auto c : s) {
      
        // If character is not found in set, 
        // add it to result
        if (exists.find(c) == exists.end()) {
            ans.push_back(c);
            exists.insert(c); 
        }
    }
    
    return ans;
}

int main() {
    
    string word ="";
    string st = "bcddea tsqprt";
    stringstream iss(st);
    while(iss>>word){
        string ans = "";
        removeDuplicates(word,ans);
        sort(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    

    return 0;
}