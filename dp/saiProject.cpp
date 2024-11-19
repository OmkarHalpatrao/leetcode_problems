#include<bits/stdc++.h>

using namespace std;

int main(){
  
  int ini_bal;
  cin>>ini_bal;
  
  int N;
  cin>>N;
  
  
  
  vector<string> operations;
  vector<int> amount;
  vector<int> commit_bal;
  vector<int>ans;
  bool commit_flag = false;
  int last_commit =-1;
  
  int cur_bal = ini_bal;
  
  for(int i =0;i<N;i++){
    string ops;
    cin>>ops;
    
    if(ops == "read"){
      
      ans.push_back(cur_bal);
    }
    else if(ops == "credit"){
      int data;
      cin>>data;
      
      cur_bal += data;
      commit_flag =false;
      
      operations.push_back(ops);
      amount.push_back(data);
    }else if(ops == "debit"){
      int data;
      cin>>data;
      
      cur_bal -= data;
      operations.push_back(ops);
      amount.push_back(data);
      commit_flag =false;
      
    }else if(ops == "abort"){
      int x;
      cin>>x;
      if (x-1 <last_commit) {
                
                continue;
       }
      
       if(operations[x-1]=="credit"){
              cur_bal -= amount[x-1];
          }else if(operations[x-1]=="debit"){
              cur_bal += amount[x-1]; 
          }
      
    }else if(ops == "commit"){
    	commit_bal.push_back(cur_bal);
      	commit_flag =true;
      	last_commit = (int)operations.size();
    }else if(ops == "rollback"){
    	int val;
      	cin>>val;
      	
      	cur_bal = commit_bal[val-1];     	
    }else{
    	cout<<"invalid operation"<<endl;
    }
  }
  
  for(auto it:ans){
  	cout<<it<<endl;
  }
  
  return 0;
}