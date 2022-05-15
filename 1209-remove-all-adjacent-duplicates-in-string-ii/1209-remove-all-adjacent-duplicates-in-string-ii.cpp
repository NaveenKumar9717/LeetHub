class Solution {
public:
    string removeDuplicates(string s, int k) {
       
        stack<pair<char,int>>stk;
        for(int i = 0 ; i  < s.length();i++){
            if(stk.empty() == false){
               if(stk.top().first == s[i]){
                  int freq = stk.top().second+1;
                  if(freq < k){
                      stk.top().second = freq;
                  }
                  else{
                      stk.pop();
                  } 
               }
               else{
                   stk.push({s[i],1});
               }  
            }
            else{
                stk.push({s[i],1});
            }
        }
        
        string final_str = "";
        while(stk.empty() == false){
            int count = stk.top().second;
            for(int i = 0 ; i < count;i++)
                final_str += stk.top().first;
            
            stk.pop();
        }
        reverse(final_str.begin(),final_str.end());
        return final_str;
    }
};